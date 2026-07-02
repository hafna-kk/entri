/*Objective: Write a program to create an automated cooling system using an LM35
sensor and a DC motor with manual power control.
Requirements: The system must interface with an LM35 temperature sensor and a
DC motor. A push-button must be used to toggle the entire system ON and OFF.
When the system is ON, it should read the temperature and adjust the motor speed
accordingly. At lower temperatures, the motor should run at a reduced speed, and at
higher temperatures, the motor should automatically switch to a higher speed. The
program logic for sensor reading, speed calculation, and motor control must be
implemented using separate functions.
 * q10.c
 *
 * Created: 12-06-2026 21:45:36
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t system_on = 0;

// ADC Initialization
void ADC_Init()
{
	ADMUX = (1<<REFS0);   // AVCC reference, ADC0
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1); // Enable ADC, Prescaler 64
}

// Read ADC
uint16_t ADC_Read()
{
	ADCSRA |= (1<<ADSC);           // Start conversion

	while (ADCSRA & (1<<ADSC));    // Wait

	return ADC;
}

// Read temperature from LM35
uint16_t Read_Temperature()
{
	uint16_t adc = ADC_Read();

	// LM35 = 10mV/°C
	
	return (adc * 500) / 1024;
}

// Calculate motor speed
uint8_t Calculate_Speed(uint16_t temp)
{
	if(temp < 20)
	return 64;      // 25%

	else if(temp < 30)
	return 128;     // 50%

	else
	return 255;     //100%
}

// Control Motor
void Motor_Control(uint8_t speed)
{
	OCR0A = speed;
}

int main(void)
{
	// PWM pin
	DDRD |= (1<<DDD6);

	// Motor direction
	DDRD |= (1<<DDD0) | (1<<DDD1);

	PORTD |= (1<<PD0);
	PORTD &= ~(1<<PD1);

	// Button
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PD2);

	// Timer0 Fast PWM
	TCCR0A = (1<<WGM00) | (1<<WGM01) | (1<<COM0A1);
	TCCR0B = (1<<CS01) | (1<<CS00);

	ADC_Init();

	while(1)
	{
		// Toggle system ON/OFF
		if(!(PIND & (1<<PD2)))
		{
			_delay_ms(20);

			if(!(PIND & (1<<PD2)))
			{
				system_on = !system_on;

				while(!(PIND & (1<<PD2)));

				_delay_ms(20);
			}
		}

		if(system_on)
		{
			uint16_t temp;

			temp = Read_Temperature();

			uint8_t speed;

			speed = Calculate_Speed(temp);

			Motor_Control(speed);
		}
		else
		{
			OCR0A = 0;      // Motor OFF
		}
	}
}