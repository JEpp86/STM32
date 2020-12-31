/**
*******************************************************************************
* @file    TargetGPIO.c
* @author  Jason Epp
* @brief   HW initialization functions to be executed at startup used from 
*          standard startup functions provided by STM MCD Application Team/
*          STM32 Cube
*******************************************************************************
*/

#include "TargetGPIO.h"


GPIO_CfgTypeDef * InitGPIO(PinMap pin)
{
	GPIO_CfgTypeDef * gpio = GetPinFromMap(pin);
	HAL_GPIO_Init(gpio->pin, &gpio->config );
	return gpio;
}

void SetGPIO(GPIO_CfgTypeDef * gpio_pin, GPIO_PinState state)
{
	HAL_GPIO_WritePin(gpio_pin->pin, gpio_pin->config.Pin, state);
}
void ToggleGPIO(GPIO_CfgTypeDef * gpio_pin)
{
	HAL_GPIO_TogglePin(gpio_pin->pin, gpio_pin->config.Pin);
}