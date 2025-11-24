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
   DDRD&=~(1<<DDD2); // PD2 as input
   PORTD |= (1 << PD2);     // Enable internal pull-up resistor on PD2
   DDRB|=(1<<DDB2); // PB2 as output (LED pin)

    while (1) 
    {
		if (!(PIND&(1<<PD2)))// If button pressed (PD2 LOW)
		{
			PORTB|=(1<<PB2); // LED ON
		} 
		else
		{PORTB&=~(1<<PB2); // LED OFF
		}
    }
}

