/*
 * dc_motor.c
 *
 * Created: 04-12-2025 19:58:46
 *  Author: hafna
 */ 
#include "dc-motor.h"

void motor_init(void)
{
	// Direction pin PD0 output
	DDRD |= (1 << PD0);
DDRD |= (1 << PD1);
	// PWM pin PD6  output
	DDRD |= (1 << PD6);

	// Set PD0 high
	PORTD |= (1 << PD0);
	// Set PD1 low
PORTD &=~ (1 << PD1);
	// Timer0  PWM - non-inverting
	TCCR0A |= (1<<WGM01) | (1<<WGM00); 
TCCR0B &= ~(1<<WGM02);
	TCCR0A |= (1 << COM0A1);

	// Prescaler 64
	TCCR0B |= (1 << CS01) | (1 << CS00);
}

void motor_set_speed(void)
{
	
	OCR0A = 128;
}


