/*
 * External_interrupt.c
 *
 * Created: 08-12-2025 11:01:34
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t led_trigger = 0;  // flag set by ISR

ISR(INT0_vect) {
	led_trigger = 1;   // just set a flag
}

int main(void)
{
	// Configure PD2 (INT0 pin) as input
	DDRD &= ~(1<<DDD2);

	// Configure PB5 and PB4 as outputs
	DDRB |= (1<<DDB5) | (1<<DDB4);

	// Clear any pending INT0 flag properly
	EIFR = (1<<INTF0);

	// Enable external interrupt 0
	EIMSK |= (1<<INT0);

	// Configure INT0 for rising edge
	EICRA |= (1<<ISC01) | (1<<ISC00);

	// Enable global interrupts
	sei();

	while (1) {
		if (led_trigger) {
			PORTB |= (1<<PB5);   // LED on
			_delay_ms(3000);     // hold for 3 seconds
			PORTB &= ~(1<<PB5);  // LED off
			led_trigger = 0;     // reset flag
		}

		PORTB ^= (1<<PB4);       // toggle PB4
		_delay_ms(1000);
	}
}