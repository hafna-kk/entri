/*
 * pullup-blink.c
 *
 * Created: 22-11-2025 20:50:09
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   DDRD&=~(1<<DDD2);
   PORTD |= (1 << PD2);
   DDRB|=(1<<DDB2);
    while (1) 
    {
		if (!(PIND&(1<<PD2)))
		{
			PORTB|=(1<<PB2);
		} 
		else
		{PORTB&=~(1<<PB2);
		}
    }
}

