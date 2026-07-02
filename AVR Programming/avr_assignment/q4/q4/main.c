/*Objective: Write a program that uses four LEDs to display a 4-bit binary count
triggered by a switch.
Requirements: Four LEDs must be connected to PORTB (Pins 0 through 3) and a
push-button must be connected to PORTD Pin 2. Every time the switch is pressed,
the value displayed by the LEDs must increment by one in binary format (from 0000
to 1111). When the count reaches 15 (all LEDs ON), the next press must reset the
counter back to 0. The program should use a dedicated function to update the LED
states based on the current counter variable.
 * q4.c
 *
 * Created: 26-06-2026 00:04:08
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// function to update the LED states
void display_count(uint8_t count) 
{
	PORTB = count & 0x0F ;  //send count to portB(0-3) for display count in binary 
}

int main(void)
{
	DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3); //set PB0–PB3 as output
	DDRD &= ~(1<<DDD2);  // PD2 as input
	PORTD |= (1<<PD2);   // pull-up enabled

	uint8_t count = 0;

	display_count(count);

	while (1)
	{
		if (!(PIND & (1<<PIND2)))   // button pressed
		{
			_delay_ms(20);         // debounce

			if (!(PIND & (1<<PIND2)))
			{
				count++;

				if (count == 16)
				{
					count = 0;
				}

				display_count(count);

				while (!(PIND & (1<<PIND2))); // wait release
				_delay_ms(20);
			}
		}
	}
}