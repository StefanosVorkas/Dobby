/*
 * If not stated otherwise in this file or this component's Licenses.txt file
 * the following copyright and licenses apply:
 *
 * Copyright 2019 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/*
    Value-Change Detection:
    Simple API that allows you to add/remove parameters you wish to check value-change for.
    Uses a single thread to poll parameter values across all rbus handles.
    The thread is started on first param added and stopped on last param removed.
    A poling period (default 30 seconds) helps to limit the cpu usage.
    Runs in the provider process, so the value are got with direct callbacks and not over the network.
    The technique is simple:
    1) when a param is added, get and cache its current value.
    2) on a background thread, periodically get the latest value and compare to cached value.
    3) if the value has change, publish an event.
*/

#define _GNU_SOURCE 1 //needed for pthread_mutexattr_settype

#include "rbus_valuechange.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <pthread.h>
#include <unistd.h>
#include <rtVector.h>
#include <assert.h>

#define VC_LOCK() {int rc = pthread_mutex_lock(&vcmutex); (void)rc;}
#define VC_UNLOCK() {pthread_mutex_unlock(&vcmutex);}

static int              vcinit      = 0;
static int              vcrunning   = 0;
static int              vcperiod    = 30;//seconds
static rtVector         vcparams    = NULL;
static pthread_mutex_t  vcmutex;
static pthread_t        vcthread;

typedef struct ValueChangeRecord
{
    rbusHandle_t handle;    //needed when calling rbus_getHandler and rbusEvent_Publish
    elementNode const* node;    //used to call the rbus_getHandler is contains
    rbusProperty_t property;    //the parameter with value that gets cached
} ValueChangeRecord;

static void rbusValueChange_Init()
{
    rtLog_Debug("%s", __FUNCTION__);

    if(vcinit)
        return;

    vcinit = 1;

    rtVector_Create(&vcparams);

    pthread_mutexattr_t attrib;
    pthread_mutexattr_init(&attrib);
    pthread_mutexattr_settype(&attrib, PTHREAD_MUTEX_ERRORCHECK);
    if(0 != pthread_mutex_init(&vcmutex, &attrib))
    {
        rtLog_Warn("%s: failed to initialize mutex", __FUNCTION__);
    }
}

static void vcParams_Free(void* p)
{
    ValueChangeRecord* rec = (ValueChangeRecord*)p;
    rbusProperty_Release(rec->property);
    free(rec);
}

static ValueChangeRecord* vcParams_Find(const elementNode* paramNode)
{
    size_t i;
    for(i=0; i < rtVector_Size(vcparams); ++i)
    {
        ValueChangeRecord* rec = (ValueChangeRecord*)rtVector_At(vcparams, i);
        if(rec && rec->node == paramNode)
            return rec;
    }
    return NULL;
}

