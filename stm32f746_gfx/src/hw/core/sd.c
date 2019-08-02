/*
 * sd.c
 *
 *  Created on: 2019. 8. 1.
 *      Author: Baram
 */




#include "sd.h"
#include "cmdif.h"

#ifdef _USE_HW_SD





//-- Internal Variables
//
static bool is_init = false;
static SD_HandleTypeDef uSdHandle;
static err_code_t err_code;


//-- External Variables
//


//-- Internal Functions
//
static void sdInitDetectedPin(void);
static void sdInitHw(void);

#if HW_USE_CMDIF_SD == 1
void sdCmdifInit(void);
void sdCmdif(void);
#endif



//-- External Functions
//




bool sdInit(void)
{
  bool ret = true;


  err_code = OK;

  /* uSD device interface configuration */
  uSdHandle.Instance = SDMMC1;

  uSdHandle.Init.ClockEdge           = SDMMC_CLOCK_EDGE_RISING;
  uSdHandle.Init.ClockBypass         = SDMMC_CLOCK_BYPASS_DISABLE;
  uSdHandle.Init.ClockPowerSave      = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  uSdHandle.Init.BusWide             = SDMMC_BUS_WIDE_1B;
  uSdHandle.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  uSdHandle.Init.ClockDiv            = SDMMC_TRANSFER_CLK_DIV;


  sdInitDetectedPin();


  if (sdIsDetected() == false)
  {
    return false;
  }

  sdInitHw();


  if(HAL_SD_Init(&uSdHandle) != HAL_OK)
  {
    return false;
  }

  /* Enable wide operation */
  if(HAL_SD_ConfigWideBusOperation(&uSdHandle, SDMMC_BUS_WIDE_4B) != HAL_OK)
  {
    ret = false;
  }

  is_init = ret;



#if HW_USE_CMDIF_SD == 1
  static bool is_cmd_init = false;

  if (is_cmd_init == false)
  {
    sdCmdifInit();
    is_cmd_init = true;
  }
#endif

  return is_init;
}

void sdInitHw(void)
{
  GPIO_InitTypeDef gpio_init_structure;


  /* Enable SDIO clock */
  __HAL_RCC_SDMMC1_CLK_ENABLE();

  /* Enable GPIOs clock */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /* Common GPIO configuration */
  gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
  gpio_init_structure.Pull      = GPIO_NOPULL;
  gpio_init_structure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
  gpio_init_structure.Alternate = GPIO_AF12_SDMMC1;

  /* GPIOC configuration */
  gpio_init_structure.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12;

  HAL_GPIO_Init(GPIOC, &gpio_init_structure);

  /* GPIOD configuration */
  gpio_init_structure.Pin = GPIO_PIN_2;
  HAL_GPIO_Init(GPIOD, &gpio_init_structure);

  /* NVIC configuration for SDIO interrupts */
  HAL_NVIC_SetPriority(SDMMC1_IRQn, 0x0E, 0);
  HAL_NVIC_EnableIRQ(SDMMC1_IRQn);
}


bool sdReadBlocks(uint32_t block_addr, uint8_t *p_data, uint32_t num_of_blocks, uint32_t timeout_ms)
{
  bool ret = false;

  if(HAL_SD_ReadBlocks(&uSdHandle, (uint8_t *)p_data, block_addr, num_of_blocks, timeout_ms) == HAL_OK)
  {
    ret = true;
  }

  return ret;
}

bool sdWriteBlocks(uint32_t block_addr, uint8_t *p_data, uint32_t num_of_blocks, uint32_t timeout_ms)
{
  bool ret = false;


  if(HAL_SD_WriteBlocks(&uSdHandle, (uint8_t *)p_data, block_addr, num_of_blocks, timeout_ms) == HAL_OK)
  {
    ret = true;
  }

  return ret;
}

