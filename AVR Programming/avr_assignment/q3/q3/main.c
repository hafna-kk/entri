/*Objective: Write a program to create a "train" animation where a single active LED
appears to move across a series of connected GPIO pins.
Requirements: The system must control a sequence of at least eight LEDs
connected to PORTB. When the program starts, only the first LED should turn ON.
After a short delay, the first LED must turn OFF and the second LED must turn ON.
This sequential shifting must continue until the last LED in the row is reached. Once
the "train" reaches the end of the line, the pattern should immediately reset to the
first LED and repeat the sequence indefinitely to create a continuous moving light
effect.
 * q3.c
 *
 * Created: 25-06-2026 23:40:39
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = 0xFF;//configure all port B pins as output (LEDs)
	
	
    while (1) 
    {
		for(uint8_t i=0 ; i<8 ; i++){
			
			PORTB = (1 << i); //ON one LED at a time from PB0 to PB7
			_delay_ms(200); //delay
		}
    }
}

