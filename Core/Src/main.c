/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
uint16_t countSecond = 0, countSecond_limit = 30;
uint16_t countSecond_WaitLimit = 360;
//uint16_t countSecond = 0, countSecond_limit = 5;
//uint16_t countSecond_WaitLimit = 10;
uint8_t countMili = 0, countMili_limit = 2;
uint8_t flagSkip = 0, flagChange = 0, flagFirstStop = 0;
uint8_t flagTim3 = 0, flagTim2 = 1;
uint8_t relay1 = 0, relay2 = 0, relay3 = 0, relay4 = 0;
enum State {
	stop,
	switch1,
	switch2,
	switch3,
	switch4,
	switch5,
	switch6,
	switch7,
	switch8,
	switch9,
	switch10,
	switch11,
	switch12,
	wait
} state = stop;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim2) {
		countSecond += 1;
//		if(countSecond %2 == 0)
//		HAL_GPIO_TogglePin(Switch6_GPIO_Port, Switch6_Pin);
	} else if (htim == &htim3) {
		countMili += 1;
//	HAL_GPIO_TogglePin(Switch4_GPIO_Port, Switch4_Pin);
	}
}
void RstAll() {
	countSecond = 0;
	countMili = 0;
	relay1 = 0;
	relay2 = 0;
	relay3 = 0;


	HAL_GPIO_WritePin(LedWait_GPIO_Port, LedWait_Pin, 0);
	HAL_GPIO_WritePin(Switch1_GPIO_Port, Switch1_Pin, 0);
	HAL_GPIO_WritePin(Switch2_GPIO_Port, Switch2_Pin, 0);
	HAL_GPIO_WritePin(Switch3_GPIO_Port, Switch3_Pin, 0);
	HAL_GPIO_WritePin(Switch4_GPIO_Port, Switch4_Pin, 0);
	HAL_GPIO_WritePin(Switch5_GPIO_Port, Switch5_Pin, 0);
	HAL_GPIO_WritePin(Switch6_GPIO_Port, Switch6_Pin, 0);
	HAL_GPIO_WritePin(Switch7_GPIO_Port, Switch7_Pin, 0);
	HAL_GPIO_WritePin(Switch8_GPIO_Port, Switch8_Pin, 0);
	HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, 0);
	HAL_GPIO_WritePin(Led2_GPIO_Port, Led2_Pin, 0);
	HAL_GPIO_WritePin(Led3_GPIO_Port, Led3_Pin, 0);
	HAL_GPIO_WritePin(Led4_GPIO_Port, Led4_Pin, 0);
	HAL_GPIO_WritePin(Led5_GPIO_Port, Led5_Pin, 0);
	HAL_GPIO_WritePin(Led6_GPIO_Port, Led6_Pin, 0);
	HAL_GPIO_WritePin(Led7_GPIO_Port, Led7_Pin, 0);
	HAL_GPIO_WritePin(Led8_GPIO_Port, Led8_Pin, 0);
	HAL_GPIO_WritePin(Led9_GPIO_Port, Led9_Pin, 0);
	HAL_GPIO_WritePin(Led10_GPIO_Port, Led10_Pin, 0);
	HAL_GPIO_WritePin(Led11_GPIO_Port, Led11_Pin, 0);
	HAL_GPIO_WritePin(Led12_GPIO_Port, Led12_Pin, 0);

}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == StartButt_Pin) {
		flagChange = 1;
		state = switch1;
		__HAL_GPIO_EXTI_CLEAR_IT(StartButt_Pin);
		EXTI->PR = StartButt_Pin;
//		HAL_Delay(100);
	}

	else if (GPIO_Pin == StopButt_Pin) {
		flagChange = 1;
		state = stop;
//		HAL_Delay(10);
		__HAL_GPIO_EXTI_CLEAR_IT(StopButt_Pin);
		EXTI->PR = StopButt_Pin;
	}
//	HAL_Delay(10);
//	if (GPIO_Pin == SkipButt_Pin) {
//		flagSkip = 1;
//	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	RstAll();
	HAL_GPIO_WritePin(LedWait_GPIO_Port, LedWait_Pin, 0);

