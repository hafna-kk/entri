/*
 * stm32f401xx_spi_driver.c
 *
 *  Created on: May 4, 2026
 *      Author: hafna
 */

#include "stm32f401xx.h"

#include "stm32f401xx_spi_driver.h"

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClockControl(SPI_Regdef_t *pSPIx, uint8_t EnorDi){

	 if (EnorDi == ENABLE)
	    {
	        if (pSPIx == SPI1)
	        {
	            SPI1_PCLK_EN();
	        }
	        else if (pSPIx == SPI2)
	        {
	        	SPI2_PCLK_EN();
	        }
	        else if (pSPIx == SPI3)
	        {
	        	 SPI3_PCLK_EN();
	        }



	    }
	    else
	    {
	        // Similar structure for DISABLE
	    	if (pSPIx == SPI1)
	    	{
	    		  SPI1_PCLK_DI();
	    	}
	    	else if (pSPIx == SPI2)
	    	{
	    		   SPI2_PCLK_DI();
	    	}
	    	else if (pSPIx == SPI3)
	    	{
	    			SPI3_PCLK_DI();
	    	}


	    }
}


void SPI_Init(SPI_Handle_t *pSPIHandle){

		// Enable peripheral clock
	    SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

	    uint32_t tempreg=0;

	    tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR; //configuring device mode

	    //  Configure bus config
	        if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	        {
	            // Full duplex: BIDIMODE = 0
	            tempreg &= ~(1 << SPI_CR1_BIDIMOOE);
	        }
	        else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	        {
	            // Half duplex: BIDIMODE = 1
	            tempreg |= (1 << SPI_CR1_BIDIMOOE);
	        }
	        else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX)
	        {
	            // Simplex RX: BIDIMODE = 0, RXONLY = 1
	            tempreg &= ~(1 << SPI_CR1_BIDIMOOE);
	            tempreg |= (1 << SPI_CR1_RXONLY);
	        }

	        tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed <<  SPI_CR1_BR; //configuring clock speed

	        //  Configure DFF (data frame format)
	           tempreg |= (pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF);

	           //  Configure CPOL
	           tempreg |= (pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL);

	           //  Configure CPHA
	           tempreg |= (pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA);

	           // Configure SSM
	           tempreg |= (pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM);

	           // Write to CR1 register
	           pSPIHandle->pSPIx->CR1 = tempreg;




}
void SPI_DeInit(SPI_Regdef_t *pSPIx)
{
    if(pSPIx == SPI1)
    {
        SPI1_REG_RESET();
    }
    else if(pSPIx == SPI2)
    {
        SPI2_REG_RESET();
    }
    else if(pSPIx == SPI3)
    {
        SPI3_REG_RESET();
    }
    else if(pSPIx == SPI4)
    {
        SPI4_REG_RESET();
    }
}

// Get flag status from SR register
uint8_t SPI_GetFlagStatus(SPI_Regdef_t *pSPIx, uint32_t FlagName)
	{
	    if (pSPIx->SR & FlagName)
	    {
	        return FLAG_SET;
	    }
	    return FLAG_RESET;
	}

/*
 * Data Send and Receive (Blocking/Polling)
 */
void SPI_SendData(SPI_Regdef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len){

	 while (Len > 0)
	    {
	        // 1. Wait until TXE is set (TX buffer empty)
	        while (SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG)==FLAG_RESET);

	        // 2. Check DFF bit in CR1
	        if (pSPIx->CR1 & (1 << SPI_CR1_DFF))
	        {
	            // 16-bit DFF
	            pSPIx->DR = *((uint16_t*)pTxBuffer);
	            Len --;
	            Len --;
	            (uint16_t*)pTxBuffer++;
	        }
	        else
	        {
	            // 8-bit DFF
	            pSPIx->DR = *pTxBuffer;
	            Len--;
	            pTxBuffer++;
	        }
	    }

}
void SPI_ReceiveData(SPI_Regdef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len){

	while (Len > 0)
		    {
		        // 1. Wait until TXE is set (RX buffer empty)
		        while (SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG)==FLAG_RESET);

		        // 2. Check DFF bit in CR1
		        if (pSPIx->CR1 & (1 << SPI_CR1_DFF))
		        {
		            // 16-bit DFF
		             *((uint16_t*)pRxBuffer)= pSPIx->DR ;
		            Len --;
		            Len --;
		            (uint16_t*)pRxBuffer++;
		        }
		        else
		        {
		            // 8-bit DFF
		            *pRxBuffer = pSPIx->DR;
		            Len--;
		            pRxBuffer++;
		        }
		    }
}

void SPI_SSIConfig(SPI_Regdef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SSI);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
    }
}



void SPI_PeripheralControl(SPI_Regdef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SPE);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
    }
}
