/*
 * App.h
 *
 * Created: 11/12/2022 2:02:27 PM
 *  Author: Hossam Elzhar
 */ 





#ifndef APP_H_
#define APP_H_


/************************************************************************/
/* Includes Section                                                     */
#include "../ECUAL/LED/LED.h"
#include "../MCAL/EXT_Interrupt/EXT_Interrupt.h"
#include "../MCAL/Timer/Timer.h"
/************************************************************************/


#define TIMER0_INIT_VALUE 6
#define _1_SECOND         500
#define LONG_PRESS_TIME   750
#define _500_MILLI        250



Std_Return App_Config(void);
void App_start(void);
void Timer0_OV_func(void);
void EXT_INT0_func(void);

#endif /* APP_H_ */