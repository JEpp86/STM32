/**
*******************************************************************************
* @file    hw_config.c
* @author  Jason Epp
* @brief   configuration specific hardware defines 
*          hardware mapping and MSP functions. 
*******************************************************************************
*/

#include "hw_config.h"

GPIO_CfgTypeDef hw_config[] = 
{ //{GPIO/PortInit, { Pin,     Mode,                Pull,        Speed,                Alternate}},
    {D3_GPIO_Port,  { D3_Pin,  GPIO_MODE_OUTPUT_OD, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH, 0 }},    //D3  PWM
    {D9_GPIO_Port,  { D9_Pin,  GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH, 0 }},    //D9        
    {D14_GPIO_Port, { D14_Pin, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH, 0 }},  //D14
    {D15_GPIO_Port, { D15_Pin, GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH, 0 }},    //D15
};

GPIO_CfgTypeDef * GetPinFromMap(PinMap pin)
{
    return &hw_config[pin];
}

void EnableRequiredClocks(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
}