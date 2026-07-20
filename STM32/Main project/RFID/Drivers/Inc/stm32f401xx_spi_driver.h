/*
 * stm32f401xx_spi_driver.h
 *
 *  Created on: Feb 27, 2026
 *      Author: hafna
 */

#ifndef INC_STM32F401XX_SPI_DRIVER_H_
#define INC_STM32F401XX_SPI_DRIVER_H_

#include "stm32f401xx.h"

/*
 * Configuration structure for SPIx peripheral
 */
typedef struct
{
    uint8_t SPI_DeviceMode;    // Master or Slave
    uint8_t SPI_BusConfig;     // Full-duplex, half-duplex, simplex
    uint8_t SPI_SclkSpeed;     // Clock speed (prescaler)
    uint8_t SPI_DFF;           // Data frame format (8 or 16 bit)
    uint8_t SPI_CPOL;          // Clock polarity
    uint8_t SPI_CPHA;          // Clock phase
    uint8_t SPI_SSM;           // Software slave management
} SPI_Config_t;

typedef struct
{
    SPI_Regdef_t  *pSPIx;       // Pointer to SPI peripheral
    SPI_Config_t  SPIConfig;   // Configuration settings


} SPI_Handle_t;


/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER    1
#define SPI_DEVICE_MODE_SLAVE     0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD         1  // Full duplex
#define SPI_BUS_CONFIG_HD         2  // Half duplex
#define SPI_BUS_CONFIG_SIMPLEX_RX 3  // Simplex RX only

/*
 * @SPI_SclkSpeed - Prescaler values
 */
#define SPI_SCLK_SPEED_DIV2       0
#define SPI_SCLK_SPEED_DIV4       1
#define SPI_SCLK_SPEED_DIV8       2
#define SPI_SCLK_SPEED_DIV16      3
#define SPI_SCLK_SPEED_DIV32      4
#define SPI_SCLK_SPEED_DIV64      5
#define SPI_SCLK_SPEED_DIV128     6
#define SPI_SCLK_SPEED_DIV256     7

/*
 * @SPI_DFF - Data Frame Format
 */
#define SPI_DFF_8BITS             0
#define SPI_DFF_16BITS            1

/*
 * @SPI_CPOL
 */
#define SPI_CPOL_LOW              0
#define SPI_CPOL_HIGH             1

/*
 * @SPI_CPHA
 */
#define SPI_CPHA_LOW              0  // First clock edge
#define SPI_CPHA_HIGH             1  // Second clock edge

/*
 * @SPI_SSM - Software Slave Management
 */
#define SPI_SSM_DI                0  // Hardware NSS
#define SPI_SSM_EN                1  // Software NSS


#define SPI_TXE_FLAG		(1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG		(1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG		(1 << SPI_SR_BSY)

/******************************************
 *                 APIs
 ******************************************/

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClockControl(SPI_Regdef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_Regdef_t *pSPIx);

/*
 * Data Send and Receive (Blocking/Polling)
 */
void SPI_SendData(SPI_Regdef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_Regdef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);



#endif /* INC_STM32F401XX_SPI_DRIVER_H_ */
