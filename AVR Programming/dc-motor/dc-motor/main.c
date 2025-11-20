/*
 * dc-motor.c
 *
 * Created: 18-11-2025 20:40:38
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>



void cw(){
	PORTD|=(1<<PD1);//set PD1 is high
	PORTD &= ~(1 << PD0);//set PD0 is low
	
}
void ccw(){
	PORTD|=(1<<PD0);//set PD0 is high
	PORTD &= ~(1 << PD1);//set PD1 is low
	
}
void stp(){
	PORTD&=~(1<<PD1);//set PD1 is low
	PORTD&=~(1<<PD0);//set PD0 is low
	
	
}
int main(void)
{
	DDRD|=(1<<DDD1)|(1<<DDD0);// Set PD1 & PD0 as output
	while (1)
	{
		cw(); //set PD1 is high & PD0 is low
		_delay_ms(5000);
		stp(); //Both PD1 & PD0 is low
		_delay_ms(3000);
		ccw();  //set PD0 is high & PD1 is low
		_delay_ms(5000);
		stp(); //Both PD1 & PD0 is low
		_delay_ms(3000);
		
	}
}


