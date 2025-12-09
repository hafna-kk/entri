/*
 * External_interrupt_new.c
 *
 * Created: 09-12-2025 11:14:25
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect) {   // ISR for external interrupt 0
	PORTB |= (1<<PB5);   // LED on
	_delay_ms(10000);     // hold for 3 seconds
}

int main(void)
{
	// Configure PD2 (INT0 pin) as input
	DDRD &= ~(1<<DDD2);

	// Configure PB5 and PB4 as outputs
	DDRB |= (1<<DDB5) | (1<<DDB4);

	// Clear any pending INT0 flag 
	EIFR |= (1<<INTF0);

	// Enable external interrupt 0
	EIMSK |= (1<<INT0);

	// Configure INT0 for rising edge
	EICRA |=( (1<<ISC01) | (1<<ISC00) );

	// Enable global interrupts
	sei();

	while (1) {
		PORTB &= ~(1<<PB5);   // LED off
		PORTB ^= (1<<PB4);    // Toggle PB4
		_delay_ms(1000);
	}
}