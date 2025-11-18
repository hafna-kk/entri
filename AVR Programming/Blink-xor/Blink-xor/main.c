/*
 * Blink-xor.c
 *
 * Created: 17-11-2025 10:56:18
 * Author : hafna
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
int main(void)
{
    DDRD|=(1<<DDD2);//set PD2 as output
    while (1) 
    {
		PORTD^=(1<<PD2);// Toggle PD2 (LED ON & OFF)
		_delay_ms(1000); //1sec delay
		
    }
}

