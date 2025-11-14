/*
 * blink(3sec).c
 *
 * Created: 14-11-2025 12:24:43
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0b01000000;//set PC6 as output
	while (1)
	{
		PORTC=0b01000000;//set PC6 is high
		_delay_ms(3000); //set 3 sec delay
		PORTC=0b00000000;//set PD2 is low
		_delay_ms(3000);//set 3 sec delay
	}
}


