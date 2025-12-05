/*
 * timer0_modular.c
 *
 * Created: 02-12-2025 21:11:47
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "delay.h" //" " is used for user defined headers

int main(void)
{
  DDRB|=(1<<DDB5);//set PB5 as output
  timer0_init(); //user function for timer 0 configuration
    while (1) 
    {
		PORTB|=(1<<PB5);
		delay_ms(3000);//user defined function for delay
		PORTB &= ~(1<<PB5);  // LED OFF
		delay_ms(3000);
    }
}

