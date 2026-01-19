/*
 * counter_lcd.c
 *
 * Created: 23-12-2025 11:55:03
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "counter_lcd.h"
#include "lcd.h"

int main(void)
{
	lcd_init();          // Initialize LCD
	counter_init();      // Initialize INT0

	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_print("Event Count:");

	while (1)
	{
		if (button_pressed)
		{
			button_pressed = 0;

			uint16_t press_time = 0;

			// Measure how long button is held
			while (!(PIND & (1 << PD2)))   // Button LOW
			{
				_delay_ms(10);
				press_time += 10;

				if (press_time >= 2000)    // Long press: 2 sec
				{
					event_count = 0;       // RESET
					break;
				}
			}

			// Short press
			if (press_time < 2000)
			{
				event_count++;
			}

			// Wait until button fully released 
			while (!(PIND & (1 << PD2)));
		}

		// LCD update
		lcd_set_cursor(1, 0);
		lcd_print("        ");     // Clear old number
		lcd_set_cursor(1, 0);
		lcd_print_uint16(event_count);

		_delay_ms(200);
	}
}


