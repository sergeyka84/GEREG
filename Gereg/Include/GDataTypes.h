/*
 * DataTypes.h
 *
 *  Created on: 29.09.2016 г.
 *      Author: SergeyKa
 */

#pragma once
#include <stddef.h>
#include <inttypes.h>

typedef void			VOID, *PVOID;

typedef void*			HANDLE;

typedef unsigned int	BOOL;

typedef int8_t			INT8;
typedef int16_t			INT16;
typedef int32_t			INT32;
typedef int64_t			INT64;

typedef uint8_t			UINT8;
typedef uint16_t		UINT16;
typedef uint32_t		UINT32;
typedef uint64_t		UINT64;

typedef uint8_t			BYTE;
typedef uint8_t*		PBYTE;

typedef size_t			SIZE;
typedef size_t			INTPTR;
//typedef unsigned size_t	UINTPTR;

typedef	char*			STRING;
typedef const char *	CONST_STRING;


typedef struct _RESULT
{
	union
	{
		UINT32 Value;

		struct
		{
			UINT32	Code		: 24;
			UINT32	Severity	: 7;
			BOOL	IsError		: 1;
		};
	};
} RESULT;


#define BIT_VALUE(bitIndex)				(1 << (bitIndex))
#define IS_BIT_SET(value, bitIndex)		((value) & BIT_VALUE(bitIndex))
#define SET_BIT(value, bitIndex)		((value) |= BIT_VALUE(bitIndex));
#define CLEAR_BIT(value, bitIndex)		((value) &= ~BIT_VALUE(bitIndex));
