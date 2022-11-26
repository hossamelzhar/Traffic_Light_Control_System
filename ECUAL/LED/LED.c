/*
 * LED.c
 *
 * Created: 11/12/2022 2:02:59 PM
 *  Author: Hossam Elzhar
 */ 


/************************************************************************/
/* Includes Section                                                     */
#include "LED.h"
/************************************************************************/



/************************************ Implementation Section ******************************/

/************************************************************************
 * description : LED Initialize Its Pin As OUTPUT
 * INPUT Args  : Reference To The LED Structure 
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return LED_Init(const LED_t* led)
{
	Std_Return RetVal = OK;
	
	if(NULLPTR == led)
	{
		RetVal = NOT_OK;
	}
	else
	{
		GPIO_Set_Pin_Direction(led->port, led->pin, OUTPUT);
	}
	
	return RetVal;
}


/************************************************************************
 * description : Write The Required Volt On LED's Pin To Turn ON
 * INPUT Args  : Reference To The LED Structure 
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return LED_ON(const LED_t* led)
{
	Std_Return RetVal = OK;
	
	if(NULLPTR == led)
	{
		RetVal = NOT_OK;
	}
	else
	{
		GPIO_Write_Pin(led->port, led->pin, led->ON_VOLT_LEVEL);
	}
	
	return RetVal;
}


/************************************************************************
 * description : Write The Required Volt On LED's Pin To Turn OFF
 * INPUT Args  : Reference To The LED Structure 
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return LED_OFF(const LED_t* led)
{
	Std_Return RetVal = OK;
	
	if(NULLPTR == led)
	{
		RetVal = NOT_OK;
	}
	else
	{
		GPIO_Write_Pin(led->port, led->pin, !(led->ON_VOLT_LEVEL));
	}
	
	return RetVal;
}