/*
 * qspi.h
 *
 *  Created on: 2019. 7. 24.
 *      Author: Baram
 */

#ifndef SRC_COMMON_HW_INCLUDE_QSPI_H_
#define SRC_COMMON_HW_INCLUDE_QSPI_H_


#ifdef __cplusplus
 extern "C" {
#endif


#include "hw_def.h"



typedef struct {
 uint32_t FlashSize;          /*!< Size of the flash */
 uint32_t EraseSectorSize;    /*!< Size of sectors for the erase operation */
 uint32_t EraseSectorsNumber; /*!< Number of sectors for the erase operation */
 uint32_t ProgPageSize;       /*!< Size of pages for the program operation */
 uint32_t ProgPagesNumber;    /*!< Number of pages for the program operation */
} qspi_info_t;


bool qspiInit(void);


bool qspiRead(uint32_t addr, uint8_t *p_data, uint32_t length);
bool qspiWrtie(uint32_t addr, uint8_t *p_data, uint32_t length);
bool qspiEraseBlock(uint32_t block_addr);
bool qspiEraseChip(void);
bool qspiGetStatus(void);
bool qspiGetInfo(qspi_info_t* p_info);
bool qspiEnableMemoryMappedMode(void);

#ifdef __cplusplus
}
#endif



#endif /* SRC_COMMON_HW_INCLUDE_QSPI_H_ */
