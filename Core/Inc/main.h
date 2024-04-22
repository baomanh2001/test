/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define PauseButt_Pin GPIO_PIN_13
#define PauseButt_GPIO_Port GPIOC
#define Switch1_Pin GPIO_PIN_0
#define Switch1_GPIO_Port GPIOA
#define Switch2_Pin GPIO_PIN_1
#define Switch2_GPIO_Port GPIOA
#define Switch3_Pin GPIO_PIN_2
#define Switch3_GPIO_Port GPIOA
#define Switch4_Pin GPIO_PIN_3
#define Switch4_GPIO_Port GPIOA
#define Switch5_Pin GPIO_PIN_4
#define Switch5_GPIO_Port GPIOA
#define Switch6_Pin GPIO_PIN_5
#define Switch6_GPIO_Port GPIOA
#define Switch7_Pin GPIO_PIN_6
#define Switch7_GPIO_Port GPIOA
#define Switch8_Pin GPIO_PIN_7
#define Switch8_GPIO_Port GPIOA
#define Switch9_Pin GPIO_PIN_0
#define Switch9_GPIO_Port GPIOB
#define Switch10_Pin GPIO_PIN_1
#define Switch10_GPIO_Port GPIOB
#define Switch11_Pin GPIO_PIN_10
#define Switch11_GPIO_Port GPIOB
#define Switch12_Pin GPIO_PIN_11
#define Switch12_GPIO_Port GPIOB
#define Led1_Pin GPIO_PIN_12
#define Led1_GPIO_Port GPIOB
#define Led2_Pin GPIO_PIN_13
#define Led2_GPIO_Port GPIOB
#define Led3_Pin GPIO_PIN_14
#define Led3_GPIO_Port GPIOB
#define Led4_Pin GPIO_PIN_15
#define Led4_GPIO_Port GPIOB
#define Led5_Pin GPIO_PIN_8
#define Led5_GPIO_Port GPIOA
#define Led6_Pin GPIO_PIN_9
#define Led6_GPIO_Port GPIOA
#define Led7_Pin GPIO_PIN_10
#define Led7_GPIO_Port GPIOA
#define Led8_Pin GPIO_PIN_11
#define Led8_GPIO_Port GPIOA
#define Led9_Pin GPIO_PIN_12
#define Led9_GPIO_Port GPIOA
#define Led10_Pin GPIO_PIN_15
#define Led10_GPIO_Port GPIOA
#define Led11_Pin GPIO_PIN_3
#define Led11_GPIO_Port GPIOB
#define Led12_Pin GPIO_PIN_4
#define Led12_GPIO_Port GPIOB
#define LedWait_Pin GPIO_PIN_5
#define LedWait_GPIO_Port GPIOB
#define LedStop_Pin GPIO_PIN_6
#define LedStop_GPIO_Port GPIOB
#define StartButt_Pin GPIO_PIN_8
#define StartButt_GPIO_Port GPIOB
#define StartButt_EXTI_IRQn EXTI9_5_IRQn
#define StopButt_Pin GPIO_PIN_9
#define StopButt_GPIO_Port GPIOB
#define StopButt_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
