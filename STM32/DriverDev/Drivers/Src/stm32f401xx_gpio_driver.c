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
        // ... repeat for other ports
    }
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	 uint32_t temp = 0;

	    // 1. Configure the mode of GPIO pin
	    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	    {
	        // Non-interrupt mode
	        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode
	                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	        // Clear the 2 bits first
	        pGPIOHandle->pGPIOx->MODER &= ~(0x3
	                << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	        // Set the new value
	        pGPIOHandle->pGPIOx->MODER |= temp;
	    }
	    else
	    {
	        // Interrupt mode
	    }
	    temp = 0;

	    // 2. Configure the speed
	    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	    pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	    temp = 0;

	    // 3. Configure the pull-up/pull-down settings
	    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	    pGPIOHandle->pGPIOx->PUPDR |= temp;
	    temp = 0;

	    // 4. Configure the output type (only 1 bit per pin)
	    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	    pGPIOHandle->pGPIOx->OTYPER |= temp;
	    temp = 0;

	    //AF
	    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	   	    {
	    	uint32_t temp1,temp2;

	   	    temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;  // AFR index (0 or 1)
	   	   	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;  // Bit position

	   	   	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
	   	   	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));

	   	    }



}
void GPIO_DeInit(GPIO_Regdef_t *pGPIOx){

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
