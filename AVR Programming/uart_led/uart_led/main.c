/*
 * uart_led.c
 *
 * Created: 28-01-2026 10:13:37
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_PIN PB0

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

int main(void)
{
   char cmd;
   UART_Init();
   sei();            // Enable global interrupts
	LED_DDR |= (1<< LED_PIN );	//set PB0 as output
	LED_PORT &=~ (1<<LED_PIN);	//initially led off 
	
	UART_TxString("UART LED CONTROL \r\n");
   
		 while (1)
		      {
			      if (UART_DataAvailable())
			      {
				      cmd = UART_GetChar();

				      if (cmd == '\r' || cmd == '\n')
				      {
					      continue;
				      }

				      if (cmd == '1')
				      {
					      LED_PORT |= (1 << LED_PIN);
					      UART_TxString("LED ON\r\n");
				      }
				      else if (cmd == '0')
				      {
					      LED_PORT &= ~(1 << LED_PIN);
					      UART_TxString("LED OFF\r\n");
				      }
				      else if (cmd == 'S')
				      {
					      if (LED_PORT & (1 << LED_PIN))
					      UART_TxString("LED IS ON\r\n");
					      else
					      UART_TxString("LED IS OFF\r\n");
				      }
				      else
				      {
					      UART_TxString("INVALID COMMAND\r\n");
				      }
			      }
		 }   
}

