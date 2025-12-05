/*
 * pwm_ds30.c
 *
 * Created: 04-12-2025 17:34:36
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void delay_ms_custom(uint16_t t)
{
	while (t--)
	_delay_ms(1);
}

void cw(){
	PORTD |= (1 << PD5);    // IN1 = HIGH
	PORTD &= ~(1 << PD4);   // IN2 = LOW
}

void ccw(){
	PORTD &= ~(1 << PD5);   // IN1 = LOW
	PORTD |= (1 << PD4);    // IN2 = HIGH
}

void stp(){
	PORTD &= ~(1 << PD5);   // IN1 = LOW
	PORTD &= ~(1 << PD4);   // IN2 = LOW
}

int main(void)
{
	DDRD |= (1 << DDD6) | (1 << DDD5) | (1 << DDD4);
	// PD6 = PWM, PD5 & PD4 = direction pins

	// Phase correct PWM
	TCCR0A |= (1 << WGM00);
	TCCR0A &= ~(1 << WGM01);

	// Non-inverting PWM
	TCCR0A |= (1 << COM0A1);
	TCCR0A &= ~(1 << COM0A0);

	// Prescaler = 64
	TCCR0B |= (1 << CS01) | (1 << CS00);
	TCCR0B &= ~(1 << CS02);

	// PWM duty = 30%
	OCR0A = 76;

	while (1)
	{
		cw();
		delay_ms_custom(5000);

		stp();
		delay_ms_custom(3000);

		ccw();
		delay_ms_custom(5000);

		stp();
		delay_ms_custom(3000);
	}
}
