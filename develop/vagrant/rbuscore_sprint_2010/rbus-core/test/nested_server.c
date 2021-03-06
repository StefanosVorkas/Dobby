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
#include <string.h>
#include "rbus_core.h"
#include "rbus_marshalling.h"
#include "rtLog.h"

static char data[100] = "init init init";
static const char * object_name;
static const char * nested_object_name;
static int handle_get(const char * destination, const char * method, rtMessage message, void * user_data, rtMessage *response, const rtMessageHeader* hdr)
{
    (void) user_data;
    (void) message;
    (void) hdr;
    printf("Handling %s call for %s\n", method, destination);
    rtMessage_Create(response);
    rbus_SetInt32(*response, MESSAGE_FIELD_RESULT, RTMESSAGE_BUS_SUCCESS);
    rbus_SetString(*response, MESSAGE_FIELD_PAYLOAD, data);

    if(0 == strncmp(object_name, destination, strlen(object_name)))
    {
        /* Make the nested call */
        rtMessage nestedResponse;
        if(RTMESSAGE_BUS_SUCCESS != rbus_invokeRemoteMethod(nested_object_name, METHOD_GETPARAMETERVALUES,
                    NULL, 1000, &nestedResponse))
        {
            printf("Nested call failed.\n");
        }
        else
        {
            printf("Nested call returned.\n");
            rtMessage_Release(nestedResponse);
        }
    }
    printf("Exiting %s call for %s\n", method, destination);
    return 0;
}


static void handle_unknown(const char * destination, const char * method, rtMessage message, rtMessage *response, const rtMessageHeader* hdr)
{
    (void) message;
    (void) destination;
    (void) method;
    (void) hdr;
    rtMessage_Create(response);
    rbus_SetInt32(*response, MESSAGE_FIELD_RESULT, RTMESSAGE_BUS_ERROR_UNSUPPORTED_METHOD);
}

static int callback(const char * destination, const char * method, rtMessage message, void * user_data, rtMessage *response, const rtMessageHeader* hdr)
{
    (void) user_data;
    (void) destination;
    (void) method;
    (void) hdr;
    printf("Received message in base callback.\n");
    char* buff = NULL;
    uint32_t buff_length = 0;

    rtMessage_ToString(message, &buff, &buff_length);
    printf("%s\n", buff);
    free(buff);

    /* Craft response message.*/
    handle_unknown(destination, method, message, response, hdr);
    return 0;
}

int main(int argc, char *argv[])
{
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;
    printf("syntax: rbus_nested_test_server <top level object> <nested object>\n");
    if(3 > argc)
        return 1;
    object_name = argv[1];
    nested_object_name = argv[2];

    rtLog_SetLevel(RT_LOG_INFO);

    if((err = rbus_openBrokerConnection(argv[1])) == RTMESSAGE_BUS_SUCCESS)
    {
        printf("Successfully connected to bus.\n");
    }

    if((err = rbus_registerObj(object_name, callback, NULL)) == RTMESSAGE_BUS_SUCCESS)
    {
        printf("Successfully registered object.\n");
    }

    if((err = rbus_registerObj(nested_object_name, callback, NULL)) == RTMESSAGE_BUS_SUCCESS)
    {
        printf("Successfully registered object.\n");
    }
    rbus_method_table_entry_t table[1] = {{METHOD_GETPARAMETERVALUES, NULL, handle_get}};
    rbus_registerMethodTable(object_name, table, 1); 
    rbus_registerMethodTable(nested_object_name, table, 1); 
    pause();

    if((err = rbus_closeBrokerConnection()) == RTMESSAGE_BUS_SUCCESS)
    {
        printf("Successfully disconnected from bus.\n");
    }
    return 0;
}
