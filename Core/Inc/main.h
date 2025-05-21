/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DB0_Pin GPIO_PIN_0
#define DB0_GPIO_Port GPIOC
#define DB1_Pin GPIO_PIN_1
#define DB1_GPIO_Port GPIOC
#define DB2_Pin GPIO_PIN_2
#define DB2_GPIO_Port GPIOC
#define DB3_Pin GPIO_PIN_3
#define DB3_GPIO_Port GPIOC
#define MODE_SW_Pin GPIO_PIN_1
#define MODE_SW_GPIO_Port GPIOA
#define UP_SW_Pin GPIO_PIN_2
#define UP_SW_GPIO_Port GPIOA
#define DN_SW_Pin GPIO_PIN_3
#define DN_SW_GPIO_Port GPIOA
#define SET_SW_Pin GPIO_PIN_4
#define SET_SW_GPIO_Port GPIOA
#define EncoderSW_Pin GPIO_PIN_5
#define EncoderSW_GPIO_Port GPIOA
#define EncoderA_Pin GPIO_PIN_6
#define EncoderA_GPIO_Port GPIOA
#define EncoderA_EXTI_IRQn EXTI9_5_IRQn
#define EncoderB_Pin GPIO_PIN_7
#define EncoderB_GPIO_Port GPIOA
#define DB4_Pin GPIO_PIN_4
#define DB4_GPIO_Port GPIOC
#define DB5_Pin GPIO_PIN_5
#define DB5_GPIO_Port GPIOC
#define LED0_Pin GPIO_PIN_10
#define LED0_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_11
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_12
#define LED2_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_13
#define LED3_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_14
#define LED4_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_15
#define LED5_GPIO_Port GPIOB
#define DB6_Pin GPIO_PIN_6
#define DB6_GPIO_Port GPIOC
#define DB7_Pin GPIO_PIN_7
#define DB7_GPIO_Port GPIOC
#define RS_Pin GPIO_PIN_8
#define RS_GPIO_Port GPIOC
#define RW_Pin GPIO_PIN_9
#define RW_GPIO_Port GPIOC
#define Buzzer_Pin GPIO_PIN_8
#define Buzzer_GPIO_Port GPIOA
#define Display_Dir_Pin GPIO_PIN_11
#define Display_Dir_GPIO_Port GPIOA
#define E_Pin GPIO_PIN_10
#define E_GPIO_Port GPIOC
#define CS2_Pin GPIO_PIN_11
#define CS2_GPIO_Port GPIOC
#define CS1_Pin GPIO_PIN_12
#define CS1_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
