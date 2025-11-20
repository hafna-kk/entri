/*
 * dc-motor-using-switch.c
 *
 * Created: 20-11-2025 22:45:54
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void cw(){
	PORTD|=(1<<PD0);//set PD0 is high
	PORTD&=~(1<<PD1);//set PD1 is low
}
void acw(){
	PORTD|=(1<<PD1); // set PD1 is high
	PORTD&=~(1<<PD0); // set PD0 is low
}
void stp(){
	PORTD&=~(1<<PD0); // set PD0 is low
	PORTD&=~(1<<PD1); // set PD1 is low
}
int main(void)
{
   DDRD|=(1<<DDD1)|(1<<DDD0); // Motor pins(PD1 & PD0) as output

   DDRB&=~((1<<DDB1)|(1<<DDB2)); // Switches as input(PB1 & PB2) 
    while (1) 
    {
		if ((PINB&(1<<PB1))&& !(PINB&(1<<PB2))) //check PB1=1 &	PB2=0	
		{
			cw();
		} 
		else if(!(PINB&(1<<PB1))&& (PINB&(1<<PB2)))//check PB1=0 &	PB2=1
		{
			acw();
		}
		else
		{
			stp();
		}
    }
}

