/*
 * LED.h
 *
 * Created: 11/12/2022 2:02:48 PM
 *  Author: Hossam Elzhar
 */ 



#ifndef LED_H_
#define LED_H_

/************************************************************************/
/* Includes Section                                                     */
#include "../../MCAL/GPIO/GPIO.h"
/************************************************************************/

typedef struct
{
	Port_type port;
	Pin_type  pin;
	VoltageLevel_type ON_VOLT_LEVEL;
	
}LED_t;


Std_Return LED_Init(const LED_t* led);
Std_Return LED_ON(const LED_t* led);
Std_Return LED_OFF(const LED_t* led);


#endif /* LED_H_ */