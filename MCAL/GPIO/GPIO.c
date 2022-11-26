/*
 * GPIO.c
 *
 * Created: 11/12/2022 2:03:54 PM
 *  Author: Hossam Elzhar
 */ 


/************************************************************************/
/* Includes Section                                                     */
#include "GPIO.h"
/************************************************************************/


/************************************ Implementation Section ******************************/


/************************************************************************
 * description : Set A Pin Direction In A Port As Input OR OUTPUT
 * INPUT Args  : PORT Type, Pin Number In Port, State OF Pin
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return GPIO_Set_Pin_Direction(Port_type port, Pin_type pin, Pin_Stat_type stat)
{
	Std_Return RetVal = OK;
	//switch on port type
	switch(port)
	{
		case PA:
            //switch on State type
			switch(stat)
			{
				case INPUT: CLEAR_BIT(DDRA, pin); break;
				case OUTPUT:  SET_BIT(DDRA, pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRA, pin); SET_BIT(PORTA, pin); break;
				default:
					RetVal = NOT_OK;
					break;
			}
			break;
		case PB:
			switch(stat)
			{
				case INPUT: CLEAR_BIT(DDRB, pin); break;
				case OUTPUT:  SET_BIT(DDRB, pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRB, pin); SET_BIT(PORTB, pin); break;
				default:
					RetVal = NOT_OK;
					break;
			}
			break;
		case PC:
			switch(stat)
			{
				case INPUT: CLEAR_BIT(DDRC, pin); break;
				case OUTPUT:  SET_BIT(DDRC, pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRC, pin); SET_BIT(PORTC, pin); break;
				default:
					RetVal = NOT_OK;
					break;
			}
			break;
		case PD:
			switch(stat)
			{
				case INPUT: CLEAR_BIT(DDRD, pin); break;
				case OUTPUT:  SET_BIT(DDRD, pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRD, pin); SET_BIT(PORTD, pin); break;
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


/************************************************************************
 * description : Write A value On A Port
 * INPUT Args  : PORT Type, Value
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return GPIO_Write_Port(Port_type port, u8 value)
{
	Std_Return RetVal = OK;
	switch (port)
	{
		case PA: ASSIGN_REG(PORTA,value); break;
		case PB: ASSIGN_REG(PORTB,value); break;
		case PC: ASSIGN_REG(PORTC,value); break;
		case PD: ASSIGN_REG(PORTD,value); break;
		default:
			RetVal = NOT_OK;
			break;
	}
	
	return RetVal;
}


/************************************************************************
 * description : Read value OF A Port
 * INPUT Args  : PORT Type
 * RETURN      : Value Of Port
 * **********************************************************************
 * */
u8 GPIO_Read_Port(Port_type port)
{
	switch (port)
	{
		case PA:
			return PINA;
			break;
		case PB:
			return PINB;
			break;
		case PC:
			return PINC;
			break;
		case PD:
			return PIND;
			break;
		default:
			return 0x00;
			break;
	}
}


/************************************************************************
 * description : Write A value On A Pin In Port
 * INPUT Args  : PORT Type, Pin Number In Port, Value
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return GPIO_Write_Pin(Port_type port, Pin_type pin, VoltageLevel_type stat)
{
	Std_Return RetVal = OK;
	switch(port)
	{
		case PA:
			switch(stat)
			{
				case LOW: CLEAR_BIT(PORTA, pin); break;
				case HIGH:  SET_BIT(PORTA, pin); break;
				default:
				RetVal = NOT_OK;
				break;
			}
			break;
		case PB:
			switch(stat)
			{
				case LOW: CLEAR_BIT(PORTB, pin); break;
				case HIGH:  SET_BIT(PORTB, pin); break;
				default:
				RetVal = NOT_OK;
				break;
			}
			break;
		case PC:
			switch(stat)
			{
				case LOW: CLEAR_BIT(PORTC, pin); break;
				case HIGH:  SET_BIT(PORTC, pin); break;
				default:
				RetVal = NOT_OK;
				break;
			}
			break;
		case PD:
			switch(stat)
			{
				case LOW: CLEAR_BIT(PORTD, pin); break;
				case HIGH:  SET_BIT(PORTD, pin); break;
				default:
				RetVal = NOT_OK;
				break;
			}
			break;
	}
	
	return RetVal;
}



/************************************************************************
 * description : Read A value OF A Pin In Port
 * INPUT Args  : PORT Type, Pin Number In Port
 * RETURN      : HIGH OR LOW
 * **********************************************************************
 * */
VoltageLevel_type GPIO_Read_Pin(Port_type port, Pin_type pin)
{
	switch (port)
	{
		case PA:
			return CHECK_BIT(PINA,pin);
			break;
		case PB:
			return CHECK_BIT(PINB,pin);
			break;
		case PC:
			return CHECK_BIT(PINC,pin);
			break;
		case PD:
			return CHECK_BIT(PIND,pin);
			break;
		default:
			return 0x00;
			break;
	}
}



/************************************************************************
 * description : Toggle A value OF A Pin In Port
 * INPUT Args  : PORT Type, Pin Number In Port
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
Std_Return GPIO_Toggle_Pin(Port_type port, Pin_type pin)
{
	Std_Return RetVal = OK;
	switch (port)
	{
		case PA:
			TOGGLE_BIT(PORTA,pin);
			break;
		case PB:
			TOGGLE_BIT(PORTB,pin);
			break;
		case PC:
			TOGGLE_BIT(PORTC,pin);
			break;
		case PD:
			TOGGLE_BIT(PORTD,pin);
			break;
		default:
			RetVal =NOT_OK;
			break;
	}
	
	return RetVal;
}
