/**
*******************************************************************************
* @file    hw_init.h
* @author  Jason Epp
* @brief   HW MSP (MCU Support Package) initilization functiuons
*          standard MSP functions based on those provided by STM MCD 
*          Application Team/STM32 Cube
*******************************************************************************
*/

#ifndef HW_INIT_H
#define HW_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

//ST Drivers
#include "stm32f7xx_hal.h"
#include "stm32f746xx.h"
//hw 
#include "stm32f7xx_hal_conf.h"
#include "hw_init.h"
#include "hw_config.h"

//sys_tick
TIM_HandleTypeDef        htim6; 

//base HW configuration
void SystemClock_Config(void);
void CPU_CACHE_Enable(void);
//initialization function 
void HW_Init(void);



#ifdef __cplusplus
}
#endif

#endif /* HW_INIT_H */