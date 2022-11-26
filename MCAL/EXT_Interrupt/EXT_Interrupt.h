/*
 * EXT_Interrupt.h
 *
 * Created: 11/12/2022 2:04:31 PM
 *  Author: Hossam Elzhar
 */ 


#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_


/************************************************************************/
/* Includes Section                                                     */
#include "../Utiles/MemMap.h"
#include "../Utiles/Std_Types.h"
#include "../Utiles/Macros.h"
/************************************************************************/


typedef enum
{
	EX_INT0,
	EX_INT1,
	EX_INT2
}Interrupt_Name_T;

typedef enum
{
	LOW_LEVEL = 0,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}EDGE_T;


Std_Return EXI_Enable(Interrupt_Name_T Interrupt_Name);
Std_Return EXI_Disable(Interrupt_Name_T Interrupt_Name);
Std_Return EXI_TriggerEdge(Interrupt_Name_T Interrupt_Name, EDGE_T Edge);
Std_Return EXI_SetCallBack(Interrupt_Name_T Interrupt_Name, void (*fptr)(void));

#endif /* EXT_INTERRUPT_H_ */