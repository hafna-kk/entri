/*
 * GPIO_toggle.c
 *
 *  Created on: Feb 4, 2026
 *      Author: hafna
 */


#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"

void delay(void){
	for (uint32_t i = 0; i < 500000; i++);

}

int main(void){

	GPIO_Handle_t GPIO_led;

	GPIO_led.pGPIOx=GPIOA;
	GPIO_led.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
	GPIO_led.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
	GPIO_led.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
	GPIO_led.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	GPIO_led.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIO_led);

	while(1){
		GPIO_ToggleOutputPin(GPIOA , GPIO_PIN_NO_5);
		delay();
	}




}
