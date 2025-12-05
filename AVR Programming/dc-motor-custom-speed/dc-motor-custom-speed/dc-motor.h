/*
 * dc_motor.h
 *
 * Created: 04-12-2025 19:58:27
 *  Author: hafna
 */ 



#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <avr/io.h>

void motor_init(void);
void motor_set_speed(uint8_t speed);   // speed in %
void motor_start(void);
void motor_stop(void);



#endif /* DC-MOTOR_H_ */