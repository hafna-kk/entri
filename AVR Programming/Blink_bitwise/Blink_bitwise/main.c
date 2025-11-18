/*
 * Blink_bitwise.c
 *
 * Created: 15-11-2025 20:31:07
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
  DDRD|=(1<<DDD2); //set PD2 as output
    while (1) 
    {
		PORTD |= (1 << PD2); //set PD2 as high
		_delay_ms(1000); //set 1sec delay
		PORTD &=~(1 << PD2);//set PD2 as low
		_delay_ms(1000);
    }
}

