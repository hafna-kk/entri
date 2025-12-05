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

	// PWM pin PD6 (OC0A) output
	DDRD |= (1 << PD6);

	// Set direction forward
	PORTD |= (1 << PD0);

	// Timer0 Fast PWM - non-inverting
	TCCR0A |= (1 << WGM00) | (1 << WGM01);
	TCCR0A |= (1 << COM0A1);

	// Prescaler 64 ? PWM frequency ~1 kHz
	TCCR0B |= (1 << CS01) | (1 << CS00);
}

void motor_set_speed(uint8_t speed)
{
	if (speed > 100) speed = 100;  // limit input

	uint8_t value = (speed * 255) / 100;  // convert %
	OCR0A = value;
}

void motor_start(void)
{
	OCR0A = OCR0A;  // just keep PWM running
}

void motor_stop(void)
{
	OCR0A = 0;  // duty cycle = 0 ? motor stops
}
