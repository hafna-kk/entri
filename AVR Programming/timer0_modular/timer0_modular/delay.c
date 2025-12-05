/*
 * delay.c
 *
 * Created: 02-12-2025 21:12:43
 *  Author: hafna
 */ 
#include <avr/io.h>
#include "delay.h"

void timer0_init(void){
	TCNT0=0;
	OCR0A=249;
	//Timer0 CTC mode
	TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	//Prescalar =64
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
}
void delay_ms(uint16_t ms){
	while(ms--){
		while(!(TIFR0&(1<<OCF0A)));
		TIFR0|=(1<<OCF0A);
	}
}