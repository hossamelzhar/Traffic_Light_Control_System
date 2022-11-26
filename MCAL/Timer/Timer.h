/*
 * Timer.h
 *
 * Created: 11/12/2022 2:03:26 PM
 *  Author: Hossam Elzhar
 */ 


#ifndef TIMER_H_
#define TIMER_H_


/************************************************************************/
/* Includes Section                                                     */
#include "../Utiles/MemMap.h"
#include "../Utiles/Std_Types.h"
#include "../Utiles/Macros.h"
/************************************************************************/

#define SCALLER_MASK 0XF8


typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;


typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;


typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;



Std_Return Timer0_Init(Timer0Mode_type mode, Timer0Scaler_type scaler , OC0Mode_type oc_mode);
void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
Std_Return Timer0_OV_SetCallBack(void (*fptr)(void));
Std_Return Timer0_OC_SetCallBack(void (*fptr)(void));



#endif /* TIMER_H_ */