//					__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
//					HAL_TIM_Base_Start_IT(&htim2);
//									__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
//									HAL_TIM_Base_Start_IT(&htim3);

//					HAL_GPIO_WritePin(Switch4_GPIO_Port, Switch4_Pin, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

//			HAL_GPIO_WritePin(Switch1_GPIO_Port, Switch1_Pin, 1);
//					if(countSecond  >= 5){
////						HAL_GPIO_WritePin(Switch4_GPIO_Port, Switch4_Pin, 0);
////					HAL_GPIO_TogglePin(Switch6_GPIO_Port, Switch6_Pin);
//					countSecond = 0;
//					}
		if (HAL_GPIO_ReadPin(PauseButt_GPIO_Port, PauseButt_Pin) == 0) {
			if (flagFirstStop == 0) {
				flagFirstStop = 1;
				HAL_TIM_Base_Stop_IT(&htim3);
				HAL_TIM_Base_Stop_IT(&htim2);
//				HAL_GPIO_TogglePin(LedWait_GPIO_Port, LedWait_Pin);
			}
		} else {
			if (flagFirstStop == 1) {
//				HAL_GPIO_TogglePin(LedWait_GPIO_Port, LedWait_Pin);
				flagFirstStop = 0;
				if (flagTim3)
					HAL_TIM_Base_Start_IT(&htim3);
				if (flagTim2)
					HAL_TIM_Base_Start_IT(&htim2);
			}
			switch (state) {
			case stop:
				if (flagChange) {
					HAL_TIM_Base_Stop_IT(&htim3);
					flagTim3 = 0;
					HAL_TIM_Base_Stop_IT(&htim2);
					flagTim2 = 0;
					RstAll();
					flagChange = 0;
				}
				break;
			case switch1:
				if (flagChange) {
					countMili = 0;
					RstAll();
					HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, 1);
					HAL_GPIO_WritePin(Switch1_GPIO_Port, Switch1_Pin, 1);
					relay1 = 1;
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						relay1 = 0;
						HAL_GPIO_WritePin(Switch1_GPIO_Port, Switch1_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch2;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch2:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led2_GPIO_Port, Led2_Pin, 1);
					HAL_GPIO_WritePin(Switch2_GPIO_Port, Switch2_Pin, 1);
					relay2 = 1;
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch2_GPIO_Port, Switch2_Pin, 0);
						relay2 = 0;
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch3;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch3:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led3_GPIO_Port, Led3_Pin, 1);
					HAL_GPIO_WritePin(Switch3_GPIO_Port, Switch3_Pin, 1);
					relay3 = 1;
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch3_GPIO_Port, Switch3_Pin, 0);
						relay3 = 0;
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch4;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch4:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led4_GPIO_Port, Led4_Pin, 1);
					HAL_GPIO_WritePin(Switch4_GPIO_Port, Switch4_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch4_GPIO_Port, Switch4_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch5;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch5:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led5_GPIO_Port, Led5_Pin, 1);
					HAL_GPIO_WritePin(Switch5_GPIO_Port, Switch5_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch5_GPIO_Port, Switch5_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch6;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch6:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led6_GPIO_Port, Led6_Pin, 1);
					HAL_GPIO_WritePin(Switch6_GPIO_Port, Switch6_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch6_GPIO_Port, Switch6_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch7;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch7:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led7_GPIO_Port, Led7_Pin, 1);
					HAL_GPIO_WritePin(Switch7_GPIO_Port, Switch7_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch7_GPIO_Port, Switch7_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch8;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch8:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led8_GPIO_Port, Led8_Pin, 1);
					HAL_GPIO_WritePin(Switch8_GPIO_Port, Switch8_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch8_GPIO_Port, Switch8_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch9;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch9:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led9_GPIO_Port, Led9_Pin, 1);
					HAL_GPIO_WritePin(Switch9_GPIO_Port, Switch9_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch9_GPIO_Port, Switch9_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch10;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			case switch10:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led10_GPIO_Port, Led10_Pin, 1);
					HAL_GPIO_WritePin(Switch10_GPIO_Port, Switch10_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch10_GPIO_Port, Switch10_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch11;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;
			case switch11:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led11_GPIO_Port, Led11_Pin, 1);
					HAL_GPIO_WritePin(Switch11_GPIO_Port, Switch11_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch11_GPIO_Port, Switch11_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = switch12;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;
			case switch12:
				if (flagChange) {
					countMili = 0;
					HAL_GPIO_WritePin(Led12_GPIO_Port, Led12_Pin, 1);
					HAL_GPIO_WritePin(Switch12_GPIO_Port, Switch12_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim3);
					flagTim3 = 1;
					flagChange = 0;
				} else {
					if (countMili >= countMili_limit) {
						HAL_GPIO_WritePin(Switch12_GPIO_Port, Switch12_Pin, 0);
						HAL_TIM_Base_Stop_IT(&htim3);
						flagTim3 = 0;
						__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
						HAL_TIM_Base_Start_IT(&htim2);
						flagTim2 = 1;
						countMili = 0;
					}
					if (countSecond >= countSecond_limit) {
						state = wait;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;
			case wait:
				if (flagChange) {
					countSecond = 0;
					HAL_GPIO_WritePin(LedWait_GPIO_Port, LedWait_Pin, 1);
					__HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
					HAL_TIM_Base_Start_IT(&htim2);
					flagTim2 = 1;
					flagChange = 0;
				} else {
					if (countSecond >= countSecond_WaitLimit) {
						state = switch1;
						flagChange = 1;
						countSecond = 0;
						HAL_TIM_Base_Stop_IT(&htim2);
						flagTim2 = 0;

					}
				}
				break;

			}
		}
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 7999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 63;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 62499;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Switch1_Pin|Switch2_Pin|Switch3_Pin|Switch4_Pin
                          |Switch5_Pin|Switch6_Pin|Switch7_Pin|Switch8_Pin
                          |Led5_Pin|Led6_Pin|Led7_Pin|Led8_Pin
                          |Led9_Pin|Led10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Switch9_Pin|Switch10_Pin|Switch11_Pin|Switch12_Pin
                          |Led1_Pin|Led2_Pin|Led3_Pin|Led4_Pin
                          |Led11_Pin|Led12_Pin|LedWait_Pin|LedStop_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PauseButt_Pin */
  GPIO_InitStruct.Pin = PauseButt_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(PauseButt_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Switch1_Pin Switch2_Pin Switch3_Pin Switch4_Pin
                           Switch5_Pin Switch6_Pin Switch7_Pin Switch8_Pin
                           Led5_Pin Led6_Pin Led7_Pin Led8_Pin
                           Led9_Pin Led10_Pin */
  GPIO_InitStruct.Pin = Switch1_Pin|Switch2_Pin|Switch3_Pin|Switch4_Pin
                          |Switch5_Pin|Switch6_Pin|Switch7_Pin|Switch8_Pin
                          |Led5_Pin|Led6_Pin|Led7_Pin|Led8_Pin
                          |Led9_Pin|Led10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Switch9_Pin Switch10_Pin Switch11_Pin Switch12_Pin
                           Led1_Pin Led2_Pin Led3_Pin Led4_Pin
                           Led11_Pin Led12_Pin LedWait_Pin LedStop_Pin */
  GPIO_InitStruct.Pin = Switch9_Pin|Switch10_Pin|Switch11_Pin|Switch12_Pin
                          |Led1_Pin|Led2_Pin|Led3_Pin|Led4_Pin
                          |Led11_Pin|Led12_Pin|LedWait_Pin|LedStop_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : StartButt_Pin */
  GPIO_InitStruct.Pin = StartButt_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(StartButt_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : StopButt_Pin */
  GPIO_InitStruct.Pin = StopButt_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(StopButt_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
