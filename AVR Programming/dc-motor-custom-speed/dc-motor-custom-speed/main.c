/*
 * dc-motor-custom-speed.c
 *
 * Created: 04-12-2025 19:57:59
 * Author : hafna
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "dc-motor.h"

int main(void)
{
	motor_init();

	
	while (1)
	{	
		motor_set_speed();
		
	}
}
