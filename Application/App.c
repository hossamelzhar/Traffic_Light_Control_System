/*
 * App.c
 *
 * Created: 11/12/2022 2:02:09 PM
 *  Author: Hossam Elzhar
 */ 


/************************************ Includes Section *********************************/
#include "App.h"
/***************************************************************************************/



/************************************ Definition Section *********************************/
volatile u8 timer0_OV_flag = 0;
volatile u8 INT0_flag = 0;
volatile u16 milli = 0;
volatile u8 second = 0;
volatile u16 counter = 0;
Std_Return RetVal;

LED_t Cars_Green  = {PA, Pin0, HIGH};
LED_t Cars_Yellow = {PA, Pin1, HIGH};
LED_t Cars_Red    = {PA, Pin2, HIGH};

LED_t pedestrians_Green  = {PB, Pin0, HIGH};
LED_t pedestrians_Yellow = {PB, Pin1, HIGH};
LED_t pedestrians_Red    = {PB, Pin2, HIGH};
/***************************************************************************************/


/***************************************************************************************
 * description : Configure Application Requirements,
 *                 GPIO, LEDS, External Interrupts , Timer
 * INPUT Args  : Void
 * RETURN      : Execution Status (OK OR NOT_OK)
 * *************************************************************************************
 */
Std_Return App_Config(void)
{
    //Set Pin Of Interrupt 0 As PULL UP
    GPIO_Set_Pin_Direction(PD, Pin2, IN_PULL_UP);
    
    //Initialize LEDs Of Cars
    RetVal |= LED_Init(&Cars_Green);
    RetVal |= LED_Init(&Cars_Yellow);
    RetVal |= LED_Init(&Cars_Red);
    //Initialize LEDs Of Pedestrians
    RetVal |= LED_Init(&pedestrians_Green);
    RetVal |= LED_Init(&pedestrians_Yellow);
    RetVal |= LED_Init(&pedestrians_Red);
    
    //Enable Global Interrupt
    sei();
    
    //Configure Interrupt Zero Falling Edge
    RetVal |= EXI_TriggerEdge(EX_INT0, FALLING_EDGE);
    //Set Call Back Function
    RetVal |= EXI_SetCallBack(EX_INT0, EXT_INT0_func);
    //Enable It
    RetVal |= EXI_Enable(EX_INT0);
    
    //Configure Timer Zero
    RetVal |= Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_64, OC0_DISCONNECTED);
    RetVal |= Timer0_OV_SetCallBack(Timer0_OV_func);
    Timer0_OV_InterruptEnable();
    //Set Initial Value Of Timer 0 Register To Overflow On 250 Tick
    TCNT0 = TIMER0_INIT_VALUE; //6
   
    return RetVal;
}


/***************************************************************************************
 * description : Check On Timer0 Flag To Know The Current Time, And Take Actions On 
 *               LEDs Depending On Time 
 * INPUT Args  : Void
 * RETURN      : Void
 * *************************************************************************************
 */
void App_start(void)
{
    //Check On Timer 0 Flag Value
	if(0 == timer0_OV_flag)
	{
        //First State, Cars green LED IS ON, Pedestrian RED LED IS ON, Remaining LEDs OFF
		LED_ON(&Cars_Green);
		LED_ON(&pedestrians_Red);
		LED_OFF(&Cars_Yellow);
		LED_OFF(&pedestrians_Yellow);
		LED_OFF(&Cars_Red);
		LED_OFF(&pedestrians_Green);
        //Wait here until Timer Flag Value Changed
		while(timer0_OV_flag == 0);
	}
	else if( (1 == timer0_OV_flag) || (3 == timer0_OV_flag) )
	{
		LED_ON(&Cars_Yellow);
		LED_ON(&pedestrians_Yellow);
		LED_OFF(&Cars_Green);
		LED_OFF(&pedestrians_Green);
		LED_OFF(&Cars_Red);
		LED_OFF(&pedestrians_Red);
        //Wait here until Timer Flag Value Changed
		while( (1 == timer0_OV_flag) || (3 == timer0_OV_flag) )
		{
            //Toggle Yellow LEDs Every 500 Milli Second
			if( (milli > _500_MILLI ) )
			{
				LED_OFF(&Cars_Yellow);
                LED_OFF(&pedestrians_Yellow);
			}
            else
            {
                LED_ON(&Cars_Yellow);
                LED_ON(&pedestrians_Yellow);
            }
		}
	}
	else if(2 == timer0_OV_flag)
	{
		LED_ON(&Cars_Red);
		LED_ON(&pedestrians_Green);
		LED_OFF(&Cars_Yellow);
		LED_OFF(&pedestrians_Yellow);
		LED_OFF(&Cars_Green);
		LED_OFF(&pedestrians_Red);
        //Wait here until Timer Flag Value Changed
		while(timer0_OV_flag == 2);
	}
	else{}
}


/****************************************************************************************
 * description : Timer 0 Function Counts Time With Initial Value In TCNT0 = 6 
 *               To Overflow After 250 Tick
 * INPUT Args  : Void
 * RETURN      : Void
 * **************************************************************************************
 */
void Timer0_OV_func(void)
{
	TCNT0 = TIMER0_INIT_VALUE;//6
	milli++;
	counter++;
    
	if(_1_SECOND == milli) //500
	{
		second++;
        //from 0 sec to 5 sec, Active Led Is Green
		if(5 == second)
		{
            //switch to Yellow
			timer0_OV_flag = 1; 
		}
        //from 5 sec to 10 sec, Active Led Is Yellow
		else if(10 == second)
		{
            //switch to Red
			timer0_OV_flag = 2; 
		}
        //from 10 sec to 15 sec, Active Led Is Red
		else if(15 == second)
		{
            //switch to Yellow
			timer0_OV_flag = 3; 
		}
        //from 15 sec to 20 sec, Active Led Is Yellow
		else if(20 == second)
		{
            //switch to Green, And Reset Every Thing To Start New Round
			timer0_OV_flag = 0; 
			second = 0;
		}
		else{}
		
		milli = 0;
		
	}
	else{}
	
}


void EXT_INT0_func(void)
{
    //Check If This Visit Of ISR Is When Pressing The Button,
    //OR When Rising hand From it (free the button)
    if(INT0_flag == 0)
    {
        //Switch The Interrupt Edge To Rising To Detect When Leaving The Button
        EXI_TriggerEdge(EX_INT0, RISING_EDGE);
        //Start Count Time
        counter = 0;
        //Make Interrupt Flag = 1 To Enter The Second Case, When Leaving The Button
        INT0_flag = 1;
    }
    else
    {
        //After Leaving The button, Check If It Was A Long Press OR NOT
        if(counter > LONG_PRESS_TIME)//more than 1.5 seconds
        {
            /*NOTHING*/
        }
        else
        {
            //Case Short Press
            
            //Check On The Current Timer Flag Value
            //If the Cars Led Green Is ON
            if(0 == timer0_OV_flag)
            {
                TCNT0 = TIMER0_INIT_VALUE;
                timer0_OV_flag = 1;
                milli = 0;
                second = 5;
            }
            //If the Cars Cars Led Yellow Is ON, But Next Active Led Is Green,
            //So Change To Yellow Case That Next Led Is Red
            else if(3 == timer0_OV_flag) 
            {
                TCNT0 = TIMER0_INIT_VALUE;
                timer0_OV_flag = 1;
                milli = 0;
                second = 5;
            }
            else{}
        }
        //Set Interrupt Again As Falling Edge To Detect A New Interrupt Request
        INT0_flag = 0;
        EXI_TriggerEdge(EX_INT0, FALLING_EDGE);
    }
    
}