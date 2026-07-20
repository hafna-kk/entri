/*
 * stm32f401xx_gpio_driver.h
 *
 *  Created on: Jan 28, 2026
 *      Author: hafna
 */


#ifndef INC_STM32F401XX_GPIO_DRIVER_H_
#define INC_STM32F401XX_GPIO_DRIVER_H_
#include "stdint.h"

#include "stm32f401xx.h"



typedef struct {
	uint8_t GPIO_PinNumber; // Pin number (0-15)
	uint8_t GPIO_PinMode; // Mode: Input/Output/AltFn/Analog
	uint8_t GPIO_PinSpeed; // Speed: Low/Medium/High/Very High
	uint8_t GPIO_PinPuPdControl; // Pull-up/Pull-down configuration
	uint8_t GPIO_PinOPType; // Output type: Push-Pull/Open-Drain
	uint8_t GPIO_PinAltFunMode; // Alternate function (0-15)
	}GPIO_PinConfig_t;

/* * Handle structure for a GPIO pin */

typedef struct {
	GPIO_Regdef_t *pGPIOx; // Pointer to GPIO port base address
	GPIO_PinConfig_t GPIO_PinConfig; // Pin configuration settings
	}GPIO_Handle_t;


	/**********************************
	 * Generic Macros
	 **********************************/


#define GPIO_PIN_NO_0 			0
#define GPIO_PIN_NO_1 			1
#define GPIO_PIN_NO_2 			2
#define GPIO_PIN_NO_3 			3
#define GPIO_PIN_NO_4 			4
#define GPIO_PIN_NO_5 			5
#define GPIO_PIN_NO_6 			6
#define GPIO_PIN_NO_7 			7
#define GPIO_PIN_NO_8 			8
#define GPIO_PIN_NO_9 			9
#define GPIO_PIN_NO_10 			10
#define GPIO_PIN_NO_11 			11
#define GPIO_PIN_NO_12			12
#define GPIO_PIN_NO_13			13
#define GPIO_PIN_NO_14			14
#define GPIO_PIN_NO_15 			15

	/*
	 * @GPIO_PIN_MODES
	 * GPIO pin possible modes
	 */
	#define GPIO_MODE_IN       0   // Input mode
	#define GPIO_MODE_OUT      1   // General purpose output mode
	#define GPIO_MODE_ALTFN    2   // Alternate function mode
	#define GPIO_MODE_ANALOG   3   // Analog mode
	// Interrupt modes (Handled via EXTI)
	#define GPIO_MODE_IT_FT     4   // Interrupt Falling edge trigger
	#define GPIO_MODE_IT_RT     5   // Interrupt Rising edge trigger
	#define GPIO_MODE_IT_RFT    6   // Interrupt Rising + Falling trigger
	/*
	 * @GPIO_PIN_OUTPUT_TYPES
	 * GPIO pin output types
	 */
	#define GPIO_OP_TYPE_PP    0   // Push-pull
	#define GPIO_OP_TYPE_OD    1   // Open-drain

	/*
	 * @GPIO_PIN_SPEED
	 * GPIO pin output speeds
	 */
	#define GPIO_SPEED_LOW     0   // Low speed
	#define GPIO_SPEED_MEDIUM  1   // Medium speed
	#define GPIO_SPEED_FAST    2   // High speed
	#define GPIO_SPEED_HIGH    3   // Very high speed

	/*
	 * @GPIO_PIN_PUPD
	 * GPIO pin pull-up/pull-down configuration
	 */
	#define GPIO_NO_PUPD       0   // No pull-up, pull-down
	#define GPIO_PIN_PU        1   // Pull-up
	#define GPIO_PIN_PD        2   // Pull-down

	//GPIO ALt Functions/

	#define GPIO_AF_01				0
	#define GPIO_AF_02				1
	#define GPIO_AF_03				2
	#define GPIO_AF_04				3
	#define GPIO_AF_05				4
	#define GPIO_AF_06				5
	#define GPIO_AF_07				6
	#define GPIO_AF_08				7
	#define GPIO_AF_09				8
	#define GPIO_AF_10				9
	#define GPIO_AF_11				10
	#define GPIO_AF_12				11
	#define GPIO_AF_13				12
	#define GPIO_AF_14				12
	#define GPIO_AF_15				14





void GPIO_PeriClockControl(GPIO_Regdef_t *pGPIOx, uint8_t EnorDi);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Regdef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_Regdef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_Regdef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_Regdef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_Regdef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_Regdef_t *pGPIOx, uint8_t PinNumber);

/**********************************
 * IRQ Configuration and Handling
 **********************************/

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

void GPIO_IRQHandling(uint8_t PinNumber);

#endif
/* INC_STM32F401XX_GPIO_DRIVER_H_ */

