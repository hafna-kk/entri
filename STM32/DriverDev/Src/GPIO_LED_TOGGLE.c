/*
 * GPIO_INT.c
 *
 *  Created on: Feb 19, 2026
 *      Author: hafna

 */
#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"


// Software delay for debouncing (~200ms @ 16MHz)
void delay1(void)
{
    for(uint32_t i = 0; i < 500000/2; i++);
}
int main(void){

	GPIO_Handle_t GPIO_led,GPIO_INT;



	/* Configuration for led */

	GPIO_led.pGPIOx=GPIOA;
	GPIO_led.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
	GPIO_led.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
	GPIO_led.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_LOW;
	GPIO_led.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	GPIO_led.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;


	 /* Enable clock for GPIOA  */
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GPIO_led);

	/* Select GPIO port C */

	GPIO_INT.pGPIOx=GPIOC;

			/* Configure pin PC13 (USER button on board) */
	GPIO_INT.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_13;
	GPIO_INT.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_IT_FT;
	GPIO_INT.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
	GPIO_INT.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PIN_PU;


				 /* Enable clock for  GPIOC */
				GPIO_PeriClockControl(GPIOC, ENABLE);

			 /* Initialize GPIO pins */

				GPIO_Init(&GPIO_INT);

				GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);
				GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,10);

				 // Main loop - wait for interrupts
				    while(1)
				    {

				    }


}
void EXTI15_10_IRQHandler(void)
{
    delay1();  // Software debouncing

    GPIO_IRQHandling(GPIO_PIN_NO_13);  // Clear pending interrupt

    GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);  // Toggle LED
}
