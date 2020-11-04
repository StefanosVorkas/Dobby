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

/**
 * @file        rubs_value.h
 * @brief       rbusValue
 * @defgroup    rbusValue
 * @brief       An rbus value is a variant data type representing a fundamental piece of data passed through rbus.
 *              An rbusValue_t is a reference counted handle to an rbus value.  
 * @{
 */

#ifndef RBUS_VALUE_H
#define RBUS_VALUE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief       The value types that can be contained inside an rbusValue_t
 * @enum        rbusValueType_t
 */
typedef enum
{
    RBUS_BOOLEAN  = 0x500,  /**< bool true or false */
    RBUS_CHAR,              /**< char of size 1 byte*/
    RBUS_BYTE,              /**< unsigned char */
    RBUS_INT8,              /**< 8 bit int */
    RBUS_UINT8,             /**< 8 bit unsigned int */
    RBUS_INT16,             /**< 16 bit int */
    RBUS_UINT16,            /**< 16 bit unsigned int */
    RBUS_INT32,             /**< 32 bit int */
    RBUS_UINT32,            /**< 32 bit unsigned int */
    RBUS_INT64,             /**< 64 bit int */
    RBUS_UINT64,            /**< 64 bit unsigned int */
    RBUS_SINGLE,            /**< 32 bit float */
    RBUS_DOUBLE,            /**< 64 bit float */
    RBUS_DATETIME,          /**< rbusDateTime_t structure for Date/Time */
    RBUS_STRING,            /**< null terminated C style string */
    RBUS_BYTES,             /**< byte array */
    RBUS_PROPERTY,          /**< property instance */
    RBUS_OBJECT,            /**< object instance */
    RBUS_NONE
} rbusValueType_t;

typedef struct _rbusTimeZone {
    int m_tzhour;
    int m_tzmin;
} rbusTimeZone_t ;

typedef struct _rbusDateTime {
    struct tm       m_time;
    rbusTimeZone_t  m_tz;
    bool            m_isWest;
} rbusDateTime_t;

/**
 * @brief       A handle to an rbus value.
 */
typedef struct _rbusValue* rbusValue_t;

/**
 * @brief       A handle to an rbus object.
 * @ingroup     rbusObject
 */
typedef struct _rbusObject* rbusObject_t;

/**
 * @brief       A handle to an rbus property.
 * @ingroup     rbusProperty
 */
typedef struct _rbusProperty* rbusProperty_t;

/** @fn void rbusValue_Init(rbusValue_t* pvalue)
 *  @brief  Allocate and initialize a value to an empty state
 *          with its type set to RBUS_NONE and data set to NULL.
 *          This automatically retains ownership of the value. 
 *          It's the caller's responsibility to release ownership by
 *          calling rbusValue_Release once it's done with it.
 *  @param  pvalue reference to an address where the new value will be assigned.
 *          The caller is responsible for releasing the value with rbusValue_Release
 */
void rbusValue_Init(rbusValue_t* pvalue);

/** @fn void rbusValue_Retain(rbusValue_t value)
 *  @brief Take shared ownership of the value.  This allows a value to have 
 *         multiple owners.  The first owner obtains ownership with rbusValue_Init.
 *         Additional owners can be assigned afterwards with rbusValue_Retain.  
 *         Each owner must call rbusValue_Release once done using the value.
 *  @param value the value to retain
 */
void rbusValue_Retain(rbusValue_t value);

/** @fn void rbusValue_Release(rbusValue_t value)
 *  @brief Release ownership of the value.  This must be called when done using
 *         a value that was retained with either rbusValue_Init or rbusValue_Retain.
 *  @param value the value to release
 */
void rbusValue_Release(rbusValue_t value);

///  @brief rbusValue_FromBoolean initialize a value's type to RBUS_BOOLEAN and data to the supplied bool 
rbusValue_t rbusValue_FromBoolean(bool b);

///  @brief rbusValue_FromInt16 initialize a value's type to RBUS_INT16 and data to the supplied int16_t 
rbusValue_t rbusValue_FromInt16(int16_t i16);

///  @brief rbusValue_FromUInt16 initialize a value's type to RBUS_UINT16 and data to the supplied uint16_t 
rbusValue_t rbusValue_FromUInt16(uint16_t u16);

///  @brief rbusValue_FromInt32 initialize a value's type to RBUS_INT32 and data to the supplied int32_t 
rbusValue_t rbusValue_FromInt32(int32_t i32);

///  @brief rbusValue_FromUInt32 initialize a value's type to RBUS_UINT32 and data to the supplied uint32_t 
rbusValue_t rbusValue_FromUInt32(uint32_t u32);

