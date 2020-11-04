/*
 * If not stated otherwise in this file or this component's Licenses.txt file
 * the following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
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
#include "gtest/gtest.h"
#include <rbus.h>

TEST(rbusValueTest, validate_types)
{
  rbusValue_t val;
  rbusValue_Init(&val);

  rbusValue_SetBoolean(val, true);
  EXPECT_EQ(rbusValue_GetType(val), RBUS_BOOLEAN);

  rbusValue_Release(val);
}

TEST(rbusValueTest, validate_bool)
{
  rbusValue_t val;
  rbusValue_Init(&val);

  rbusValue_SetBoolean(val, true);
  EXPECT_EQ(rbusValue_GetType(val), RBUS_BOOLEAN);
  EXPECT_EQ(rbusValue_GetBoolean(val), true);

  rbusValue_SetBoolean(val, false);
  EXPECT_EQ(rbusValue_GetType(val), RBUS_BOOLEAN);
  EXPECT_EQ(rbusValue_GetBoolean(val), false);

  rbusValue_SetInt32(val, 10);
  rbusValue_SetBoolean(val, true);
  EXPECT_EQ(rbusValue_GetType(val), RBUS_BOOLEAN);
  EXPECT_EQ(rbusValue_GetBoolean(val), true);

  rbusValue_SetString(val, "hello world");
  rbusValue_SetBoolean(val, true);
  EXPECT_EQ(rbusValue_GetType(val), RBUS_BOOLEAN);
  EXPECT_EQ(rbusValue_GetBoolean(val), true);

  rbusValue_Release(val);
}

TEST(rbusValueTest, validate_char)
{
  rbusValue_t val;
  rbusValue_Init(&val);

  rbusValue_SetChar(val, 'a');
  EXPECT_EQ(rbusValue_GetType(val), RBUS_CHAR);
  EXPECT_EQ(rbusValue_GetChar(val), 'a');

  rbusValue_SetByte(val, 0x0a);
  EXPECT_EQ(rbusValue_GetType(val), RBUS_BYTE);
  EXPECT_EQ(rbusValue_GetByte(val), 0x0a);

  rbusValue_SetByte(val, 0xff);
  EXPECT_EQ(rbusValue_GetByte(val), 0xff);

  rbusValue_SetByte(val, static_cast<uint8_t>(0xff+1));
  EXPECT_EQ(rbusValue_GetByte(val), 0x00);

  rbusValue_Release(val);
}
