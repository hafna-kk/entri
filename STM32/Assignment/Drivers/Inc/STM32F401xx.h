/*
 * STM32F401xx.h
 *
 *  Created on: Jan 17, 2026
 *      Author: hafna
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include <stddef.h>
#include <stdint.h>

#define __vol  volatile
#define ENABLE  			1
#define DISABLE  			0
/*
 * Memory base addresses
 * */
#define FLASH_BASEADDR   	 0x08000000U
#define ROM_BASEADDR     	 0x1FFF0000U
#define SRAM_BASEADDR	 	 0x20000000U



/*
 * Peripheral bus base addresses
 * */

#define APB1_PERIBASEADDR			0x40000000U
#define APB2_PERIBASEADDR			0x40010000U
#define AHB1_PERIBASEADDR			0x40020000U
#define AHB2_PERIBASEADDR			0x50000000U



/*
 * AHB1 bus base addresses
 * */

#define GPIOA_BASEADDR					(AHB1_PERIBASEADDR+0x0000)
#define GPIOB_BASEADDR					(AHB1_PERIBASEADDR+0x0400)
#define GPIOC_BASEADDR					(AHB1_PERIBASEADDR+0x0800)
#define GPIOD_BASEADDR					(AHB1_PERIBASEADDR+0x0C00)
#define GPIOE_BASEADDR					(AHB1_PERIBASEADDR+0x1000)
#define GPIOH_BASEADDR					(AHB1_PERIBASEADDR+0x1C00)
#define CRC_BASEADDR					(AHB1_PERIBASEADDR+0x3000)
#define RCC_BASEADDR					(AHB1_PERIBASEADDR+0x3800)
#define FLASH_INTERFACE_BASEADDR		(AHB1_PERIBASEADDR+0x3C00)
#define DMA1_BASEADDR					(AHB1_PERIBASEADDR+0x6000)
#define DMA2_BASEADDR					(AHB1_PERIBASEADDR+0x6400)

/*
 * AHB2 bus base addresses
 * */


#define USB_OTG_FS_BASEADDR   			(AHB2_PERIBASEADDR + 0x0000)


/*
 * APB1 bus base addresses
 * */


#define TIM2_BASEADDR  		(APB1_PERIBASEADDR + 0x0000)
#define TIM3_BASEADDR  		(APB1_PERIBASEADDR + 0x0400)
#define TIM4_BASEADDR  		(APB1_PERIBASEADDR + 0x0800)
#define TIM5_BASEADDR  		(APB1_PERIBASEADDR + 0x0C00)
#define RTC_BASEADDR  		(APB1_PERIBASEADDR + 0x2800)
#define WWDG_BASEADDR  		(APB1_PERIBASEADDR + 0x2C00)
#define IWDG_BASEADDR  		(APB1_PERIBASEADDR + 0x3000)
#define I2S2ext_BASEADDR	(APB1_PERIBASEADDR + 0x3400)
#define SPI2_BASEADDR  		(APB1_PERIBASEADDR + 0x3800)
#define SPI3_BASEADDR  		(APB1_PERIBASEADDR + 0x3C00)
#define I2S3ext_BASEADDR	(APB1_PERIBASEADDR + 0x4000)
#define USART2_BASEADDR  		(APB1_PERIBASEADDR + 0x4400)
#define I2C1_BASEADDR  		(APB1_PERIBASEADDR + 0x5400)
#define I2C2_BASEADDR  		(APB1_PERIBASEADDR + 0x5800)
#define I2C3_BASEADDR  		(APB1_PERIBASEADDR + 0x5C00)
#define PWR_BASEADDR  		(APB1_PERIBASEADDR + 0x7000)

/*
 * APB2 bus base addresses
 * */

