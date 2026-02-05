/*
 * uart_servo.c
 *
 * Created: 28-01-2026 11:44:13
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

volatile char rx_char;
volatile uint8_t rx_flag = 0;

ISR(USART_RX_vect)
{
	rx_char = UDR0;   // Read received character
	rx_flag = 1;      // Mark data available
}
uint8_t UART_DataAvailable(void)
{
	return rx_flag;
}

char UART_GetChar(void)
{
	rx_flag = 0;      // Clear flag
	return rx_char;
}

// PB1 / OC1A
void Servo_Init(void)
{
	// Set PB1 as output
	DDRB |= (1 << PB1);

	// Timer1 Fast PWM, 50Hz (ICR1 top)
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // prescaler 8
	ICR1 = 40000; // 16MHz / 8 / 50Hz = 40000 counts

	// Initial position = 0°
	OCR1A = 2000; // 1ms pulse
}
// angle 0-180
void Servo_SetAngle(uint8_t angle)
{
	// pulse width 1ms–2ms ? 2000–4000 counts
	OCR1A = 2000 + ((uint32_t)angle * 2000) / 180;
}

int main(void)
{ 
	char cmd;
	   UART_Init();   // Initialize UART
	   Servo_Init();  // Initialize Servo PWM
	   sei();         // Enable global interrupts       
	
	
	UART_TxString("UART BASE SERVO MOTOR CONTROL \r\n");
   while (1)
   {
	   if (UART_DataAvailable())
	   {
		   cmd = UART_GetChar();

		   if (cmd == '\r' || cmd == '\n')
		   continue;

		   if (cmd == '0')
		   {
			   Servo_SetAngle(0);
			   UART_TxString("Servo -> 0 degrees\r\n");
		   }
		   else if (cmd == '1')
		   {
			   Servo_SetAngle(90);
			   UART_TxString("Servo -> 90 degrees\r\n");
		   }
		   else if (cmd == '2')
		   {
			   Servo_SetAngle(180);
			   UART_TxString("Servo -> 180 degrees\r\n");
		   }
		   
		   else
		   {
			   UART_TxString("INVALID COMMAND\r\n");
		   }
	   }
   }

}

