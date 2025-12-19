/*
 * led-brighness-control.c
 *
 * Created: 18-12-2025 10:31:10
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t mode = 0;   // 0 = fade, 1 = step brightness

void delay_ms(unsigned int ms)
{
	while (ms--)
	{
		_delay_ms(1);
	}
}

ISR(INT0_vect)
{
	mode ^= 1;   // toggle mode
}

int main(void)
{
	// LED pin
	DDRD |= (1<<DDD6);

	// Button INT0 pin
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PD2);   // pull-up enable

	// Phase Correct PWM
	TCCR0A |= (1<<WGM00);
	TCCR0A &= ~(1<<WGM01);

	// Non-inverting PWM
	TCCR0A |= (1<<COM0A1);
	TCCR0A &= ~(1<<COM0A0);

	// Prescaler = 8
	TCCR0B |= (1<<CS01);

	// External Interrupt INT0 (falling edge)
	EICRA |= (1<<ISC01);
	EICRA &= ~(1<<ISC00);
	EIMSK |= (1<<INT0);

	sei();   // global interrupt enable

	while (1)
	{
		if (mode == 0)
		{
			// Smooth fading
			for (int i = 0; i <= 255; i++)
			{
				OCR0A = i;
				delay_ms(5);
				if (mode) break;
			}

			for (int i = 255; i >= 0; i--)
			{
				OCR0A = i;
				delay_ms(5);
				if (mode) break;
			}
		}
		else
		{
			// Step brightness levels
			OCR0A = 64;   delay_ms(1000);
			OCR0A = 128;  delay_ms(1000);
			OCR0A = 192;  delay_ms(1000);
			OCR0A = 255;  delay_ms(1000);
		}
	}
}
