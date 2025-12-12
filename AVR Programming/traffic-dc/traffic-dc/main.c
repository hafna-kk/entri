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

volatile uint8_t interrupt_flag = 0;   // flag set by ISR

// delay function
void delay_ms(unsigned int t){
	while(t--){
		if (interrupt_flag == 1) return; // early exit 
		_delay_ms(1);
	}
}


// TRAFFIC LIGHT
void stp(void){
	PORTB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3));
	PORTB |= (1<<PB3);    // RED
}

void ready(void){
	PORTB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3));
	PORTB |= (1<<PB2);    // ORANGE
}

void go(void){
	PORTB &= ~((1<<PB1)|(1<<PB2)|(1<<PB3));
	PORTB |= (1<<PB1);    // GREEN
}


// MOTOR
void cw(void){
	PORTD |= (1<<PD0);
	PORTD &= ~(1<<PD1);
}

void acw(void){
	PORTD |= (1<<PD1);
	PORTD &= ~(1<<PD0);
}

void motor_stop(void){
	PORTD &= ~(1<<PD0);
	PORTD &= ~(1<<PD1);
}

//ISR for External Interrupt
ISR(INT0_vect)
{
	interrupt_flag = 1;   // set a flag
}

// Function for special sequence
void special_sequence(void) {
	interrupt_flag = 0;   // clear the flag
	
	stp();                // 1. Change Green/Orange to Red
	cw();                 // 2. CW 10s
	delay_ms(10000);

	motor_stop();         // 3. Stop 20s
	delay_ms(20000);

	acw();                // 4. ACW 10s
	delay_ms(10000);

	motor_stop();         // 5. Motor stop
	go();                 // 6. Back to Green
}


int main(void)
{
	// motor pins (PD0, PD1 for control, PD6 for L293D Enable)
	DDRD |= (1<<DDD0) | (1<<DDD1) | (1<<DDD6);

	// traffic light pins (PB1:Green, PB2:Orange, PB3:Red)
	DDRB |= (1<<DDB1) | (1<<DDB2) | (1<<DDB3);

	// switch (PD2/INT0)
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PD2);  // enable pull-up

	PORTD |= (1<<PD6);  // enable L293D output

	// interrupt configure
	// INT0 on falling edge
	EICRA |= (1<<ISC01);
	EICRA &= ~(1<<ISC00);
	
	// Clear any pending INTF0 flag from power-up/transient
	EIFR |= (1<<INTF0);
	
	EIMSK |= (1<<INT0); // configure external interrupt
	sei();              // enable global interrupt (Do this last)

	while(1)
	{
		// Check for the special sequence request
		if(interrupt_flag == 1)
		{
			special_sequence();
			continue; // Return to the start 
		}

		// NORMAL TRAFFIC SYSTEM

		//  GREEN
		go();
		delay_ms(5000);
		if(interrupt_flag == 1) 
			{ special_sequence(); continue; } // Handle interrupt after delay
		
		//  ORANGE (before Red)
		ready();
		delay_ms(3000);
		if(interrupt_flag == 1) 
			
			{ special_sequence(); continue; }
		
		// RED
		stp();
		delay_ms(5000);
		if(interrupt_flag == 1)
			 { special_sequence(); continue; }

		//ORANGE (before Green)
		ready();
		delay_ms(3000);
		
	}
}