/*
 * Blink-task.c
 *
 * Created: 18-11-2025 10:43:16
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Initialize PB0  and PB1 as output
	DDRB |= (1 << DDB0) | (1 << DDB1);

	while (1)
	{
		
		PORTB |= (1 << PB0);     // PB0 ON
		PORTB &= ~(1 << PB1);    // PB1 OFF
		_delay_ms(5000);

		
		PORTB &= ~((1 << PB0) | (1 << PB1));  // Both OFF
		_delay_ms(3000);

		
		PORTB |= (1 << PB1);     // PB1 ON
		PORTB &= ~(1 << PB0);    // PB0 OFF
		_delay_ms(5000);
	}
}
