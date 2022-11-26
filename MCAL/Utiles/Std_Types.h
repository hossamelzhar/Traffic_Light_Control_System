/*
 * Std_Types.h
 *
 * Created: 11/12/2022 2:08:01 PM
 *  Author: Hossam Elzhar
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long s64;

#define TRUE (u8)0x01
#define FALSE (u8)0x00
#define NULLPTR   ((void*)0)

typedef enum
{
	OK = 0,
	NOT_OK
}Std_Return;


#endif /* STD_TYPES_H_ */