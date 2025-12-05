/*
 * timer_ctc.c
 *
 * Created: 30-11-2025 12:29:22
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void) //defining delay function
{
	
	for (int i=0; i<100; i++) //repeat 100 times to get 1sec delay with 1024 prescalar and compare value of 156
	{
		while(!(TIFR0&(1<<OCF0A))) //wait until OCF0A flag is set (TCNT0=OCR0A)
		TIFR0|=(1<<OCF0A); // reset OCF0A flag
	}
	
	
}
int main(void)
{
	TCNT0=0; //load min value of counter
	OCR0A=0x9C; // load compare value
	//Timer in ctc mode
	TCCR0A&=~(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	// set prescalar=1024
	TCCR0B|=(1<<CS02)|(1<<CS00);
	TCCR0B&=~(1<<CS01);
	
	DDRB|=(1<<DDB5); //configure PB5 as output
	
	/* Replace with your application code */
	while (1)
	{
		PORTB^=(1<<PB5);  //PB5 is high
		delay_1s(); //delay fun
		
	}
}

