/*
 * dc-motor-speed.c
 *
 * Created: 18-12-2025 10:55:38
 * Author : hafna
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


volatile uint8_t speed_change_req = 0;
volatile uint8_t speed_level = 0;

// delay function
void delay_ms(unsigned int ms)
{
	while (ms--)
	_delay_ms(1);
}

// External Interrupt ISR (INT0)
ISR(INT0_vect)
{
	
	speed_change_req = 1;
}

int main(void)
{
	
	/* Motor control pins */
	DDRD |= (1 << DDD6);   // PD6  (PWM pin)
	DDRD |= (1 << DDD0);   // configure PD0 as motor pin
	DDRD |= (1 << DDD1);   // configure PD1 as motor pin

	/* Set motor direction: forward */
	PORTD |= (1 << PD0);
	PORTD &= ~(1 << PD1);

	/* Push button on INT0 (PD2) */
	DDRD &= ~(1 << DDD2);  // input
	PORTD |= (1 << PD2);   // enable internal pull-up

	
	/* Phase Correct PWM, non-inverting PWM */
	TCCR0A = (1 << WGM00) | (1 << COM0A1);
	TCCR0B = (1 << CS01) | (1 << CS00);   // Prescaler = 64

	/* Start with low speed */
	OCR0A = 64; // 25% duty cycle

	/* INT0 on falling edge */
	EICRA = (1 << ISC01);
	EIMSK = (1 << INT0);

	sei();   // Enable global interrupts

	while (1)
	{
		
		if (speed_change_req)
		{
			speed_change_req = 0;

			speed_level++;
			if (speed_level > 3)
			speed_level = 0;
		}

		/* set speed based on speed_level */
		switch (speed_level)
		{
			case 0:
			OCR0A = 64;    // 25% duty cycle
			break;
			case 1:
			OCR0A = 128;   // 50% duty cycle
			break;
			case 2:
			OCR0A = 192;   // 75% duty cycle
			break;
			case 3:
			OCR0A = 255;   // 100% duty cycle
			break;
		}

		delay_ms(100);
	}
}
