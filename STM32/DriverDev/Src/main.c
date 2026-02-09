/*
 * main.c
 *
 *  Created on: Feb 7, 2026
 *      Author: hafna
 */


#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"



int main(void)
{
	GPIO_Handle_t GPIO_led;
	GPIO_Handle_t button;
	GPIO_Handle_t GPIO_LED1,GPIO_LED2;

	/* Enable clock for GPIOA and GPIOC */
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_PeriClockControl(GPIOC, ENABLE);


		 /* Select GPIO port A */
			GPIO_led.pGPIOx=GPIOA;

		 /* Configure pin PA5 (on-board LED) */
			GPIO_led.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
			GPIO_led.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
			GPIO_led.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
			GPIO_led.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
			GPIO_led.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;


		/* Select GPIO port C */

			button.pGPIOx=GPIOC;

		/* Configure pin PC13 (USER button on board) */
			button.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_13;
			button.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_IN;
			button.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
			button.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;



		 /* Initialize GPIO pins */
			GPIO_Init(&GPIO_led);
			GPIO_Init(&button);



			/* Select GPIO port A */

			GPIO_LED1.pGPIOx=GPIOA;

			 /* Configure pin PA6  */
			GPIO_LED1.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_6;
			GPIO_LED1.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
			GPIO_LED1.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
			GPIO_LED1.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
			GPIO_LED1.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;


			 GPIO_Init(&GPIO_LED1);


				/* Select GPIO port A */

			    GPIO_LED2.pGPIOx=GPIOA;

				 /* Configure pin PA7  */
				GPIO_LED2.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_7;
				GPIO_LED2.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
				GPIO_LED2.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
				GPIO_LED2.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
				GPIO_LED2.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;


				GPIO_Init(&GPIO_LED2);


			static uint8_t state = 0;
			static uint32_t count = 0;
			static uint32_t delay = 0;

    while(1)
    {
    	 if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == 0)
    	        {
    	            delay++;

    	            if (delay > 20000)   // debounce delay
    	            {
    	                GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
    	                delay = 0;

    	                while (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == 0);
    	            }
    	        }
    	        else
    	        {
    	            delay = 0;   // reset when button released
    	        }
    //LED1 & LED2 alternate blinking

    	count++;

    	if(count >= 250000)
    	{
    		count=0;
    	    if(state == 0)
    	    {
    	    	//LED1 ON , LED2 OFF
    	        GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_6, GPIO_PIN_SET);
    	        GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_7, GPIO_PIN_RESET);
    	        state = 1;
    	    }
    	    else
    	    {
    	    	//LED2 ON , LED1 OFF
    	        GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_7, GPIO_PIN_SET);
    	        GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_6, GPIO_PIN_RESET);
    	        state = 0;
    	    }
    	}

    }
}
