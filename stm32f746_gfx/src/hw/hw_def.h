/*
 * hw_def.h
 *
 *  Created on: 2019. 6. 14.
 *      Author: HanCheol Cho
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "def.h"
#include "bsp.h"



#define _USE_HW_MICROS
#define _USE_HW_MILLIS
#define _USE_HW_DELAY
#define _USE_HW_SDRAM
#define _USE_HW_RTOS


#define _USE_HW_SD
#define      HW_USE_CMDIF_SD        1

#define _USE_HW_FATFS


#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_UART
#define      HW_UART_MAX_CH         1


#define _USE_HW_I2C
#define      HW_I2C_MAX_CH          1
#define      HW_USE_CMDIF_I2C       1


#define _USE_HW_TS
#define      HW_TS_MAX_TOUCH        5



#define _USE_HW_CMDIF
#define      HW_CMDIF_LIST_MAX              16
#define      HW_CMDIF_CMD_STR_MAX           16
#define      HW_CMDIF_CMD_BUF_LENGTH        128



#define _HW_DEF_SDRAM_ADDR_START              0xC0000000
#define _HW_DEF_SDRAM_ADDR_LENGTH             0x00800000
#define _HW_DEF_SDRAM_ADDR_END                (_HW_DEF_SDRAM_ADDR_START + _HW_DEF_SDRAM_ADDR_LENGTH)


#define _HW_DEF_SDRAM_HEAP_START              (_HW_DEF_SDRAM_ADDR_START + 2*1024*1024)
#define _HW_DEF_SDRAM_HEAP_LENGTH             (6*1024*1024)


#endif /* SRC_HW_HW_DEF_H_ */