static void* rbusValueChange_pollingThreadFunc(void *userData)
{
    (void)(userData);
    rtLog_Debug("%s: start", __FUNCTION__);
    while(vcrunning)
    {
        size_t i;
        
        sleep(vcperiod);
        
        if(!vcrunning)
            break;

        VC_LOCK();//############ LOCK ############
        //TODO: VC_LOCK around the whole for loop might not be efficient
        //      What if rbusEvent_Publish takes too long.  
        //      This could block the _callback_handler, which calls rbusValueChange_AddParameter, for too long

        for(i=0; i < rtVector_Size(vcparams); ++i)
        {
            rbusProperty_t property;
            rbusValue_t newVal, oldVal;

            ValueChangeRecord* rec = (ValueChangeRecord*)rtVector_At(vcparams, i);
            if(!rec)
                continue;

            rbusProperty_Init(&property,rbusProperty_GetName(rec->property), NULL);

            rbusGetHandlerOptions_t opts;
            memset(&opts, 0, sizeof(rbusGetHandlerOptions_t));
            opts.requestingComponent = "valueChangePollThread";

            int result = rec->node->cbTable.getHandler(rec->handle, property, &opts);

            if(result != RBUS_ERROR_SUCCESS)
            {
                rtLog_Warn("%s: failed to get current value of %s", __FUNCTION__, rbusProperty_GetName(property));
                continue;
            }

            char* sValue = rbusValue_ToString(rbusProperty_GetValue(property), NULL, 0);
            rtLog_Debug("%s: %s=%s", __FUNCTION__, rbusProperty_GetName(property), sValue);
            free(sValue);

            newVal = rbusProperty_GetValue(property);
            oldVal = rbusProperty_GetValue(rec->property);

            if(rbusValue_Compare(newVal, oldVal))
            {
                rbusSubscription_t* subscription;
                rtListItem li;

                rtLog_Info("%s: value change detected for %s", __FUNCTION__, rbusProperty_GetName(rec->property));

                /*
                    mrollins: I added a 'filter=true|false' property to the event data when a filter it triggered.
                    This would let the consumer know if their filter got triggered by the property's value crossing
                    into the threshold (filter=true) or out of the threshold (filter=false). 
                    Although useful, it creates complication if multiple consumers subscribe with different filters.
                    When we publish below with rbusEvent_Publish, all subscribers to the property will get an event.  
                    But we add this 'filter' property to the event data if a filter was triggered and this would confuse any
                    additional subscriber on this property which had a filter that wasn't triggered or triggered in the opposite way.

                    Example fail case: consumer A has filter 1 (val > 0), and consumer B has filter 2 (val < 0).  
                    Now assume filter 1 gets crossed into (val goes from 0 to 1).
                    We publish the event with a 'filter=true' (meaning it crossed into). 
                    Consumer A gets the correct event.  Consumer B gets the same event with 'filter=true' and believes
                    that the val went below 0 -- which is wrong. 

                    Note that this could be fixed by publishing to specific subscribers from here; however, if autoPublish is
                    false, we don't have anything in the API to allow a provider to know about subscribers and to publish to 
                    specific providers.
                */
                rtList_GetFront(rec->node->subscriptions, &li);
                while(li)
                {
                    bool publish = true;
                    rbusValue_t filterResult = NULL;

                    rtListItem_GetData(li, (void**)&subscription);

                    /* if the subscriber has a filter we check the filter to determine if we publish.
                       if the subscriber does not have a filter, we publish always*/
                    if(subscription->filter)
                    {
                        /*We publish an event only when the value crosses the filter threshold boundary.
                          When the value crosses into the threshold we publish a single event signally the filter started matching.
                          When the value crosses out of the threshold we publish a single event signally the filter stopped matching.
                          We do not publish continuous events while the filter continues to match. The consumer can read the 'filter'
                          property from the event data to determine if the filter has started or stopped matching.  If the consumer
                          wants to get continuous value-change events, they can unsubscribe the filter and resubscribe without a filter*/

                        int newResult = rbusFilter_Apply(subscription->filter, newVal);
                        int oldResult = rbusFilter_Apply(subscription->filter, oldVal);

                        if(newResult != oldResult)
                        {
                            rtLog_Info("%s: filter matched for %s", __FUNCTION__, rbusProperty_GetName(rec->property));
                            /*set 'filter' to true/false implying that either the filter has started or stopped matching*/
                            rbusValue_Init(&filterResult);
                            rbusValue_SetBoolean(filterResult, newResult != 0);
                        }
                        else
                        {
                            publish =  false;
                        }
                    }
                    rtListItem_GetNext(li, &li);

                    if(publish)
                    {
                        rbusEvent_t event = {0};
                        rbusObject_t data;

                        rbusObject_Init(&data, NULL);
                        rbusObject_SetValue(data, "value", newVal);
                        rbusObject_SetValue(data, "oldValue", oldVal);
                        if(filterResult)
                        {
                            rbusObject_SetValue(data, "filter", filterResult);
                            rbusValue_Release(filterResult);
                        }

                        rtLog_Info ("%s: value change detected for %s", __FUNCTION__, rbusProperty_GetName(rec->property));

                        event.name = rbusProperty_GetName(rec->property);
                        event.data = data;
                        event.type = RBUS_EVENT_VALUE_CHANGED;

                        result = rbusEvent_Publish(rec->handle, &event);

                        rbusObject_Release(data);

                        if(result != RBUS_ERROR_SUCCESS)
                        {
                            rtLog_Warn("%s: rbusEvent_Publish failed with result=%d", __FUNCTION__, result);
                        }

                        /*
                            Break out of the node's subscriptions loop so that we only publish 1 event for this property.
                                
                            We only publish 1 time, even though there could be multiple subscribers whose filters get triggered.
                            If there are multiple providers with different filters then it can be a problem because only the first 
                            consumer who's filter triggered will have the corrent 'filter' property in the event data.  The other 
                            subscribers with different filters will get confused.   Right now we are just assuming only one subscriber
                            per property, so we may have to come back and fix the code to handle multiple subscribers correctly at some point.
                        */
                        break;
                    }
                }
            
                /*update the record's property with new value*/
                rbusProperty_SetValue(rec->property, rbusProperty_GetValue(property));
                rbusProperty_Release(property);
            }
            else
            {
                rtLog_Info("%s: value change not detected for %s", __FUNCTION__, rbusProperty_GetName(rec->property));
                rbusProperty_Release(property);
            }
        }

        VC_UNLOCK();//############ UNLOCK ############
    }
    rtLog_Debug("%s: stop", __FUNCTION__);
    return NULL;
}

void rbusValueChange_SetPollingPeriod(int seconds)
{
    rtLog_Debug("%s: %d", __FUNCTION__, seconds);
    vcperiod = seconds;
}