bool sdEraseBlocks(uint32_t start_addr, uint32_t end_addr)
{
  bool ret = false;


  if(HAL_SD_Erase(&uSdHandle, start_addr, end_addr) == HAL_OK)
  {
    ret = true;
  }

  return ret;
}

bool sdIsBusy(void)
{
  bool is_busy;


  if (HAL_SD_GetCardState(&uSdHandle) == HAL_SD_CARD_TRANSFER )
  {
    is_busy = false;
  }
  else
  {
    is_busy = true;
  }

  return is_busy;
}

bool sdIsDetected(void)
{
  bool ret = false;


  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
  {
    ret = true;
  }

  return ret;
}

bool sdGetInfo(sd_info_t *p_info)
{
  bool ret = false;
  sd_info_t *p_sd_info = (sd_info_t *)p_info;

  HAL_SD_CardInfoTypeDef card_info;


  if (is_init == true)
  {
    HAL_SD_GetCardInfo(&uSdHandle, &card_info);

    p_sd_info->card_type          = card_info.CardType;
    p_sd_info->card_version       = card_info.CardVersion;
    p_sd_info->card_class         = card_info.Class;
    p_sd_info->rel_card_Add       = card_info.RelCardAdd;
    p_sd_info->block_numbers      = card_info.BlockNbr;
    p_sd_info->block_size         = card_info.BlockSize;
    p_sd_info->log_block_numbers  = card_info.LogBlockNbr;
    p_sd_info->log_block_size     = card_info.LogBlockSize;
    p_sd_info->card_size          =  (uint32_t)((uint64_t)p_sd_info->block_numbers * (uint64_t)p_sd_info->block_size / (uint64_t)1024 / (uint64_t)1024);
    ret = true;
  }


  return ret;
}


void sdInitDetectedPin(void)
{
  GPIO_InitTypeDef  gpio_init_structure;

  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* GPIO configuration in input for uSD_Detect signal */
  gpio_init_structure.Pin       = GPIO_PIN_13;
  gpio_init_structure.Mode      = GPIO_MODE_INPUT;
  gpio_init_structure.Pull      = GPIO_NOPULL;
  gpio_init_structure.Speed     = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOC, &gpio_init_structure);
}


void SDMMC1_IRQHandler(void)
{
  HAL_SD_IRQHandler(&uSdHandle);
}


#if HW_USE_CMDIF_SD == 1
void sdCmdifInit(void)
{
  cmdifAdd("sd", sdCmdif);
}

void sdCmdif(void)
{
  bool ret = true;
  sd_info_t sd_info;


  if (cmdifGetParamCnt() == 1 && cmdifHasString("info", 0) == true)
  {
    cmdifPrintf("sd init      : %d\n", is_init);
    cmdifPrintf("sd connected : %d\n", sdIsDetected());

    if (is_init == true)
    {
      if (sdGetInfo(&sd_info) == true)
      {
        cmdifPrintf("  card_type            : %d\n", sd_info.card_type);
        cmdifPrintf("  card_version         : %d\n", sd_info.card_version);
        cmdifPrintf("  card_class           : %d\n", sd_info.card_class);
        cmdifPrintf("  rel_card_Add         : %d\n", sd_info.rel_card_Add);
        cmdifPrintf("  block_numbers        : %d\n", sd_info.block_numbers);
        cmdifPrintf("  block_size           : %d\n", sd_info.block_size);
        cmdifPrintf("  log_block_numbers    : %d\n", sd_info.log_block_numbers);
        cmdifPrintf("  log_block_size       : %d\n", sd_info.log_block_size);
        cmdifPrintf("  card_size            : %d MB, %d.%d GB\n", sd_info.card_size, sd_info.card_size/1024, ((sd_info.card_size * 10)/1024) % 10);
      }
    }
  }
  else
  {
    ret = false;
  }

  if (ret == false)
  {
    cmdifPrintf( "sd info \n");
  }
}
#endif /* _USE_HW_CMDIF_SD */

#endif /* _USE_HW_SD */
