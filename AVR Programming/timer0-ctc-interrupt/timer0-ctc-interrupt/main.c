/*
 * timer0-ctc-interrupt.c
 *
 * Created: 05-12-2025 11:02:14
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t count=0;
ISR(TIMER0_COMPA_vect){
	if(count>1000){
		PORTB^=(1<<PB5);
		count=0;
	}
	else{
		count++;
	}
}


int main(void)
{
	sei();//Enable global interrupt
    TCNT0=0; //load min value of counter
    OCR0A=0xF9; // load compare value
    //Timer in ctc mode
    TCCR0A&=~(1<<WGM00);
    TCCR0A|=(1<<WGM01);
    // set prescalar=64
    TCCR0B|=(1<<CS01)|(1<<CS00);
    TCCR0B&=~(1<<CS02);
	//enable output compare match A interrupt
	TIMSK0|=(1<<OCIE0A);
	DDRB|=(1<<DDB5);//set PB5 is output port
    while (1) 
    {
    }
}

