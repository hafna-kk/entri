/*
 * timer_prescaling.c
 *
 * Created: 30-11-2025 12:30:22
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void delay_1s(void) //defining a function for delay
{
		
	//repeat the loop 61 times to get 1sec delay
	for (int i=0; i<61; i++)
	{
		while(!(TIFR0&(1<<TOV0)));//Check flag
		TIFR0|=(1<<TOV0);//WRITING 1 TO MAKE TOV0=0(strange rule/ opposite ie to make 0 write 1)
	}

}

int main(void)
{
	TCNT0=0;// Load min value of counter
	TCCR0A&=~((1<<WGM00)|(1<<WGM01)); //Set Timer 0 in normal mode
	TCCR0B|=(1<<CS02|1<<CS00);// divided by 1024
	TCCR0B&=~(1<<CS01);

	DDRB|=(1<<DDB5);
	/* Replace with your application code */
	while (1)
	{
		PORTB|=(1<<PB5);
		delay_1s();
		PORTB&=~(1<<PB5);
		delay_1s();
	}
}
