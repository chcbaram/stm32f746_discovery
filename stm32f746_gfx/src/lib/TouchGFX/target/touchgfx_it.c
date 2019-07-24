
#include "hw.h"

#include <stdbool.h>

#include <cmsis_os.h>


static volatile int overrunCnt;

extern LTDC_HandleTypeDef hltdc;
extern DMA2D_HandleTypeDef hdma2d;
extern struct HwJPEG_Context_s HwJPEG_Context;




void DMA2D_IRQHandler(void)
{
  HAL_DMA2D_IRQHandler(&hdma2d);
}

void LTDC_ER_IRQHandler(void)
{
  if (LTDC->ISR & 2)
  {
    LTDC->ICR = 2;
    overrunCnt++;
  }
}


void LTDC_IRQHandler(void)
{
  HAL_LTDC_IRQHandler(&hltdc);
}