///  @brief rbusValue_FromInt64 initialize a value's type to RBUS_INT64 and data to the supplied int64_t 
rbusValue_t rbusValue_FromInt64(int64_t i64);

///  @brief rbusValue_FromUInt64 initialize a value's type to RBUS_UINT64 and data to the supplied uint64_t 
rbusValue_t rbusValue_FromUInt64(uint64_t u64);

///  @brief rbusValue_FromSingle initialize a value's type to RBUS_SINGLE and data to the supplied float 
rbusValue_t rbusValue_FromSingle(float f32);

///  @brief rbusValue_FromDouble initialize a value's type to RBUS_DOUBLE and data to the supplied double 
rbusValue_t rbusValue_FromDouble(double f64);

///  @brief rbusValue_FromTime initialize a value's type to RBUS_DATETIME and data to the supplied timeval 
rbusValue_t rbusValue_FromTime(rbusDateTime_t* tv);

///  @brief rbusValue_FromString initialize a value's type to RBUS_STRING and data to the supplied string 
///         s should be a null terminated c string
rbusValue_t rbusValue_FromString(char const* s);

///  @brief rbusValue_FromBytes initialize a value's type to RBUS_BYTES and data to the supplied byte array
rbusValue_t rbusValue_FromBytes(uint8_t const* bytes, int len);

///  @brief rbusValue_FromProperty initialize a value's type to RBUS_PROPERTY and data to the supplied property
rbusValue_t rbusValue_FromProperty(struct _rbusProperty* propert);

///  @brief rbusValue_FromObject initialize a value's type to RBUS_OBJECT and data to the supplied object
rbusValue_t rbusValue_FromObject(struct _rbusObject* object);

/** @fn void rbusValue_Compare(rbusValue_t value1, rbusValue_t value2)
 *  @brief Compare two values for equality.  They are equal if both the type and data are equal.
 *  @param value1 the first value to compare
 *  @param value2 the second value to compare
 *  @return The compare result where 0 is equal and non-zero if not equal.  If value1
 */
int rbusValue_Compare(rbusValue_t value1, rbusValue_t value2);

/** @fn void rbusValue_SetPointer(rbusValue_t value1, rbusValue_t value2)
 *  @brief Set value1 pointer to value2 while handling the ref count.
 *  @param value1 the first value to swap
 *  @param value2 the second value to swap
 */
void rbusValue_SetPointer(rbusValue_t* value1, rbusValue_t value2);

/** @fn void rbusValue_Copy(rbusValue_t dest, rbusValue_t source)
 *  @brief Copy data from source to dest
 *  @param dest destination to copy data into
 *  @param source source of data to copy from
 */
void rbusValue_Copy(rbusValue_t dest, rbusValue_t source);

/** @fn char* rbusValue_ToString(rbusValue_t value, char* buf, size_t buflen)
 *  @brief Returns a null terminated string representing the data of the value.  
 *         Parameters buf and buflen are optional and allow the caller to pass in a buffer 
 *          to write the string to.  If parameter buf is NULL, this method will allocate a buffer
 *          to write the string to and the caller should call free to deallocate the buffer.
 *          For DateTime datatype, below ISO-8601 formats as per TR-069_Amendment-6 will be used for printing.
 *          YYYY-MM-DDThh:mm:ssZ
 *          YYYY-MM-DDThh:mm:ss+00:00
 *          YYYY-MM-DDThh:mm:ss-00:00
 *  @param value the value to convert to a string
 *  @param buf optional buffer to write the string to
 *  @param buflen the length of buf if buf was supplied, otherwise ignored
 *  @return A null-terminated string.  The caller must call free on this if parameter buf was NULL.
 */
char* rbusValue_ToString(rbusValue_t value, char* buf, size_t buflen);

/** @fn char* rbusValue_ToDebugString(rbusValue_t value, char* buf, size_t buflen)
 *  @brief Returns a null terminated string representing the type and data of the value.  
 *         Parameters buf and buflen are optional and allow the caller to pass in a buffer 
 *          to write the string to.  If parameter buf is NULL, this method will allocate a buffer
 *          to write the string to and the caller should call free to deallocate the buffer.
 *  @param value the value to convert to a string
 *  @param buf optional buffer to write the string to
 *  @param buflen the length of buf if buf was supplied, otherwise ignored
 *  @return A null-terminated string.  The caller must call free on this if parameter buf was NULL.
 */
char* rbusValue_ToDebugString(rbusValue_t value, char* buf, size_t buflen);

/** @fn char* rbusValue_GetType(rbusValue_t value)
 *  @brief Get the type of a value.  
 *  @param value A value.
 *  @return The type of the value.
 */ 
