/*Objective: Write a program that manages two independent timing tasks
simultaneously using the 16-bit Timer1 and the 8-bit Timer2.
Requirements: The system must control two different LEDs. Timer1 must be
configured to toggle a "Status LED" on PORTB Pin 1 exactly every 2 seconds.
Simultaneously, Timer2 must be configured to toggle a "Heartbeat LED" on PORTB
Pin 2 every 500 milliseconds. The program must use the Compare Match interrupt
for both timers to ensure high precision. Each LED's timing logic must reside in its
respective Interrupt Service Routine, allowing both sequences to run independently
without interfering with each other.
 * q7.c
 *
 * Created: 09-06-2026 08:09:09
 * Author : hafna
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

void timer1_init()
{
	// CTC mode
	TCCR1B |= (1<<WGM12);

	// 2 sec timing:
	// 16MHz / 256 = 62500 counts/sec
	// 2 sec = 125000 counts ? OCR1A = 125000 - 1
	OCR1A = 124999;

	// prescaler 256
	TCCR1B |= (1<<CS12);

	// enable compare match interrupt
	TIMSK1 |= (1<<OCIE1A);
}

void timer2_init()
{
	// CTC mode
	TCCR2A |= (1<<WGM21);


	TCCR2B |= (1<<CS22); // prescaler 64

	TIMSK2 |= (1<<OCIE2A);
}

// Timer1 ISR ? 2 sec
ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1<<PB1);   // toggle Status LED
}

// Timer2 
volatile uint16_t ms2 = 0;

ISR(TIMER2_COMPA_vect)
{
	ms2++;

	if (ms2 >= 500)
	{
		PORTB ^= (1<<PB2); // toggle Heartbeat LED
		ms2 = 0;
	}
}

int main(void)
{
	DDRB |= (1<<DDB1) | (1<<DDB2);

	timer1_init();
	timer2_init();

	sei(); // global interrupt enable

	while (1)
	{
		
	}
}