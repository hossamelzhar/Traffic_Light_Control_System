

/*
#include "GPIO.h"

#define F_CPU 8000000
#include "util/delay.h"
VoltageLevel_type value;





int main()
{
        
    //Set PORTA As INPUT
    GPIO_Set_Pin_Direction(PA, Pin0, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin1, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin2, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin3, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin4, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin5, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin6, INPUT);
    GPIO_Set_Pin_Direction(PA, Pin7, INPUT);
    //SET PORTB AS OUTPUT
    GPIO_Set_Pin_Direction(PB, Pin0, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin1, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin2, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin3, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin4, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin5, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin6, OUTPUT);
    GPIO_Set_Pin_Direction(PB, Pin7, OUTPUT);

    //case 1 test read port and write port functions
    //Init PORTB By Zero
    //GPIO_Write_Port(PB, 0x00);
    
    //case 3 test toggle pin function
    GPIO_Set_Pin_Direction(PD, Pin5, OUTPUT);
    GPIO_Write_Pin(PD, Pin5, HIGH);
    
    
    
    while(1)
    {
        //case 1
        //Read PortA, Write It On PortB
        //GPIO_Write_Port(PB, GPIO_Read_Port(PA));
        
        //case 2 test read pin and write pin functions
        //Read Pin from portA, Write Pin In PortB
        //value = GPIO_Read_Pin(PA, Pin7);
        //GPIO_Write_Pin(PB, Pin0, value);
        
        //case 3
        //Toggle Pin5 On PortD every 500 milli
        GPIO_Toggle_Pin(PD, Pin5);
        _delay_ms(500);
        
    }
    
    return 0;
}

*/