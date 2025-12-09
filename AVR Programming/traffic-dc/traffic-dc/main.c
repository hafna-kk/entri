/*Hw: Make a Traffic light (Green - Orange-Red-Orange - Green) .
 When a switch is pressed , Change Green to Red and rotate a motor clockwise for 10 seconds. 
 wait for 20 seconds. and then turn the motor anticlockwise for 10 seconds 
 Then change red back to green and follow the normal flow.
 * traffic-dc.c
 *
 * Created: 24-11-2025 23:28:13
 * Author : hafna
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//ISR for external interrupt
ISR(INT0_vect)
{
	stp();          // Force to RED

	cw();           // CW for 10 seconds
	delay(10000);

	motor_stop();   // Stop 20 seconds
	delay(20000);

	acw();          // ACW for 10 seconds
	delay(10000);

	motor_stop();
	go();           // Back to GREEN
}
void delay(unsigned int t){ //set delay function
	while(t--){
		_delay_ms(1);
	}
}

// TRAFFIC LIGHT
void stp(){           // RED ON
	PORTB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3));
	PORTB |= (1<<PB3);
}
void ready(){         // ORANGE ON
	PORTB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3));
	PORTB |= (1<<PB2);
}
void go(){            // GREEN ON
	PORTB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3));
	PORTB |= (1<<PB1);
}

// MOTOR FUNCTIONS
void cw(){
	PORTD |= (1<<PD0);
	PORTD &= ~(1<<PD1);
}
void acw(){
	PORTD |= (1<<PD1);
	PORTD &= ~(1<<PD0);
}
void motor_stop(){
	PORTD &= ~(1<<PD0);
	PORTD &= ~(1<<PD1);
}

int main(void)
{
	// motor pins output
	DDRD |= (1<<DDD0) | (1<<DDD1)|(1<<DDD6); //PD6 is pwm pin

	// traffic light pins output
	DDRB |= (1<<DDB1) | (1<<DDB2) | (1<<DDB3);

	// switch input
	DDRD &= ~(1<<DDD2);   // PD2 (INT0) as input
	PORTD |= (1<<PD2);    // enable pull-up

	PORTD |= (1<<PD6);   // ENABLE L293D output permanently
	EIFR|=(1<<INTF0);// Clear flag
	
	EICRA|=((1<<ISC00)|(1<<ISC01)); //Configure INT0 for rising edge
	
	EIMSK|=(1<<INT0);//Enable External interrupt0
	
	sei(); //Enable global interrupt
	while(1)
	{
		// normal sequence
		go();      delay(5000);
		ready();   delay(3000);
		stp();     delay(5000);
		ready();   delay(3000);


		
	}
}
