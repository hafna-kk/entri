/*
 * Switch.c
 *
 * Created: 20-11-2025 20:43:40
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
  DDRD&=~(1<<DDD2);
  DDRB|=(1<<DDB5);
    while (1) 
    {
		if(PIND & (1<<PD2)){
			PORTB|=(1<<PB5);
			}
		else{
			PORTB&=~(1<<PB5);
		}
				
    }
}

