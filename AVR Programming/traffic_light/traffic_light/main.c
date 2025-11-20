/*
 * traffic_light.c
 *
 * Created: 20-11-2025 09:52:10
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void stp(){
	PORTB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2));  // clear ALL three LEDs
	PORTB|=(1<<PB2); //RED ON
	
}
void ready(){
	PORTB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2));  // clear ALL three LEDs
	PORTB|=(1<<PB1);//YELLOW ON
	
	
}
void go(){
	PORTB &= ~((1<<PB0) | (1<<PB1) | (1<<PB2));  // clear ALL three LEDs
	PORTB|=(1<<PB0); //GREEN  ON
	
	
}
int main(void)
{
  DDRB|=(1<<DDB2)|(1<<DDB1)|(1<<DDB0);// Set PB0, PB1, PB2 as output
    while (1) 
    {
		stp();  //RED ON
		_delay_ms(15000); //15 sec delay
		ready();//YELLOW ON
		_delay_ms(3000);
		go(); //GREEN  ON
		_delay_ms(15000);
		ready();//YELLOW ON
		_delay_ms(3000);
    }
}

