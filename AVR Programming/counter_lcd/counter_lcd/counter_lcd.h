/*
 * counter_lcd.h
 *
 * Created: 23-12-2025 11:56:36
 *  Author: hafna
 */ 


#ifndef COUNTER_LCD_H_
#define COUNTER_LCD_H_
#include <stdint.h>


//Initialize external interrupt for event counting 
void counter_init(void);

extern volatile uint16_t event_count; // Global event counter 
extern volatile uint8_t button_pressed;

#endif /* COUNTER_LCD_H_ */