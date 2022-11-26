/*
 * Traffic_Light_Control.c
 *
 * Created: 11/12/2022 11:49:04 AM
 * Author : Hossam Elzhar
 */ 

/************************************************************************/
/* Includes section                                                     */
#include "./Application/App.h"
/************************************************************************/


int main(void)
{

    Std_Return RetVal = NOT_OK;
    //Set Application Configurations
    RetVal = App_Config();
    //Check On Return Value
    if(OK == RetVal)
    {
        while (1) 
        {
            //Start The Application
            App_start();
        }
    }
    else{}//Terminate
}

