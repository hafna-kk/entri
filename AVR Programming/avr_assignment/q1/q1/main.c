/*
 * q1.c
 *
 * Created: 01-06-2026 10:52:19
 * Author : hafna
 Objective: Write a program to toggle an LED connected to PORTD Pin 5 with
 specific timing intervals for the ON and OFF states.
 Requirements: The LED must be interfaced with PORTD Pin 5. Upon system start
 or reset, the LED must immediately turn ON and remain in that state for exactly 3
 seconds. After the ON period, the LED must turn OFF for a duration of exactly 5
 seconds. The program must be designed to continuously loop this 3-second ON and
 5-second OFF sequence.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= (1<<DDD5); // Set PD5 as output

	
	 
    while (1) 
    {
	 	 PORTD |= (1<<PD5); // Set PD5 high (LED ON)
		  
		
		 for(int i = 0; i < 300; i++)
		 {
			 _delay_ms(10);    //3sec delay
		 }

		 
		 PORTD &= ~(1<<PD5); //Set PD5 low (LED OFF)
		 
		 for(int i = 0; i < 500; i++)
		 {
			 _delay_ms(10);    //5sec delay
		 }
    }
}

