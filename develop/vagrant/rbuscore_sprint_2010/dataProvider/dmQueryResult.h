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
#ifndef __DM_QUERY_RESULT_H__
#define __DM_QUERY_RESULT_H__

#include "dmValue.h"
#include <vector>

class dmQueryResult
{
public:
  struct Param
  {
    Param(int code, char const* msg, dmNamedValue const& val);
    int StatusCode;
    std::string StatusMessage;
    dmNamedValue Value;
  };

  dmQueryResult();

  void clear();
  void merge(dmQueryResult const& resuls);
  void setStatus(int status);
  void setStatusMsg(std::string statusmsg);
  void addValue(dmNamedValue const& val, int code = 0, char const* msg = nullptr);

  inline int status() const
    { return m_status; }

  inline std::vector<Param> values() const
    { return m_values; }

  inline std::string statusMsg() const
    { return m_statusMsg; }

private:
  int m_status;
  std::vector<Param> m_values;
  std::string m_statusMsg;
};

#endif
