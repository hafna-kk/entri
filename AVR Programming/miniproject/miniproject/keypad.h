/*
 * keypad.h
 *
 * Created: 11-08-2026 15:44:54
 *  Author: hafna
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include <avr/io.h>
#include <stdint.h>

void keypad_init(void);
char keypad_getkey(void);


#endif /* KEYPAD_H_ */