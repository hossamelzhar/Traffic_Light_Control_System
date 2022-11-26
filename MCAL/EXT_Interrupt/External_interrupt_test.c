/*
#include "EXT_Interrupt.h"
#include "../GPIO/GPIO.h"

volatile u8 counter;
void interrupt_function(void);

int main()
{
    //set pin 7 on port c as output, And write High On it
    GPIO_Set_Pin_Direction(PC, Pin7, OUTPUT);
    GPIO_Write_Pin(PC, Pin7, HIGH);
    
    //enable global interrupt
    sei();
    
    //set call back function
    EXI_SetCallBack(EX_INT0, interrupt_function);
    //set trigger Edge
    EXI_TriggerEdge(EX_INT0, FALLING_EDGE);
    //Enable Interrupt 0
    EXI_Enable(EX_INT0);
    
    while(1)
    {
        if(counter == 5)
        {
            EXI_TriggerEdge(EX_INT0, RISING_EDGE);
        }
        else if(counter == 10)
        {
            EXI_Disable(EX_INT0);
        }
    }
    
    
    return 0;
}


void interrupt_function(void)
{
    GPIO_Toggle_Pin(PC, Pin7);
    counter++;
}

 */