void rbusValueChange_AddPropertyNode(rbusHandle_t handle, elementNode* propNode)
{
    ValueChangeRecord* rec;

    rtLog_Debug("%s: %s", __FUNCTION__, propNode->fullName);

    if(!vcinit)
    {
        rbusValueChange_Init();
    }

    /* basic sanity tests */    
    assert(propNode);
    if(!propNode)
    {
        rtLog_Warn("%s: propNode NULL error", __FUNCTION__);
        return;
    }
    assert(propNode->type == RBUS_ELEMENT_TYPE_PROPERTY);
    if(propNode->type != RBUS_ELEMENT_TYPE_PROPERTY)
    {
        rtLog_Warn("%s: propNode type %d error", __FUNCTION__, propNode->type);
        return;
    }
    assert(propNode->cbTable.getHandler);
    if(!propNode->cbTable.getHandler)
    {
        rtLog_Warn("%s: propNode getHandler NULL error", __FUNCTION__);
        return;
    }

    /* only add the property if its not already in the list */

    VC_LOCK();//############ LOCK ############

    rec = vcParams_Find(propNode);

    VC_UNLOCK();//############ UNLOCK ############

    if(!rec)
    {
        rec = (ValueChangeRecord*)malloc(sizeof(ValueChangeRecord));
        rec->handle = handle;
        rec->node = propNode;

        rbusProperty_Init(&rec->property, propNode->fullName, NULL);

        rbusGetHandlerOptions_t opts;
        memset(&opts, 0, sizeof(rbusGetHandlerOptions_t));
        opts.requestingComponent = "valueChangePollThread";
        /*get and cache the current value
          the polling thread will periodically re-get and compare to detect value changes*/
        int result = propNode->cbTable.getHandler(handle, rec->property, &opts);

        if(result != RBUS_ERROR_SUCCESS)
        {
            rtLog_Warn("%s: failed to get current value for %s", __FUNCTION__, propNode->fullName);
            vcParams_Free(rec);
            rec = NULL;
        }

        char* sValue;
        rtLog_Debug("%s: %s=%s", __FUNCTION__, propNode->fullName, (sValue = rbusValue_ToString(rbusProperty_GetValue(rec->property), NULL, 0)));
        free(sValue);

        VC_LOCK();//############ LOCK ############

        rtVector_PushBack(vcparams, rec);

        /* start polling thread if needed */

        if(!vcrunning)
        {
            vcrunning = 1;
            pthread_create(&vcthread, NULL, rbusValueChange_pollingThreadFunc, NULL);
        }

        VC_UNLOCK();//############ UNLOCK ############
    }
}

void rbusValueChange_RemovePropertyNode(rbusHandle_t handle, elementNode* propNode)
{
    ValueChangeRecord* rec;

    (void)(handle);

    rtLog_Debug("%s: %s", __FUNCTION__, propNode->fullName);

    if(!vcinit)
    {
        return;
    }

    VC_LOCK();//############ LOCK ############

    rec = vcParams_Find(propNode);

    VC_UNLOCK();//############ UNLOCK ############

    if(rec)
    {
        bool stopThread;

        VC_LOCK();//############ LOCK ############

        rtVector_RemoveItem(vcparams, rec, vcParams_Free);

        /* if there's nothing left to poll then shutdown the polling thread */

        if(vcrunning && rtVector_Size(vcparams) == 0)
        {
            stopThread = true;
            vcrunning = 0;
        }
        else 
        {
            stopThread = false;
        }

        VC_UNLOCK();//############ UNLOCK ############

        if(stopThread)
        {
            pthread_join(vcthread, NULL);
        }
    }
    else
    {
        rtLog_Warn("%s: value change param not found: %s", __FUNCTION__, propNode->fullName);
    }
}

void rbusValueChange_Close(rbusHandle_t handle)
{
    rtLog_Debug("%s", __FUNCTION__);

    if(!vcinit)
    {
        return;
    }

    //remove all params for this bus handle
    size_t i = 0;
    while(i < rtVector_Size(vcparams))
    {
        ValueChangeRecord* rec = (ValueChangeRecord*)rtVector_At(vcparams, i);
        if(rec && rec->handle == handle)
        {
            rtVector_RemoveItem(vcparams, rec, vcParams_Free);
        }
        else
        {
            //only i++ here because rtVector_RemoveItem does a right shift on all the elements after remove index
            i++; 
        }
    }

    //clean up everything once all params are removed
    //but check the size to ensure we do not clean up if params for other rbus handles exist
    if(rtVector_Size(vcparams) == 0)
    {
        if(vcrunning)
        {
            vcrunning = 0;
            pthread_join(vcthread, NULL);
        }
        pthread_mutex_destroy(&vcmutex);
        rtVector_Destroy(vcparams, NULL);
        vcparams = NULL;
        vcinit = 0;
    }
}

