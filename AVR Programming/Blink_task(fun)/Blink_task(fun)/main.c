/*Define 3 functions for the 3 conditions explained in the previous question (Function names  cw(),ccw() stp()).
 Call the funtions in the min so that we get the LED blink as per the previous question.
 * Blink_task(fun).c
 *
 * Created: 17-11-2025 12:05:24
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