#define TIM1_BASEADDR  			(APB2_PERIBASEADDR + 0x0000)
#define USART1_BASEADDR  		(APB2_PERIBASEADDR + 0x1000)
#define USART6_BASEADDR  		(APB2_PERIBASEADDR + 0x1400)
#define ADC1_BASEADDR  			(APB2_PERIBASEADDR + 0x2000)
#define SDIO_BASEADDR  			(APB2_PERIBASEADDR + 0x2C00)
#define SPI1_BASEADDR  			(APB2_PERIBASEADDR + 0x3000)
#define SPI4_BASEADDR  			(APB2_PERIBASEADDR + 0x3400)
#define SYSCFG_BASEADDR  		(APB2_PERIBASEADDR + 0x3800)
#define EXTI_BASEADDR  			(APB2_PERIBASEADDR + 0x3C00)
#define TIM9_BASEADDR  			(APB2_PERIBASEADDR + 0x4000)
#define TIM10_BASEADDR  		(APB2_PERIBASEADDR + 0x4400)
#define TIM11_BASEADDR  		(APB2_PERIBASEADDR + 0x4800)

/*
 * Peripheral register definition structure for RCC
 * */

typedef struct{
	__vol uint32_t CR; 				    	//offset :0x00
	__vol uint32_t PLLCFGR;					//offset :0x04
	__vol uint32_t CFGR;					//offset :0x08
	__vol uint32_t CIR;						//offset :0x0C
	__vol uint32_t AHB1RSTR;				//offset :0x10
	__vol uint32_t AHB2RSTR;				//offset :0x14
		  uint32_t Reserved1;				//offset :0x18
		  uint32_t Reserved2;				//offset :0x1C
	__vol uint32_t APB1RSTR;				//offset :0x20
	__vol uint32_t APB2RSTR;				//offset :0x24
		  uint32_t Reserved3;				//offset :0x28
		  uint32_t Reserved4;				//offset :0x2C
	__vol uint32_t AHB1ENR;			        //offset :0x30
	__vol uint32_t AHB2ENR;				    //offset :0x34
		  uint32_t Reserved5;				//offset :0x38
		  uint32_t Reserved6;				//offset :0x3C
	__vol uint32_t  APB1ENR;				//offset :0x40
	__vol uint32_t  APB2ENR;				//offset :0x44
		  uint32_t Reserved7;				//offset :0x48
		  uint32_t Reserved8;				//offset :0x4C
	__vol uint32_t AHB1LPENR; 				//offset :0x50
	__vol uint32_t AHB2LPENR;				//offset :0x54
		  uint32_t Reserved9;				//offset :0x58
		  uint32_t Reserved10;				//offset :0x5C
    __vol uint32_t APB1LPENR;				//offset :0x60
    __vol uint32_t APB2LPENR;				//offset :0x64
    	  uint32_t Reserved11;				//offset :0x68
   		  uint32_t Reserved12;				//offset :0x6C
	__vol uint32_t BDCR;					//offset :0x70
	__vol uint32_t CSR;						//offset :0x74
	 	  uint32_t Reserved13;				//offset :0x78
	   	  uint32_t Reserved14;				//offset :0x7C
	__vol uint32_t SSCGR;					//offset :0x80
	__vol uint32_t PLLI2SCFGR;				//offset :0x84
		  uint32_t Reserved15;				//offset :0x88
	__vol uint32_t DCKCFGR;					//offset :0x8C

}RCC_Regdef_t;

#define RCC 			((RCC_Regdef_t*)RCC_BASEADDR)

/*
 * Peripheral register definition structure for GPIO
 * */

typedef struct{
	__vol uint32_t MODER; 				//offset :0x00
	__vol uint32_t OTYPER;				//offset :0x04
	__vol uint32_t OSPEEDR;				//offset :0x08
	__vol uint32_t PUPDR;				//offset :0x0C
	__vol uint32_t IDR;					//offset :0x10
	__vol uint32_t ODR;					//offset :0x14
	__vol uint32_t BSRR;				//offset :0x18
	__vol uint32_t LCKR;				//offset :0x1C
	__vol uint32_t AFR[2];  			 // AFR[0] = AFRL, AFR[1] = AFRH
}GPIO_Regdef_t;

