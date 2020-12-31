/**
*******************************************************************************
* @file    hw_init.c
* @author  Jason Epp
* @brief   HW initialization functions to be executed at startup used from 
*          standard startup functions provided by STM MCD Application Team/
*          STM32 Cube
*******************************************************************************
*/
#include "hw_init.h"



/*
 * @breif   Default System clock clock configuration from STM
 *          Sys clock running off PLL at 216MHz
 * @ param  none
 * @ retval none
 */
void __attribute__((weak))
SystemClockConfig(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    //enable power control clock
    __HAL_RCC_PWR_CLK_ENABLE();

    //enable voltage scaling 
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    //Enable HSE oscillator and route to PLL for High frequency system clock 
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 432;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2; 
    RCC_OscInitStruct.PLL.PLLQ = 9;

    while(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    { ; } //TODO add exception handlers and switch to if
    //activate overdrive to reach 216MHz
    while(HAL_PWREx_EnableOverDrive() != HAL_OK)
    { ; }

    // Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | 
                                   RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    while(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    { ; }
}

/*
 * @breif CPU L1_cache enable
 */
void CPU_CACHE_Enable(void)
{
    SCB_EnableICache();
    SCB_EnableDCache();
}

void HW_Init(void)
{
    //enable the CUP cache
    CPU_CACHE_Enable();
    HAL_Init();
    SystemClockConfig();
    EnableRequiredClocks();


}



