/*
 * timer0-normalmode.c
 *
 * Created: 30-11-2025 12:32:17
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void delay_1s()
{
	TCNT0=0;// Load min value of counter
	TCCR0A&=~((1<<WGM00)|(1<<WGM01)); //Set Timer 0 in normal mode
	TCCR0B&=~((1<<CS01)|(1<<CS01));
	TCCR0B|=(1<<CS00);
	
	//repeat 62500 times to get 1sec delay
	for (long int i=0; i<62500; i++)
	{
		while(!(TIFR0&(1<<TOV0)));//Check flag
		TIFR0|=(1<<TOV0);//WRITING 1 TO MAKE TOV0=0(strange rule/ opposite ie to make 0 write 1)
	}

}

int main(void)
{
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
