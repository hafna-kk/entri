/*Objective: Write a program to simulate a basic one-way traffic light controller using
three LEDs to represent the Green, Orange, and Red signals without using inbuilt
_delay() function.
Requirements: The system must control three LEDs connected to any three
available GPIO pins on PORTB. Upon system start, the Green LED must turn ON for
a duration of 10 seconds. After this period, the Green LED must turn OFF and the
Orange LED must turn ON for 3 seconds. Once the Orange duration ends, it must
turn OFF and the Red LED must turn ON for 10 seconds. The program must be
designed to continuously cycle through this Green-Orange-Red sequence indefinitely.
 * q5.c
 *
 * Created: 26-06-2026 00:35:45
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
void delay_sec(int sec)
{
	for (int j = 0; j < sec; j++)
	{
		TCNT0 = 0;

		TCCR0A = 0x00;  // Normal mode

		TCCR0B = (1<<CS02) | (1<<CS00); // prescaler 1024

		// wait overflow 1 sec approx (62 overflows)
		for (int i = 0; i < 62; i++)
		{
			while (!(TIFR0 & (1<<TOV0)));
			TIFR0 |= (1<<TOV0); // clear flag
		}

		TCCR0B = 0x00; // stop timer
	}
}




int main(void)
{
	DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2); //configure PB0 , PB1 ,PB2 as output

	while (1)
	{
		// GREEN 10 sec
		PORTB = (1<<PB0);
		delay_sec(10);

		// ORANGE 3 sec
		PORTB = (1<<PB1);
		delay_sec(3);

		// RED 10 sec
		PORTB = (1<<PB2);
		delay_sec(10);
	}
}

