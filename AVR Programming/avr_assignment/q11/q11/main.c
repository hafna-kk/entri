/*Write a program to control the angular position of a servo motor based on the analog
input received from a potentiometer.
Requirements: The system must interface a potentiometer with ADC Channel 0
and a servo motor with the OC1A pin (PORTB Pin 1). The program must configure
Timer1 in 16-bit Phase Correct PWM mode to generate the 50Hz signal required for
servo operation. A dedicated function should read the 10-bit analog value from the
potentiometer and map it to the corresponding pulse width required to move the
servo from 0 to 180 degrees. The motor position must update in real-time as the
potentiometer is turned.
 * q11.c
 *
 * Created: 19-06-2026 21:53:49
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

// ADC Initialization
void ADC_Init()
{
	ADMUX = (1<<REFS0);                  // AVCC reference
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);
}

// Read ADC0
uint16_t ADC_Read()
{
	ADCSRA |= (1<<ADSC);

	while(ADCSRA & (1<<ADSC));

	return ADC;
}

// Move Servo
void Servo_Position()
{
	uint16_t adc;
	uint16_t pulse;

	adc = ADC_Read();

	//  ADC (0-1023) to pulse width (2000-4000)
	pulse = 2000 + ((uint32_t)adc * 2000) / 1023;

	OCR1A = pulse;
}

int main(void)
{
	// PB1 (OC1A) as output
	DDRB |= (1<<DDB1);

	ADC_Init();

	// Timer1 Phase and Frequency Correct PWM
	TCCR1A = (1<<COM1A1);

	TCCR1B = (1<<WGM13) | (1<<CS11);

	// TOP value for 50Hz
	ICR1 = 40000;

	while(1)
	{
		Servo_Position();
	}
}

