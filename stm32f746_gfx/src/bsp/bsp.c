/*
 * bsp.c
 *
 *  Created on: 2019. 6. 14.
 *      Author: HanCheol Cho
 */




#include "bsp.h"
#include "uart.h"
#include "rtos.h"
#include "led.h"


static void SystemClock_Config(void);



void bspInit(void)
{
  HAL_Init();


  SystemClock_Config();

  rtosInit();

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOK_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
}

void bspDeinit(void)
{
  uint32_t i;



  for (i=0; i<5; i++)
  {
    ledToggle(5);
    delay(50);
  }
  ledOff(5);
}


void bspInitUSB(void)
{
}

int __io_putchar(int ch)
{
  //ITM_SendChar(ch);
  uartWrite(_DEF_UART1, (uint8_t *)&ch, 1);

  return 1;
}

#if 0
static portBASE_TYPE IdleTaskHook(void* p)
{
  if ((int)p) //idle task sched out
  {
      //touchgfx::HAL::getInstance()->setMCUActive(true);
  }
  else //idle task sched in
  {
      //touchgfx::HAL::getInstance()->setMCUActive(false);
  }
  return pdTRUE;
}

void vApplicationStackOverflowHook(xTaskHandle xTask,
                                   signed portCHAR* pcTaskName)
{
    while (1);
}

void vApplicationMallocFailedHook(xTaskHandle xTask,
                                  signed portCHAR* pcTaskName)
{
    while (1);
}

void vApplicationIdleHook(void)
{
    // Set task tag in order to have the "IdleTaskHook" function called when the idle task is
    // switched in/out. Used solely for measuring MCU load, and can be removed if MCU load
    // readout is not needed.
    vTaskSetApplicationTaskTag(NULL, IdleTaskHook);
}
#endif



void Error_Handler(void)
{
  while(1)
  {

  }
}


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;

  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  /* Activate the OverDrive to reach the 216 MHz Frequency */
  ret = HAL_PWREx_EnableOverDrive();
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
}
