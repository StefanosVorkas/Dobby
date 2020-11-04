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
#ifndef __RT_LIST_H__
#define __RT_LIST_H__

#include "rtError.h"
#include <stdio.h>

struct _rtList;
typedef struct _rtList* rtList;

struct _rtListItem;
typedef struct _rtListItem* rtListItem;

typedef void (*rtList_Cleanup)(void *);

extern void* rtListReuseData;

rtError rtList_Create(rtList* plist);
rtError rtList_Destroy(rtList list, rtList_Cleanup destroyer);
rtError rtList_PushFront(rtList list, void* data, rtListItem* pitem);
rtError rtList_PushBack(rtList list, void* data, rtListItem* pitem);
rtError rtList_InsertBefore(rtList list, void* data, rtListItem at, rtListItem* pitem);
rtError rtList_InsertAfter(rtList list, void* data, rtListItem at, rtListItem* pitem);
rtError rtList_RemoveItem(rtList list, rtListItem item, rtList_Cleanup destroyer);
rtError rtList_GetSize(rtList list, size_t* size);
rtError rtList_GetFront(rtList list, rtListItem* pitem);
rtError rtList_GetBack(rtList list, rtListItem* pitem);
rtError rtListItem_GetData(rtListItem item, void** data);
rtError rtListItem_SetData(rtListItem item, void* data);
rtError rtListItem_GetNext(rtListItem item, rtListItem* pitem);
rtError rtListItem_GetPrev(rtListItem item, rtListItem* pitem);

#endif
