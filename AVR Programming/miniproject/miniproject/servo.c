/*
 * servo.c
 *
 * Created: 11-08-2026 15:46:47
 *  Author: hafna
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "servo.h"

#define SERVO_PIN PB2


void servo_init(void)
{
	DDRB |= (1 << SERVO_PIN);

	servo_lock();
}


static void servo_pulse_1ms(void)
{
	PORTB |= (1 << SERVO_PIN);

	_delay_us(1000);

	PORTB &= ~(1 << SERVO_PIN);

	_delay_us(19000);
}


static void servo_pulse_1_5ms(void)
{
	PORTB |= (1 << SERVO_PIN);

	_delay_us(1500);

	PORTB &= ~(1 << SERVO_PIN);

	_delay_us(18500);
}


void servo_lock(void)
{
	for (uint8_t i = 0; i < 5; i++)
	{
		servo_pulse_1ms();
	}
}


void servo_unlock(void)
{
	for (uint8_t i = 0; i < 5; i++)
	{
		servo_pulse_1_5ms();
	}
}