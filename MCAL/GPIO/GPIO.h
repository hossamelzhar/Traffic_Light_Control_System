/*
 * GPIO.h
 *
 * Created: 11/12/2022 2:03:42 PM
 *  Author: Hossam Elzhar
 */ 


#ifndef GPIO_H_
#define GPIO_H_


/************************************************************************/
/* Includes Section                                                     */
#include "../Utiles/MemMap.h"
#include "../Utiles/Std_Types.h"
#include "../Utiles/Macros.h"
/************************************************************************/

typedef enum
{
	PA=0,
	PB,
	PC,
	PD,
}Port_type;

typedef enum
{
	Pin0=0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
}Pin_type;


typedef enum
{
	INPUT = 0,
	OUTPUT,
	IN_PULL_UP,
}Pin_Stat_type;


typedef enum
{
	LOW=0,
	HIGH=1,
}VoltageLevel_type;

Std_Return GPIO_Set_Pin_Direction(Port_type port, Pin_type pin, Pin_Stat_type stat);
Std_Return GPIO_Write_Port(Port_type port, u8 value);
u8 GPIO_Read_Port(Port_type port);
Std_Return GPIO_Write_Pin(Port_type port, Pin_type pin, VoltageLevel_type stat);
VoltageLevel_type GPIO_Read_Pin(Port_type port, Pin_type pin);
Std_Return GPIO_Toggle_Pin(Port_type port, Pin_type pin);


#endif /* GPIO_H_ */