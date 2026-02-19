/*
 * stm32f401xx_gpio_driver.c
 *
 *  Created on: Jan 28, 2026
 *      Author: hafna
 */


#include "stm32f401xx_gpio_driver.h"


/*********************************************************************
 * @fn          - GPIO_PeriClockControl
 *
 * @brief       - Enables or disables peripheral clock for GPIO port
 *
 * @param[in]   - pGPIOx: GPIO port base address
 * @param[in]   - EnorDi: ENABLE or DISABLE macros
 *
 * @return      - none
 *
 * @Note        - none
 *********************************************************************/
void GPIO_PeriClockControl(GPIO_Regdef_t *pGPIOx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (pGPIOx == GPIOA)
        {
            GPIOA_PCLK_EN();
        }
        else if (pGPIOx == GPIOB)
        {
            GPIOB_PCLK_EN();
        }
        else if (pGPIOx == GPIOC)
        {
            GPIOC_PCLK_EN();
        }
        else if (pGPIOx == GPIOD)
        {
            GPIOD_PCLK_EN();
        }
        else if (pGPIOx == GPIOE)
        {
            GPIOE_PCLK_EN();
        }

        else if (pGPIOx == GPIOH)
        {
            GPIOH_PCLK_EN();
        }
    }
    else
    {
        // Similar structure for DISABLE
        if (pGPIOx == GPIOA)
        {
            GPIOA_PCLK_DI();
        }
        else if (pGPIOx == GPIOB)
                {
                    GPIOB_PCLK_DI();
                }
        else if (pGPIOx == GPIOB)
                 {
                     GPIOB_PCLK_DI();
                 }
        else if (pGPIOx == GPIOC)
               {
                 GPIOC_PCLK_DI();
                }
        else if (pGPIOx == GPIOD)
                       {
                           GPIOD_PCLK_DI();
                       }
        else if (pGPIOx == GPIOE)
                       {
                           GPIOE_PCLK_DI();
                       }
        else if (pGPIOx == GPIOH)
                       {
                           GPIOH_PCLK_DI();
                       }

    }
}
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;

    /*********************************************************
     * 1. Configure GPIO Mode
     *********************************************************/
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        // Clear MODER bits
        pGPIOHandle->pGPIOx->MODER &=
            ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        // Set mode
        pGPIOHandle->pGPIOx->MODER |=
            (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<
             (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    }
    else
    {
        /*********************************************************
         * INTERRUPT MODE CONFIGURATION
         *********************************************************/

        // 1. Force Input mode
        pGPIOHandle->pGPIOx->MODER &=
            ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        // 2. Configure trigger selection
        if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
        {
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
        {
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
        {
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }

        // 3. Enable SYSCFG clock
        SYSCFG_PCLK_EN();

        // 4. Configure EXTI line source using SYSCFG_EXTICR
        uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
        uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;

        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);

        SYSCFG->EXTICR[temp1] &=
            ~(0xF << (temp2 * 4));

        SYSCFG->EXTICR[temp1] |=
            (portcode << (temp2 * 4));

        // 5. Enable interrupt delivery using IMR
        EXTI->IMR |=
            (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    }

    /*********************************************************
     * 2. Configure Speed
     *********************************************************/
    pGPIOHandle->pGPIOx->OSPEEDR &=
        ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    pGPIOHandle->pGPIOx->OSPEEDR |=
        (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<
         (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    /*********************************************************
     * 3. Configure Pull-Up / Pull-Down
     *********************************************************/
    pGPIOHandle->pGPIOx->PUPDR &=
        ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    pGPIOHandle->pGPIOx->PUPDR |=
        (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<
         (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

    /*********************************************************
     * 4. Configure Output Type
     *********************************************************/
    pGPIOHandle->pGPIOx->OTYPER &=
        ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

    pGPIOHandle->pGPIOx->OTYPER |=
        (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<
         pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

    /*********************************************************
     * 5. Configure Alternate Function
     *********************************************************/
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
    {
        uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

        pGPIOHandle->pGPIOx->AFR[temp1] &=
            ~(0xF << (4 * temp2));

        pGPIOHandle->pGPIOx->AFR[temp1] |=
            (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode <<
             (4 * temp2));
    }
}

void GPIO_DeInit(GPIO_Regdef_t *pGPIOx){
	if(pGPIOx == GPIOA){

		RCC->AHB1RSTR |= (1 << 0);
		RCC->AHB1RSTR &=~ (1 << 0);
	}
	else if(pGPIOx == GPIOB){

			RCC->AHB1RSTR |= (1 << 1);
			RCC->AHB1RSTR &=~ (1 << 1);
		}
	else if(pGPIOx == GPIOC){

				RCC->AHB1RSTR |= (1 << 2);
				RCC->AHB1RSTR &=~ (1 << 2);
			}
	else if(pGPIOx == GPIOD){

				RCC->AHB1RSTR |= (1 << 3);
				RCC->AHB1RSTR &=~ (1 << 3);
			}
	else if(pGPIOx == GPIOE){

				RCC->AHB1RSTR |= (1 << 4);
				RCC->AHB1RSTR &=~ (1 << 4);
			}
	else if(pGPIOx == GPIOH){

				RCC->AHB1RSTR |= (1 << 7);
				RCC->AHB1RSTR &=~ (1 << 7);
			}
}

/*********************************************************************
 * @fn          - GPIO_ReadFromInputPin
 *
 * @brief       - Reads the value of an input pin
 *
 * @param[in]   - pGPIOx: GPIO port base address
 * @param[in]   - PinNumber: Pin number to read
 *
 * @return      - 0 or 1
 *********************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_Regdef_t *pGPIOx, uint8_t PinNumber)
{
    uint8_t value;

    // Read IDR, shift right by pin number, mask with 1
    value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);

    return value;
}

/*********************************************************************
 * @fn          - GPIO_ReadFromInputPort
 *
 * @brief       - Reads the entire input port
 *
 * @return      - 16-bit value of the port
 *********************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_Regdef_t *pGPIOx)
{
    uint16_t value;

    value = (uint16_t)pGPIOx->IDR;

    return value;
}

/*********************************************************************
 * @fn          - GPIO_WriteToOutputPin
 *
 * @brief       - Writes to an output pin
 *
 * @param[in]   - pGPIOx: GPIO port base address
 * @param[in]   - PinNumber: Pin number to write
 * @param[in]   - Value: GPIO_PIN_SET or GPIO_PIN_RESET
 *********************************************************************/
void GPIO_WriteToOutputPin(GPIO_Regdef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
    if (Value == GPIO_PIN_SET)
    {
        // Set the bit
        pGPIOx->ODR |= (1 << PinNumber);
    }
    else
    {
        // Clear the bit
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}

/*********************************************************************
 * @fn          - GPIO_WriteToOutputPort
 *
 * @brief       - Writes to entire output port
 *********************************************************************/
void GPIO_WriteToOutputPort(GPIO_Regdef_t *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = Value;
}

/*********************************************************************
 * @fn          - GPIO_ToggleOutputPin
 *
 * @brief       - Toggles the state of an output pin
 *********************************************************************/
void GPIO_ToggleOutputPin(GPIO_Regdef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1 << PinNumber);  // XOR to toggle
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(IRQNumber <= 31)
        {
            *NVIC_ISER0 |= (1 << IRQNumber);
        }
        else if(IRQNumber < 64)
        {
            *NVIC_ISER1 |= (1 << (IRQNumber % 32));
        }
    }
    else
    {
        if(IRQNumber <= 31)
        {
            *NVIC_ICER0 |= (1 << IRQNumber);
        }
        else if(IRQNumber < 64)
        {
            *NVIC_ICER1 |= (1 << (IRQNumber % 32));
        }
    }
}

void GPIO_IRQHandling(uint8_t PinNumber)
{
    if(EXTI->PR & (1 << PinNumber))
    {
        // clear pending bit
        EXTI->PR |= (1 << PinNumber);
    }
}
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;

    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

    *(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift_amount);
}