rbusValueType_t rbusValue_GetType(rbusValue_t value);

/** @name rbusValue_Get[Type]
 * @brief These functions returns the data stored in the value according to their type.
 *        The data is not coerced to the type, thus the caller should ensure
 *        the value's actual type matches the function being called.  The caller can 
 *        call rbusValue_GetType to get the type.
 * @param value A value to get data from.
 * @return The data as a specific type. This is meant to be a const accessor. 
 *         To avoid large copies, if the type is a buffer or struct type, 
 *         a const pointer to the actual data is returned. 
 */
///@{
bool rbusValue_GetBoolean(rbusValue_t value);

char rbusValue_GetChar(rbusValue_t value);

unsigned char rbusValue_GetByte(rbusValue_t value);

int16_t rbusValue_GetInt16(rbusValue_t value);

uint16_t rbusValue_GetUInt16(rbusValue_t value);

int32_t rbusValue_GetInt32(rbusValue_t value);

uint32_t rbusValue_GetUInt32(rbusValue_t value);

int64_t rbusValue_GetInt64(rbusValue_t value);

uint64_t rbusValue_GetUInt64(rbusValue_t value);

float rbusValue_GetSingle(rbusValue_t value);

double rbusValue_GetDouble(rbusValue_t value);

rbusDateTime_t const* rbusValue_GetTime(rbusValue_t value);

/// @param len optional param to retrieve the length of the string being returned(not including null terminator).
/// @return A c-style, null terminated string.  This is a pointer to the actual data thus no allocation or copy is done.
char const* rbusValue_GetString(rbusValue_t value, int* len);

/// @param len optional param to retrieve the length of the byte buffer being returned
/// @return A bytes array.  This is a pointer to the actual data thus no allocation or copy is done.
uint8_t const* rbusValue_GetBytes(rbusValue_t value, int* len);

struct _rbusProperty* rbusValue_GetProperty(rbusValue_t value);

struct _rbusObject* rbusValue_GetObject(rbusValue_t value);
///@}

/** @name rbusValue_Set[Type]
 * @brief These functions set the type and data of a value.
 * @param value A value to set.
 * @param data The type specific data to set on the value.
 */
///@{
void rbusValue_SetBoolean(rbusValue_t value, bool b);

void rbusValue_SetChar(rbusValue_t v, char c);

void rbusValue_SetByte(rbusValue_t v, unsigned char u);

void rbusValue_SetInt16(rbusValue_t value, int16_t i16);

void rbusValue_SetUInt16(rbusValue_t value, uint16_t u16);

void rbusValue_SetInt32(rbusValue_t value, int32_t i32);

void rbusValue_SetUInt32(rbusValue_t value, uint32_t u32);

void rbusValue_SetInt64(rbusValue_t value, int64_t i64);

void rbusValue_SetUInt64(rbusValue_t value, uint64_t u64);

void rbusValue_SetSingle(rbusValue_t value, float f32);

void rbusValue_SetDouble(rbusValue_t value, double f64);

void rbusValue_SetTime(rbusValue_t value, rbusDateTime_t* tv);

/// @param s        a c-style, null terminated string which is duplicated/copied to the value.
void rbusValue_SetString(rbusValue_t value, char const* s);

/// @param bytes    a bytes array which is duplicated/copied to the value.
/// @param len      the length of the array or the number of bytes to copy.
void rbusValue_SetBytes(rbusValue_t value, uint8_t const* bytes, int len);

void rbusValue_SetProperty(rbusValue_t value, struct _rbusProperty* property);

void rbusValue_Swap(rbusValue_t* v1, rbusValue_t* v2);

void rbusValue_SetObject(rbusValue_t value, struct _rbusObject* object);
///@}

///  @brief rbusValue_SetFromString sets the value's type to given type and data to appropriate by converting the string
/** 
 *  @brief Sets the type and data of a value by converting a string representation of the data to a specific typed data.
 *  @param value A value to set.
 *  @param type The type of data represented by the input string and to which the value will be assigned.
 *  @param str A string representation of the data which will be coerced to the type specified by the type param and assigned to the value.
 *  @return bool true if this function succeeds to coerce the type and set the value or false if it fails
 */
bool rbusValue_SetFromString(rbusValue_t value, rbusValueType_t type, const char* str);

/** @fn void rbusValue_fwrite(rbusValue_t obj, int depth, FILE* fout)
 *  @brief A debug utility function to write the value as a string to a file stream.
 */
void rbusValue_fwrite(rbusValue_t obj, int depth, FILE* fout);

#ifdef __cplusplus
}
#endif
#endif

/** @} */
