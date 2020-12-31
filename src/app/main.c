/***********************************************************
* main.c
* main entry into application
*
*
***********************************************************/
#include "hw_init.h"
#include "TargetGPIO.h"

GPIO_CfgTypeDef  * pin_d0;


int main(void)
{
    //Set up clock config and hardware initialization
    HW_Init();
    pin_d0 = InitGPIO(D0);
    
    //loop forever
    for (;;)
    {
    	ToggleGPIO(pin_d0);
    	HAL_Delay(1000);
		
  	}
}
