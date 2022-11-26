
/*
#include "Timer.h"
#include "../GPIO/GPIO.h"

void timer0_OVF_function(void);
void timer0_OC_function(void);
volatile u16 milli;
u8 counter;

int main()
{
    
    //Set Pin 0 on Port B As Output, and out High
    GPIO_Set_Pin_Direction(PB, Pin0, OUTPUT);
    GPIO_Write_Pin(PB, Pin0, HIGH);
    //Set Pin 7 on Port B As Output, and out High
    GPIO_Set_Pin_Direction(PB, Pin7, OUTPUT);
    GPIO_Write_Pin(PB, Pin7, HIGH);
    
    //Set OCR0 pin as output
    GPIO_Set_Pin_Direction(PB, Pin3, OUTPUT);
    
    //Enable Global interrupt
    sei();
    
    
    //initialize Timer 0 as normal mode, scaler 8 , output compare pin disconnected
    Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OC0_DISCONNECTED);
    Timer0_OV_SetCallBack(timer0_OVF_function);
    Timer0_OV_InterruptEnable();
    //Set Overflow Ticks = 200 Tick
    TCNT0 = 56;
    
    
    
    Timer0_Init(TIMER0_CTC_MODE, TIMER0_SCALER_8, OC0_TOGGLE);
    //set output compare match interrupt function
    Timer0_OC_SetCallBack(timer0_OC_function);
    //enable Timer0 output compare interrupt
    Timer0_OC_InterruptEnable();
    OCR0 = 200;
    
    
    
    Timer0_Init(TIMER0_FASTPWM_MODE, TIMER0_SCALER_8, OC0_NON_INVERTING);
    OCR0 = 200;
    
    
    
    Timer0_Init(TIMER0_PHASECORRECT_MODE, TIMER0_SCALER_8, OC0_INVERTING);
    OCR0 = 100;
    
    
    while(1)
    {
       
    }
    
    return 0;
}


void timer0_OVF_function(void)
{
    TCNT0 = 56;
    counter++;
    
    if(5 == counter)
    {
        milli++;
        if(500 == milli) // 1 second
        {
            GPIO_Toggle_Pin(PB, Pin0);
            milli = 0;
        }
        counter = 0;
    }
}

void timer0_OC_function(void)
{
    counter++;
    
    if(5 == counter)
    {
        milli++;
        if(500 == milli) // 1 second
        {
            GPIO_Toggle_Pin(PB, Pin7);
            milli = 0;
        }
        counter = 0;
    }
}
 * 
 */