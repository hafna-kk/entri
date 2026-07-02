/* Objective: Write a program to show a 9-digit number on an LCD screen that
increases with a quick button press and resets to zero with a long press.
Requirements: The system must use a 16x2 LCD and one push-button. On the
screen, the counter should start at 000000000. When you press and let go of the
button quickly, the count should go up by 1. If you hold the button down for 2
seconds or more, the counter must clear and go back to 0. The program needs to use
functions to check how long the button is held and to update the number on the LCD
screen.
 * q12.c
 *
 * Created: 27-06-2026 22:18:26
 * Author : hafna
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd-hello.h"

#define BUTTON PB0 //switch connected to pb0
unsigned long count=0;

void display_number(unsigned long num)
{
	char txt[10];
	sprintf(txt,"%09lu",num);  //Convert number into 9-digit string
	lcd_home();
	lcd_print(txt);
}

void check_button()
{
	if(!(PINB&(1<<BUTTON)))   // check whether button pressed or not
	{
		unsigned int time=0;
		_delay_ms(20);
		
		while(!(PINB&(1<<BUTTON))) //Measure  button press time
		{
			_delay_ms(10);
			time+=10;
		}

		// press time calculation
		if(time>=2000)  //Long Press
		{
			count=0;
		}
		else
		{
			count++;   //Short Press
		}

		lcd_clear();
		display_number(count);
		_delay_ms(200);
	}
}

int main(void)
{
	DDRB&=~(1<<BUTTON);  // pb0 as input(switch)
	PORTB|=(1<<BUTTON);   //  internal pull up is enabled
	
	lcd_init();
	display_number(count);

	while(1)
	{
		check_button();
	}
}