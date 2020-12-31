/**
*******************************************************************************
* @file    hw_init.h
* @author  Jason Epp
* @brief   HW MSP (MCU Support Package) initilization functiuons
*          standard MSP functions based on those provided by STM MCD 
*          Application Team/STM32 Cube
*******************************************************************************
*/

#ifndef TARGETGPIO_H
#define TARGETGPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hw_config.h"


GPIO_CfgTypeDef * InitGPIO(PinMap pin);

void SetGPIO(GPIO_CfgTypeDef * gpio_pin, GPIO_PinState state);
void ToggleGPIO(GPIO_CfgTypeDef * gpio_pin);


#ifdef __cplusplus
}
#endif

#endif /* TARGETGPIO_H */