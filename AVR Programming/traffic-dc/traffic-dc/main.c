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
		   if (interrupt_flag == 1) return; 
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




int main(void)
{
	// motor pins
	DDRD |= (1<<DDD0) | (1<<DDD1) | (1<<DDD6);

	// traffic light pins
	DDRB |= (1<<DDB1) | (1<<DDB2) | (1<<DDB3);

	// switch
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PD2);  // enable pull-up

	PORTD |= (1<<PD6);  // enable L293D output

	// interrupt configure
	// INT0 low-level trigger
	EICRA &= ~((1<<ISC00) | (1<<ISC01));  // ISC01 = 0, ISC00 = 0

	EIFR |= (1<<INTF0);
	EIMSK |= (1<<INT0); //configure external interrupt
	sei();//enable global interrupt

	while(1)
	{
		// If switch pressed   //ISR
		if(interrupt_flag == 1)
		{
			

			 interrupt_flag = 0;//clear the flag
			stp();                // red
			cw();                 // CW 10s
			delay_ms(10000);

			motor_stop();         // stop 20s
			delay_ms(20000);

			acw();                // ACW 10s
			delay_ms(10000);

			motor_stop();
			go();                 // back to green
			continue;
		}

		// NORMAL TRAFFIC SYSTEM
	go();      
	delay_ms(5000);
	if(interrupt_flag == 1) continue;

	ready();  
	 delay_ms(3000);
	if(interrupt_flag == 1) continue;

	stp();    
	 delay_ms(5000);
	if(interrupt_flag == 1) continue;

	ready();   delay_ms(3000);
	}
}
