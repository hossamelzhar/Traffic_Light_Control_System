/*
 * Timer.c
 *
 * Created: 11/12/2022 2:03:12 PM
 *  Author: Hossam Elzhar
 */ 


/************************************ Includes Section *********************************/
#include "Timer.h"
/***************************************************************************************/



/************************************ Declaration Section ******************************/
static void (*Timer0_OC_fptr)(void);
static void (*Timer0_OV_fptr)(void);
/***************************************************************************************/

/************************************ Implementation Section ******************************/

/************************************************************************
 * description : Timer 0 Initialize Mode And Scaler And OC0 Mode
 * INPUT Args  : Timer0 Mode, Scaler Value, OC0 Mode
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return Timer0_Init( Timer0Mode_type mode,Timer0Scaler_type scaler ,
                                                     OC0Mode_type oc_mode)
{
	Std_Return RetVal = OK;
	//Switch On Timer Modes
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
			CLEAR_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
		case TIMER0_PHASECORRECT_MODE:
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
		case TIMER0_CTC_MODE:
			CLEAR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
		case TIMER0_FASTPWM_MODE:
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
		default:
			RetVal = NOT_OK;
			break;
	}

    //Clear The 3 Most Least Bits In TCCR0 Register
	TCCR0 &= SCALLER_MASK; //0xF8
    
    //Set Them By The Selected Scall
	TCCR0 |= scaler;

    //Switch On OC0 Modes
	switch (oc_mode)
	{
		case OC0_DISCONNECTED:
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break;
		case OC0_TOGGLE:
			SET_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break;
		case OC0_NON_INVERTING:
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
		case OC0_INVERTING:
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
		default:
			RetVal = NOT_OK;
			break;
	}
	
	return RetVal;
}

/*************************************************************************************
 * description : Enable Timer 0 Overflow Interrupt
 * INPUT Args  : void
 * RETURN      : void
 * ***********************************************************************************
 */
void Timer0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}

/*************************************************************************************
 * description : Disable Timer 0 Overflow Interrupt
 * INPUT Args  : void
 * RETURN      : void
 * ***********************************************************************************
 */
void Timer0_OV_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}

/*************************************************************************************
 * description : Enable Timer 0 OutPut Compare Interrupt
 * INPUT Args  : void
 * RETURN      : void
 * ***********************************************************************************
 */
void Timer0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

/*************************************************************************************
 * description : Disable Timer 0 OutPut Compare Interrupt
 * INPUT Args  : void
 * RETURN      : void
 * ***********************************************************************************
 * */
void Timer0_OC_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}

/*************************************************************************************
 * description : Set Timer 0 Overflow Interrupt Call Back Function
 * INPUT Args  : Pointer To Function Take Void And Return Void
 * RETURN      : Execution Status (OK OR NOT_OK)
 * ***********************************************************************************
 * */
Std_Return Timer0_OV_SetCallBack(void (*fptr)(void))
{
	Std_Return RetVal = OK;
	if(NULLPTR == fptr)
	{
		RetVal = NOT_OK;
	}
	else
	{
		Timer0_OV_fptr = fptr;
	}

	return RetVal;
}

/*************************************************************************************
 * description : Set Timer 0 OUTPUT Compare Interrupt Call Back Function
 * INPUT Args  : Pointer To Function Take Void And Return Void
 * RETURN      : Execution Status (OK OR NOT_OK)
 * ***********************************************************************************
 * */
Std_Return Timer0_OC_SetCallBack(void (*fptr)(void))
{
	Std_Return RetVal = OK;
	if(NULLPTR == fptr)
	{
		RetVal = NOT_OK;
	}
	else
	{
		Timer0_OC_fptr = fptr;
	}

	return RetVal;
}

/*************************************************************************************
 * description : Set Timer 0 Overflow Interrupt Service Routine
 * INPUT Args  : Timer 0 Vector Number 
 * RETURN      : void
 * ***********************************************************************************
 * */
ISR(TIMER0_OVF_vect)
{
    Timer0_OV_fptr();
}

ISR(TIMER0_COMP_vect)
{
    Timer0_OC_fptr();
}
