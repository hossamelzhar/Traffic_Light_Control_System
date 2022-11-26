/*
 * EXT_Interrupt.c
 *
 * Created: 11/12/2022 2:04:20 PM
 *  Author: Hossam Elzhar
 */ 



/************************************************************************/
/* Includes Section                                                     */
#include "EXT_Interrupt.h"
/************************************************************************/


/************************************ Declaration Section ******************************/
static void (*INT0_fptr)(void);
static void (*INT1_fptr)(void);
static void (*INT2_fptr)(void);
/***************************************************************************************/


/************************************ Implementation Section ***************************/


/************************************************************************
 * description : Enable External Interrupt
 * INPUT Args  : Interrupt Type
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return EXI_Enable(Interrupt_Name_T Interrupt_Name)
{
	Std_Return RetVal = OK;
	//Switch On Interrupt Type
	switch(Interrupt_Name)
	{
		case EX_INT0:
			SET_BIT(GICR, INT0);
			break;
		
		case EX_INT1:
			SET_BIT(GICR, INT1);
			break;
		
		case EX_INT2:
			SET_BIT(GICR, INT2);
			break;
			
		default:
			RetVal = NOT_OK;
			break;
	}
	
	return RetVal;
}


/************************************************************************
 * description : Disable External Interrupt
 * INPUT Args  : Interrupt Type
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return EXI_Disable(Interrupt_Name_T Interrupt_Name)
{
	Std_Return RetVal = OK;
	//Switch On Interrupt Type
	switch(Interrupt_Name)
	{
		case EX_INT0:
			CLEAR_BIT(GICR, INT0);
			break;
		
		case EX_INT1:
			CLEAR_BIT(GICR, INT1);
			break;
		
		case EX_INT2:
			CLEAR_BIT(GICR, INT2);
			break;
		
		default:
			RetVal = NOT_OK;
			break;
	}
	
	return RetVal;
}

/************************************************************************
 * description : Set External Interrupt Trigger Edge
 * INPUT Args  : Interrupt Type, Edge Type
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return EXI_TriggerEdge(Interrupt_Name_T Interrupt_Name, EDGE_T Edge)
{
	Std_Return RetVal = OK;
	//Switch On Interrupt Type
	switch(Interrupt_Name)
	{
		case EX_INT0:
            //Switch On Edge Type
			switch(Edge)
			{
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR, ISC00);
					CLEAR_BIT(MCUCR, ISC01);
					break;
			
				case ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR, ISC00);
					CLEAR_BIT(MCUCR, ISC01);
					break;
			
				case FALLING_EDGE:
					CLEAR_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					break;
			
				case RISING_EDGE:
					SET_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					break;
				default:
					RetVal = NOT_OK;
					break;
			}
			break;
		
		case EX_INT1:
			switch(Edge)
			{
				case LOW_LEVEL:
					CLEAR_BIT(MCUCR, ISC10);
					CLEAR_BIT(MCUCR, ISC11);
					break;
			
				case ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR, ISC10);
					CLEAR_BIT(MCUCR, ISC11);
					break;
			
				case FALLING_EDGE:
					CLEAR_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					break;
			
				case RISING_EDGE:
					SET_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					break;
				default:
					RetVal = NOT_OK;
					break;
			}
			break;
		
		case EX_INT2:
			switch(Edge)
			{
				case FALLING_EDGE:
					CLEAR_BIT(MCUCR, ISC2);
					break;
				
				case RISING_EDGE:
					SET_BIT(MCUCR, ISC2);
					break;
				default:
					RetVal = NOT_OK;
					break;
			}
			break;
			
		default:
			RetVal = NOT_OK;
			break;
	}
	
	return RetVal;
}


/**************************************************************************
 * description : Set External Interrupt Function Call Back
 * INPUT Args  : Interrupt Type, Pointer To Function Take Void Return Void
 * RETURN      : Execution Status (OK OR NOT_OK)
 * ************************************************************************
 * */
Std_Return EXI_SetCallBack(Interrupt_Name_T Interrupt_Name, void (*fptr)(void))
{
	Std_Return RetVal = OK;
	
	if(NULLPTR == fptr)
	{
		RetVal = NOT_OK;
	}
	else
	{
        //Switch On Interrupt Type
		switch(Interrupt_Name)
		{
			case EX_INT0:
				INT0_fptr = fptr;
				break;	
			case EX_INT1:
				INT1_fptr = fptr;
				break;	
			case EX_INT2:
				INT2_fptr = fptr;
				break;
			default:
				RetVal = NOT_OK;
				break;
		}
	}
	
	return RetVal;
}

/************************************************************************
 * description : Set External Interrupt 0 Service Routine
 * INPUT Args  : Interrupt 0 Vector Number
 * RETURN      : Void
 * **********************************************************************
 * */
ISR(INT0_vect)
{
	INT0_fptr();
}


/************************************************************************
 * description : Set External Interrupt 1 Service Routine
 * INPUT Args  : Interrupt 1 Vector Number
 * RETURN      : Void
 * **********************************************************************
 * */
ISR(INT1_vect)
{
	INT1_fptr();
}


/************************************************************************
 * description : Set External Interrupt 2 Service Routine
 * INPUT Args  : Interrupt 2 Vector Number
 * RETURN      : Void
 * **********************************************************************
 * */
ISR(INT2_vect)
{
	INT2_fptr();
}