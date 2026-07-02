/*Objective: Write a program to manage a traffic light sequence that includes a high-
priority interrupt designed to trigger a state change only after the current light cycle

completes its minimum safe duration.
Requirements: The system must control three LEDs (Green, Orange, and Red)
connected to PORTB. Under normal operation, the program should cycle through the
Green (10s), Orange (3s), and Red (10s) states in a continuous loop. An emergency
push-button must be interfaced with the External Interrupt 0 (INT0) pin. When the
button is pressed, the program should set a flag within the Interrupt Service Routine
(ISR) rather than jumping states immediately. The main program logic must check
this flag at the end of the current light's duration. If the flag is set, the system must
then prioritize the Green light for a set duration before clearing the flag and resuming
the normal cycle.
 * q6.c
 *
 * Created: 06-06-2026 00:53:46
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t flag = 0;

// Timer delay 
void delay_sec(int sec)
{
	for (int j = 0; j < sec; j++)
	{
		TCNT0 = 0;

		TCCR0A = 0x00;
		TCCR0B = (1<<CS02) | (1<<CS00); // prescaler 1024

		for (int i = 0; i < 62; i++)
		{
			while (!(TIFR0 & (1<<TOV0)));
			TIFR0 |= (1<<TOV0);
		}

		TCCR0B = 0x00;
	}
}

// INT0 ISR (only sets flag)
ISR(INT0_vect)
{
	flag = 1;
}

// Interrupt init
void int0_init()
{
	DDRD &= ~(1<<DDD2);      // INT0 pin input
	PORTD |= (1<<PD2);       // pull-up enable

	EICRA |= (1<<ISC01);     // falling edge trigger
	EIMSK |= (1<<INT0);      // enable INT0

	sei();                   // global interrupt enable
}

int main(void)
{
	DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2);

	int0_init();

	while (1)
	{
		// GREEN 10 sec
		PORTB = (1<<PB0);
		delay_sec(10);

		if (flag)
		{
			PORTB = (1<<PB0);   // priority GREEN
			delay_sec(5);
			flag = 0;
		}

		// ORANGE 3 sec
		PORTB = (1<<PB1);
		delay_sec(3);

		if (flag)
		{
			PORTB = (1<<PB0);
			delay_sec(5);
			flag = 0;
		}

		// RED 10 sec
		PORTB = (1<<PB2);
		delay_sec(10);

		if (flag)
		{
			PORTB = (1<<PB0);
			delay_sec(5);
			flag = 0;
		}
	}
}
