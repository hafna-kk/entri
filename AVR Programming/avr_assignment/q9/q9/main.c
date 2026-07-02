/*Objective: Write a program to control the brightness of an LED or the speed of a
small DC motor using the hardware PWM capability of Timer0.
Requirements: The program must initialize Timer0 in Fast PWM mode with the
output directed to the OC0A pin (PORTD Pin 6). The system should start with a 25%
duty cycle. A push-button connected to an input pin should be used to cycle the duty
cycle through four levels: 25%, 50%, 75%, and 100% OFF. Each time the button is
pressed, the program should update the Output Compare Register (OCR0A) to the
appropriate value corresponding to the selected duty cycle. The duty cycle sequence
should repeat continuously in a loop (i.e., after 100%, it should return to 25%).
The button input should be properly debounced (either via software delay or logic)
to avoid multiple unintended triggers.
 * q9.c
 *
 * Created: 10-06-2026 10:55:52
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void update_duty_cycle(uint8_t level)
{
	switch(level)
	{
		case 0: OCR0A = 64;  break;  // 25%
		case 1: OCR0A = 128; break;  // 50%
		case 2: OCR0A = 192; break;  // 75%
		case 3: OCR0A = 255; break;  // 100%
		case 4: OCR0A = 0;   break;  // OFF
	}
}

int main(void)
{
	// PWM pin
	DDRD |= (1 << DDD6);

	// Motor direction (optional)
	DDRD |= (1 << DDD0) | (1 << DDD1);
	PORTD |= (1 << PD0);
	PORTD &= ~(1 << PD1);

	// Button
	DDRD &= ~(1 << DDD2);
	PORTD |= (1 << PD2);   // pull-up

	// Fast PWM
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	TCCR0B = (1 << CS01) | (1 << CS00);

	uint8_t level = 0;
	update_duty_cycle(level);

	while (1)
	{
		if (!(PIND & (1 << PIND2)))
		{
			_delay_ms(50);   // debounce

			if (!(PIND & (1 << PIND2)))
			{
				level++;

				if (level > 4)
				level = 0;

				update_duty_cycle(level);

				// wait release 
				while (!(PIND & (1 << PIND2)))
				{
					_delay_ms(10);
				}

				_delay_ms(50);
			}
		}
	}
}
