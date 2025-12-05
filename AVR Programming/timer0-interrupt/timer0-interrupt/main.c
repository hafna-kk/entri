/*
 * timer0-interrupt.c
 *
 * Created: 04-12-2025 20:44:07
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile  uint16_t count=0;
ISR(TIMER0_OVF_vect){ //Interrupt service routine
	if(count>977){
		PORTB^=(1<<PB5);
		count=0;
	}
	else{
		count++;
}
}
int main(void)
{
    DDRB|=(1<<DDB5);
    sei();  // enable Timer0 global interrupt
	TCNT0=0;
	TCCR0A &=~((1<<WGM00)|(1<<WGM01)); //Timer0 in normal mode
	//prescalar =64
	TCCR0B |= (1 << CS01) | (1 << CS00); 
	TCCR0B &= ~(1 << CS02);
	 // enable Timer0 Overflow interrupt
	TIMSK0|=(1<<TOIE0);
    while (1) 
    {
    }
}

