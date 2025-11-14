/*
 * Blink.c
 *
 * Created: 14-11-2025 12:22:59
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0b00000100;//set PD2 as output
	while (1)
	{
		PORTD=0b00000100;//set PD2 is high
		_delay_ms(1000); //set 1 sec delay
		PORTD=0b00000000;//set PD2 is low
		_delay_ms(1000);//set 1 sec delay
	}
}
