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

	uint8_t speed;

	while (1)
	{
		// Example: user gives input manually
		speed = 30;   // you can change this to any % (0–100)

		motor_set_speed(speed);
		motor_start();

		while(1);  // stay here
	}
}
