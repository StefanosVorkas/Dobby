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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rbus_core.h"
#include "rbus_marshalling.h"
#include "rbus_session_mgr.h"
#include "rtLog.h"


static int g_current_session_id = 0; 

void create_session()
{
    rtMessage response;
    if(RTMESSAGE_BUS_SUCCESS == rbus_invokeRemoteMethod(RBUS_SMGR_DESTINATION_NAME, RBUS_SMGR_METHOD_REQUEST_SESSION_ID, NULL, 1000, &response))
    {
        int result;
        if(RT_OK == rbus_GetInt32(response, MESSAGE_FIELD_RESULT, &result))
        {
            if(RTMESSAGE_BUS_SUCCESS != result)
            {
                printf("Session manager reports internal error %d.\n", result);
                return;
            }
        }
        if(RT_OK == rbus_GetInt32(response, MESSAGE_FIELD_PAYLOAD, &g_current_session_id))
        {
            printf("Got new session id %d\n", g_current_session_id);
        }
        else
            printf("Malformed response from session manager.\n");
    }
    else
        printf("RPC with session manager failed.\n");
}

void print_current_session_id()
{
    rtMessage response;
    if(RTMESSAGE_BUS_SUCCESS == rbus_invokeRemoteMethod(RBUS_SMGR_DESTINATION_NAME, RBUS_SMGR_METHOD_GET_CURRENT_SESSION_ID, NULL, 1000, &response))
    {
        int result;
        if(RT_OK == rbus_GetInt32(response, MESSAGE_FIELD_RESULT, &result))
        {
            if(RTMESSAGE_BUS_SUCCESS != result)
            {
                printf("Session manager reports internal error %d.\n", result);
                return;
            }
        }
        if(RT_OK == rbus_GetInt32(response, MESSAGE_FIELD_PAYLOAD, &g_current_session_id))
        {
            printf("Current session id %d\n", g_current_session_id);
        }
        else
            printf("Malformed response from session manager.\n");
    }
    else
        printf("RPC with session manager failed.\n");
}

void end_session(int session)
{
    rtMessage out;
    rtMessage response;

    rtMessage_Create(&out);
    rbus_SetInt32(out, MESSAGE_FIELD_PAYLOAD, session);
    if(RTMESSAGE_BUS_SUCCESS == rbus_invokeRemoteMethod(RBUS_SMGR_DESTINATION_NAME, RBUS_SMGR_METHOD_END_SESSION, out, 1000, &response))
    {
        int result;
        if(RT_OK == rbus_GetInt32(response, MESSAGE_FIELD_RESULT, &result))
        {
            if(RTMESSAGE_BUS_SUCCESS != result)
            {
                printf("Session manager reports internal error %d.\n", result);
                return;
            }
            else
                printf("Successfully ended session %d.\n", session);
        }
    }
    else
        printf("RPC with session manager failed.\n");
}

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;
    rtLog_SetLevel(RT_LOG_INFO);

    if((err = rbus_openBrokerConnection("rbus_smgr_client")) == RTMESSAGE_BUS_SUCCESS)
    {
        printf("Successfully connected to bus.\n");
    }
    
    create_session();
    print_current_session_id();
    create_session();//Negative test case.
    end_session(g_current_session_id + 1); //Negative test case.
    end_session(g_current_session_id);
    create_session();
    print_current_session_id();
    end_session(g_current_session_id);
    

    if((err = rbus_closeBrokerConnection()) == RTMESSAGE_BUS_SUCCESS)
    {
        printf("Successfully disconnected from bus.\n");
    }
    return 0;
}