#define GPIOA   	(GPIO_Regdef_t *)(GPIOA_BASEADDR)
#define GPIOB   	(GPIO_Regdef_t *)(GPIOB_BASEADDR)
#define GPIOC   	(GPIO_Regdef_t *)(GPIOC_BASEADDR)
#define GPIOD   	(GPIO_Regdef_t *)(GPIOD_BASEADDR)
#define GPIOE   	(GPIO_Regdef_t *)(GPIOE_BASEADDR)
#define GPIOH   	(GPIO_Regdef_t *)(GPIOH_BASEADDR)

/*
 * Peripheral register definition structure for I2C
 * */

typedef struct{
	__vol uint32_t CR1; 				//offset :0x00
	__vol uint32_t CR2; 				//offset :0x04
	__vol uint32_t OAR1; 				//offset :0x08
	__vol uint32_t OAR2; 				//offset :0x0C
	__vol uint32_t DR; 					//offset :0x10
	__vol uint32_t SR1; 				//offset :0x14
	__vol uint32_t SR2; 				//offset :0x18
	__vol uint32_t CCR; 				//offset :0x1C
	__vol uint32_t TRISE; 				//offset :0x20
	__vol uint32_t FLTR; 				//offset :0x24

} I2C_Regdef_t;


#define I2C1 				(I2C_Regdef_t *)(I2C1_BASEADDR)
#define I2C2 				(I2C_Regdef_t *)(I2C2_BASEADDR)
#define I2C3 				(I2C_Regdef_t *)(I2C3_BASEADDR)

/*
 * Peripheral register definition structure for SPI
 * */

typedef struct{
	__vol uint32_t CR1; 				//offset :0x00
	__vol uint32_t SR; 					//offset :0x08
	__vol uint32_t DR; 					//offset :0x0C
	__vol uint32_t CRCPR; 				//offset :0x10
	__vol uint32_t RXCRCR; 				//offset :0x14
	__vol uint32_t TXCRCR; 				//offset :0x18
	__vol uint32_t I2SCFGR; 			//offset :0x1C
	__vol uint32_t I2SPR; 				//offset :0x20


}SPI_Regdef_t;

#define SPI1          (SPI_Regdef_t *)(SPI1_BASEADDR)
#define SPI2          (SPI_Regdef_t *)(SPI2_BASEADDR)
#define SPI3          (SPI_Regdef_t *)(SPI3_BASEADDR)
#define SPI4          (SPI_Regdef_t *)(SPI4_BASEADDR)

/*
 * Peripheral register definition structure for USART
 * */

typedef struct{

	__vol uint32_t SR; 					//offset :0x00
	__vol uint32_t DR; 					//offset :0x04
	__vol uint32_t BRR; 				//offset :0x08
	__vol uint32_t CR1; 				//offset :0x0C
	__vol uint32_t CR2; 				//offset :0x10
	__vol uint32_t CR3; 				//offset :0x14
	__vol uint32_t GTPR; 				//offset :0x18


}USART_Regdef_t;

#define USART1          (USART_Regdef_t *)(USART1_BASEADDR)
#define USART2          (USART_Regdef_t *)(USART2_BASEADDR)
#define USART6          (USART_Regdef_t *)(USART6_BASEADDR)

/**********************************
 * Clock Enable Macros for GPIOx
 * GPIOx clocks are on AHB1 bus
 **********************************/
#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1 << 7))

/* SPI Clock Enable */
#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()     (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()     (RCC->APB2ENR |= (1 << 13))

/* I2C Clock Enable */
#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR |= (1 << 23))

/* USART Clock Enable */
#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1 << 5))

/**********************************
 * Clock Disable Macros
 **********************************/

/* GPIO Clock Disable */
#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 7))

/* SPI Clock Disable */
#define SPI1_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 13))

/* I2C Clock disable */
#define I2C1_PCLK_EN()     (RCC->APB1ENR &=~ (1 << 21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR &=~ (1 << 22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR &=~ (1 << 23))

/* USART Clock disable */
#define USART1_PCLK_EN()   (RCC->APB2ENR &=~ (1 << 4))
#define USART2_PCLK_EN()   (RCC->APB1ENR &=~ (1 << 17))
#define USART6_PCLK_EN()   (RCC->APB2ENR &=~ (1 << 5))



#endif /* INC_STM32F401XX_H_ */
