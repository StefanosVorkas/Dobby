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
/******************************************************
Test Case : Testing rbus communications from client end
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <vector>
extern "C" {
#include "rbus_core.h"
#include "rbus_marshalling.h"
}
#include "gtest_app.h"
#include "rbus_test_util.h"

#define DEFAULT_RESULT_BUFFERSIZE 128
#define MAX_SERVER_NAME 40


static bool OPEN_BROKER_CONNECTION2(char* connection_name)
{
    bool result = false;
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;

    if((err = rbus_openBrokerConnection(connection_name)) == RTMESSAGE_BUS_SUCCESS)
    {
         //printf("Successfully connected to bus.\n");
         result = true;
    }
    EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_openBrokerConnection failed";
    return result;
}

static bool CLOSE_BROKER_CONNECTION2()
{
    bool result = false;
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;
    if((err = rbus_closeBrokerConnection()) == RTMESSAGE_BUS_SUCCESS)
    {
        //printf("Successfully disconnected from bus.\n");
        result = true;
    }
    EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_closeBrokerConnection failed";
    return result;
}

static void handle_term2(int sig)
{
    (void) sig;
    CLOSE_BROKER_CONNECTION2();
    printf("**********EXITING SERVER ******************** \n");
    kill(getpid(), SIGKILL);
}
static void CREATE_RBUS_SERVER_INSTANCE2(int handle, int obj_count)
{
    char server_name[MAX_SERVER_NAME] = "test_server_";
    char obj_name[20] = "student_info";
    int i = 1;
    char buffer[DEFAULT_RESULT_BUFFERSIZE];
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;
    bool conn_status = false;
    static char test_buffer[100][100] = {};

    memset( buffer, 0, DEFAULT_RESULT_BUFFERSIZE );
    memset( test_buffer, 0, sizeof(test_buffer));
    snprintf((server_name + strlen(server_name)), (MAX_SERVER_NAME - strlen(server_name)), "%d", handle);

    printf("*** CREATING SERVER : %s \n", server_name);

    signal(SIGTERM, handle_term2);
    reset_stored_data();

    conn_status = OPEN_BROKER_CONNECTION2(server_name);

    ASSERT_EQ(conn_status, true) << "OPEN_BROKER_CONNECTION2 failed";

    for(i = 1; i < obj_count; i++)
    {
        snprintf(buffer, (sizeof(buffer) - 1), "%s_%s.obj%d", server_name, obj_name, i);
        printf("Registering object %s\n", buffer);
        strncpy(*(test_buffer + i), buffer, 100);

        err = rbus_registerObj(buffer, callback, NULL);
        EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_registerObj failed";

        rbus_method_table_entry_t table[2] = {{METHOD_SETPARAMETERVALUES, (void *)(test_buffer + i), handle_setStudentInfo}, {METHOD_GETPARAMETERVALUES, (void *)(test_buffer + i), handle_getStudentInfo}};

        err = rbus_registerMethodTable(buffer, table, 2);
        EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_registerMethodTable failed";
    }
    return;
}

static void CREATE_RBUS_SERVER_INSTANCE3(const char * app_prefix, int num)
{
    std::string server_name("");
    server_name += app_prefix + std::to_string(num);
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;

    printf("*** CREATING SERVER : %s \n", server_name.c_str());

    signal(SIGTERM, handle_term2);
    reset_stored_data();

    err = rbus_openBrokerConnection(server_name.c_str());
    EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_openBrokerConnection2() failed";
    
    std::string obj_name = std::string(app_prefix) + std::to_string(num) + ".obj";
    err = rbus_registerObj(obj_name.c_str(), callback, NULL);
    EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_registerObj failed";
    err = rbus_addElement(obj_name.c_str(), std::string(app_prefix + std::to_string(num) + std::string(".element")).c_str());
    EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_addElement failed";
    rbus_addElement(obj_name.c_str(), std::string("common.element." + std::to_string(num)).c_str());
    return;
}


static void RBUS_PULL_OBJECT2(char* expected_data, char* server_obj, rbus_error_t expected_err)
{
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;
    rtMessage response;
    if((err = rbus_pullObj(server_obj, 1000, &response)) == RTMESSAGE_BUS_SUCCESS)
    {
        const char* buff = NULL;
        rbus_GetString(response, MESSAGE_FIELD_PAYLOAD, &buff);
        printf("%s: rbus pull returned : %s \n", __FUNCTION__, buff);
        EXPECT_STREQ(buff, expected_data) << "rbus_pullObj failed to procure expected string";
        rtMessage_Release(response);
    }
    else
    {
        printf("Could not pull object %s\n", server_obj);
    }
    EXPECT_EQ(err, expected_err) << "rbus_pullObj failed";
    return;
}

static void RBUS_PUSH_OBJECT2(char* data, char* server_obj, rbus_error_t expected_err)
{
    rbus_error_t err = RTMESSAGE_BUS_SUCCESS;
    rtMessage setter;
    rtMessage_Create(&setter);
    rbus_SetString(setter, MESSAGE_FIELD_PAYLOAD, data);
    err = rbus_pushObj(server_obj, setter, 1000);
    EXPECT_EQ(err, expected_err) << "rbus_pushObj failed";
    return;
}

class MultipleServerTest : public ::testing::Test{

protected:

static void SetUpTestCase()
{
    printf("********************************************************************************************\n");
    reset_stored_data();
    printf("Set up done Successfully for MultipleServerTest\n");
}

static void TearDownTestCase()
{
    printf("********************************************************************************************\n");
    printf("Clean up done Successfully for MultipleServerTest\n");
}

};

TEST_F(MultipleServerTest, sample_test)
{
    EXPECT_EQ(1, 1);
}

TEST_F(MultipleServerTest, rbus_multipleServer_test1)
{
    int counter = 1, i = 1, j = 1;
    char client_name[] = "TEST_CLIENT_1";
    bool conn_status = false;
    char name_buf[100];
    char data_buf[100];
    int server_count = 3;
    int object_count = 3;
    int reg_object_count = 0;
    pid_t pid[10];
    bool is_parent = true;
    const char *pFound = NULL;

    for(j = 0; j < server_count; j++)
    {
        pid[j] = fork();

        if(pid[j] == 0)
        {
            counter = j + 1;
            CREATE_RBUS_SERVER_INSTANCE2(counter, (object_count + 1));
            is_parent = false;
            printf("********** SERVER ENTERING PAUSED STATE******************** \n");
            pause();
        }
    }
    if(is_parent)
    {
        sleep(2);
        conn_status = OPEN_BROKER_CONNECTION2(client_name);
        rtMessage components;
        rbus_error_t err = rbus_registeredComponents(&components);
        EXPECT_EQ(err, RTMESSAGE_BUS_SUCCESS) << "rbus_registeredComponents failed";
        int num_objects = 0;
        std::vector <std::string> object_list;
        if(RTMESSAGE_BUS_SUCCESS == err)
        {
            rbus_GetInt32(components, REGISTERED_COMPONENTS_SIZE, &num_objects);
            for(int i = 0; i < num_objects; i++)
            {
                const char * ptr;
                rbus_GetString(components, REGISTERED_COMPONENTS_ENTRIES, &ptr);
                pFound=strstr(ptr,"test_server_");
                if(pFound) {
                    if(strstr(pFound,"_student_info.obj"))
                        reg_object_count++;
                }
                object_list.emplace_back(std::string(ptr));
            }
            rtMessage_Release(components);
            EXPECT_EQ(reg_object_count, (server_count * object_count)) << "rbus_registeredComponent returned wrong size";
        }
        
        for(j = 1; j <= server_count; j++)
        {
            counter = j;
            for(i = 1;i <= object_count; i++)
            {
                snprintf(name_buf, (sizeof(name_buf) - 1), "test_server_%d_student_info.obj%d", counter, i);
                printf("Registering object %s\n", name_buf);
                snprintf(data_buf, (sizeof(data_buf) - 1), "student_%d_of_server-%d", i, counter);

                RBUS_PUSH_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
                RBUS_PULL_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);

                int listed_in_discovery = 0;
                for(unsigned int k = 0; k < object_list.size(); k++)
                {
                    if(object_list[k] == name_buf)
                    {
                        listed_in_discovery = 1;
                        break;
                    }
                }
                EXPECT_EQ(listed_in_discovery, 1) << "Could not locate object in rbus_registeredComponents() result.";
            }
        }
        if(conn_status)
            CLOSE_BROKER_CONNECTION2();

        for(i = 0; i < server_count; i++)
            kill(pid[i],SIGTERM);
    }
}

TEST_F(MultipleServerTest, rbus_multipleServer_test2)
{
    int counter = 1, i = 1, j = 1;
    char client_name[] = "TEST_CLIENT_1";
    bool conn_status = false;
    char name_buf[100];
    char data_buf[100];
    int server_count = 3;
    int object_count = 10;
    pid_t pid[10];
    bool is_parent = true;

    for(j = 0; j < server_count; j++)
    {
        pid[j] = fork();

        if(pid[j] == 0)
        {
            counter = j + 1;
            CREATE_RBUS_SERVER_INSTANCE2(counter, (object_count + 1));
            is_parent = false;
            printf("********** SERVER ENTERING PAUSED STATE******************** \n");
            pause();
        }
    }
    if(is_parent)
    {
        sleep(2);
        conn_status = OPEN_BROKER_CONNECTION2(client_name);
        for(j = 1; j <= server_count; j++)
        {
            counter = j;
            for(i = 1;i <= object_count; i++)
            {
                snprintf(name_buf, (sizeof(name_buf) - 1), "test_server_%d_student_info.obj%d", counter, i);
                printf("Registering object %s\n", name_buf);
                snprintf(data_buf, (sizeof(data_buf) - 1), "student_%d_of_server-%d", i, counter);

                RBUS_PUSH_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
                RBUS_PULL_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
            }
        }
        if(conn_status)
            CLOSE_BROKER_CONNECTION2();

        for(i = 0; i < server_count; i++)
            kill(pid[i],SIGTERM);
    }
}

TEST_F(MultipleServerTest, rbus_multipleServer_test3)
{
    int counter = 1, i = 1, j = 1;
    char client_name[] = "TEST_CLIENT_1";
    bool conn_status = false;
    char name_buf[100];
    char data_buf[100];
    int server_count = 10;
    int object_count = 3;
    pid_t pid[10];
    bool is_parent = true;

    for(j = 0; j < server_count; j++)
    {
        pid[j] = fork();

        if(pid[j] == 0)
        {
            counter = j + 1;
            CREATE_RBUS_SERVER_INSTANCE2(counter, (object_count + 1));
            is_parent = false;
            printf("********** SERVER ENTERING PAUSED STATE******************** \n");
            pause();
        }
    }
    if(is_parent)
    {
        sleep(4);

        conn_status = OPEN_BROKER_CONNECTION2(client_name);
        for(j = 1; j <= server_count; j++)
        {
            counter = j;
            for(i = 1;i <= object_count; i++)
            {
                snprintf(name_buf, (sizeof(name_buf) - 1), "test_server_%d_student_info.obj%d", counter, i);
                printf("Registering object %s\n", name_buf);
                snprintf(data_buf, (sizeof(data_buf) - 1), "student_%d_of_server-%d", i, counter);

                RBUS_PUSH_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
                RBUS_PULL_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
            }
        }
        if(conn_status)
            CLOSE_BROKER_CONNECTION2();

        for(i = 0; i < server_count; i++)
            kill(pid[i],SIGTERM);
    }
}

TEST_F(MultipleServerTest, rbus_multipleServer_test4)
{
    int counter = 1, i = 1, j = 1;
    char client_name[] = "TEST_CLIENT_1";
    bool conn_status = false;
    char name_buf[100];
    char data_buf[100];
    int server_count = 20;
    int object_count = 3;
    pid_t pid[server_count];
    bool is_parent = true;

    for(j = 0; j < server_count; j++)
    {
        pid[j] = fork();

        if(pid[j] == 0)
        {
            counter = j + 1;
            CREATE_RBUS_SERVER_INSTANCE2(counter, (object_count + 1));
            is_parent = false;
            printf("********** SERVER ENTERING PAUSED STATE******************** \n");
            pause();
        }
    }
    if(is_parent)
    {
        sleep(5);

        conn_status = OPEN_BROKER_CONNECTION2(client_name);
        for(j = 1; j <= server_count; j++)
        {
            counter = j;
            for(i = 1;i <= object_count; i++)
            {
                snprintf(name_buf, (sizeof(name_buf) - 1), "test_server_%d_student_info.obj%d", counter, i);
                printf("Registering object %s\n", name_buf);
                snprintf(data_buf, (sizeof(data_buf) - 1), "student_%d_of_server-%d", i, counter);

                RBUS_PUSH_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
                RBUS_PULL_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
            }
        }
        if(conn_status)
            CLOSE_BROKER_CONNECTION2();

        for(i = 0; i < server_count; i++)
        {
            kill(pid[i],SIGTERM);
        }
    }
}
TEST_F(MultipleServerTest, rbus_multipleServer_test5)
{
    int counter = 1, i = 1, j = 1;
    char client_name[] = "TEST_CLIENT_1";
    bool conn_status = false;
    char name_buf[100];
    char data_buf[100];
    int server_count = 20;
    int object_count = 3;
    pid_t pid[server_count];
    bool is_parent = true;

    for(j = 0; j < server_count; j++)
    {
        pid[j] = fork();

        if(pid[j] == 0)
        {
            counter = j + 1;
            CREATE_RBUS_SERVER_INSTANCE2(counter, (object_count + 1));
            is_parent = false;
            printf("********** SERVER ENTERING PAUSED STATE******************** \n");
            pause();
        }
    }
    if(is_parent)
    {
        sleep(10);

        conn_status = OPEN_BROKER_CONNECTION2(client_name);
        for(j = 1; j <= server_count; j++)
        {
            counter = j;
            for(i = 1;i <= object_count; i++)
            {
                snprintf(name_buf, (sizeof(name_buf) - 1), "test_server_%d_student_info.obj%d", counter, i);
                printf("Registering object %s\n", name_buf);
                snprintf(data_buf, (sizeof(data_buf) - 1), "student_%d_of_server-%d", i, counter);

                RBUS_PUSH_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
                RBUS_PULL_OBJECT2(data_buf, name_buf, RTMESSAGE_BUS_SUCCESS);
            }
        }
        if(conn_status)
            CLOSE_BROKER_CONNECTION2();

        for(i = 0; i < server_count; i++)
        {
            kill(pid[i],SIGTERM);
        }
    }
}


TEST_F(MultipleServerTest, rbus_multipleServer_test6)
{
    int j = 0;
    int server_count = 2;
    pid_t pid[server_count];
    bool is_parent = true;

    for (j = 0; j < server_count; j++)
    {
        pid[j] = fork();

        if (pid[j] == 0)
        {
            is_parent = false;
            CREATE_RBUS_SERVER_INSTANCE3("lookup_test", j);
            pause();
        }
    }
    if (is_parent)
    {
        rbus_error_t err;
	rbus_openBrokerConnection("lookup_client");
        const char *inputs[] = {"lookup_test0.obj", "lookup_test0.element", "lookup_test1.obj", "lookup_test1.element1", "lookup_test0.", "lookup_test1.", "abcd", "common.", "common.element.0", "common.element.1"};
        constexpr int in_length = sizeof(inputs) / sizeof(char *);
        const char *expected_output[] = {"lookup_test0.obj", "lookup_test0.obj", "lookup_test1.obj", "lookup_test1.obj", "lookup_test0.obj", "lookup_test1.obj", "", "", "lookup_test0.obj", "lookup_test1.obj"};
        char **output = nullptr;
        sleep(3);//Allow servers to set up.
        err = rbus_findMatchingObjects(inputs, in_length, &output);
        EXPECT_EQ(RTMESSAGE_BUS_SUCCESS, err) << "rbus_findMatchingObjects failed.";
        if(RTMESSAGE_BUS_SUCCESS == err)
        {
            printf("Multi-lookup returned success. Printing mapping information...\n");
            for (int i = 0; i < in_length; i++)
            {
                //printf("%s mapped to %s\n", inputs[i], output[i]);
                EXPECT_EQ(0, strcmp(expected_output[i], output[i])) << "rbus_findMatchingObjects returned wrong data";
                free(output[i]);
            }
            free(output);
        }
        rbus_closeBrokerConnection();

        for(int i = 0; i < server_count; i++)
            kill(pid[i], SIGTERM);
    }
}
