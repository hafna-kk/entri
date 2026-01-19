/*
 * counter_lcd.c
 *
 * Created: 23-12-2025 11:56:51
 *  Author: hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "counter_lcd.h"

volatile uint16_t event_count = 0;
volatile uint8_t button_pressed = 0;

ISR(INT0_vect)//ISR for INT0
{
	button_pressed = 1;   // Set a flag
}


void counter_init(void){
	
	DDRD&=~(1<<DDD2);//set PD2 as input
	PORTD|=(1<<PD2);//Enable internal pull-up
	
	
	EIMSK|=(1<<INT0);//Enable  external interrupt 0
	//Configure INT0 for falling edge
	EICRA|=(1<<ISC01);
	EICRA &= ~(1 << ISC00);
	EIFR|=(1<<INTF0);//Clear flag
	sei(); //Enable global interrupt
	
}