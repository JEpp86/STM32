/**
*******************************************************************************
* @file    hw_config.h
* @author  Jason Epp
* @brief   HW configuration mapping in one place for portability/tracibility
*          MSP function overrides, 
*          Application Team/STM32 Cube
*******************************************************************************
*/

#ifndef HW_CONFIG_H
#define HW_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

//ST Driver includes
#include "stm32f7xx_hal.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal_conf.h"


//must be the same order as the pin config
typedef enum {
	//Digital 'arduino' header pins
	D0  = 0,  	//RX
	D1  = 1,	//TX
	D2  = 2,
	D3  = 3, 	//PWM 	
	D9  = 9,	//PWM
	D13 = 13,	//SCK	
	D14 = 14, 	//SDA
	D15 = 15,	//SCL
	PIN_NUM //Pin Index
}PinMap;


//Pin deifinitions
#define D0_Pin GPIO_PIN_7 		//RX
#define D0_GPIO_Port GPIOC
#define D1_Pin GPIO_PIN_6		//TX
#define D1_GPIO_Port GPIOC
#define D3_Pin GPIO_PIN_4 		//PWM
#define D3_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_0 		//PWM CS
#define D5_GPIO_Port GPIOI
#define D7_Pin GPIO_PIN_3		//General
#define D7_GPIO_Port GPIOI
#define D8_Pin GPIO_PIN_2		//General
#define D8_GPIO_Port GPIOI
#define D9_Pin GPIO_PIN_15 		//PWM
#define D9_GPIO_Port GPIOA
#define D10_Pin GPIO_PIN_8 		//PWM
#define D10_GPIO_Port GPIOA
#define D13_Pin GPIO_PIN_15     //SCK
#define D13_GPIO_Port GPIOI
#define D14_Pin GPIO_PIN_9 		//SDA
#define D14_GPIO_Port GPIOB
#define D15_Pin GPIO_PIN_8		//SCL
#define D15_GPIO_Port GPIOB

typedef struct
{
	GPIO_TypeDef * pin;
	GPIO_InitTypeDef config;
}GPIO_CfgTypeDef;


//periferal configuration functions
GPIO_CfgTypeDef * GetPinFromMap(PinMap pin);
void EnableRequiredClocks(void);


#ifdef __cplusplus
}
#endif

#endif /* HW_INIT_H */