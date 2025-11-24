/*
 * traffic-dc.c
 *
 * Created: 24-11-2025 23:28:13
 * Author : hafna
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void delay(unsigned int t){
	_delay_ms(t);
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
	DDRD |= (1<<DDD0) | (1<<DDD1);

	// traffic light pins output
	DDRB |= (1<<DDB1) | (1<<DDB2) | (1<<DDB3);

	// switch input
	DDRB &= ~(1<<DDB0);
	PORTB |= (1<<PB0);      // enable pull-up

	while(1)
	{
		// normal sequence
		go();      delay(5000);
		ready();   delay(3000);
		stp();     delay(5000);
		ready();   delay(3000);

		// switch pressed
		if( !(PINB & (1<<PB0)) )
		{
			stp();      // RED

			cw();       // clockwise
			delay(10000);

			motor_stop();
			delay(20000);

			acw();      // anticlockwise
			delay(10000);

			motor_stop();
			go();       // back to GREEN
		}
	}
}
