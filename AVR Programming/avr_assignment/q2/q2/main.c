/*Objective: Write a program to toggle between a Red LED and a Green LED using a
momentary push-button switch.
Requirements: The system must interface with a Red LED, a Green LED, and a
push-button switch. When the switch is pressed, the program must toggle the current
active LED state. If the Red LED is currently ON, it must be turned OFF while the
Green LED is turned ON. Conversely, if the Green LED is currently ON, it must be
turned OFF while the Red LED is turned ON. Each individual press of the switch
should trigger exactly one transition between the two LEDs.
 * q2.c
 *
 * Created: 25-06-2026 22:47:54
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1 << DDB2) | (1 << DDB3);   // LEDs as output
	DDRD &= ~(1 << DDD2);                // Switch as input
	PORTD |= (1 << PORTD2);              // Enable pull-up

	uint8_t state = 0;                   // 0 = Red, 1 = Green

	// Initially : Red ON
	PORTB |= (1 << PORTB2);
	PORTB &= ~(1 << PORTB3);

	while (1)
	{
		if (!(PIND & (1 << PIND2)))      // Button pressed
		{
			_delay_ms(20);               // Debounce

			if (!(PIND & (1 << PIND2)))
			{
				if (state == 0)
				{
					PORTB &= ~(1 << PORTB2); // Red OFF
					PORTB |= (1 << PORTB3);  // Green ON
					state = 1;
				}
				else
				{
					PORTB &= ~(1 << PORTB3); // Green OFF
					PORTB |= (1 << PORTB2);  // Red ON
					state = 0;
				}

				while (!(PIND & (1 << PIND2))); // Wait for release
				_delay_ms(20);
			}
		}
	}
}