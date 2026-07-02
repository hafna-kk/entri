/*13. Objective: Write a program to manage an LED’s state and intensity through a serial
terminal while providing real-time status updates back to the user.
Requirements: The system must use UART communication at a 9600 baud rate to
receive instructions. An LED must be connected to a pin capable of hardware PWM.
If the user sends the command "ON", the LED must turn on and the system should
send back the message "LED is now ON". If the user sends "OFF", the LED must turn
off and the system should reply with "LED is now OFF". If the user sends a number
between 0 and 100, the program must adjust the LED brightness to that percentage
and reply with "Brightness set to [Value]%".
 * q13.c
 *
 * Created: 19-06-2026 22:28:18
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#define BAUD 9600
#define UBRR_VALUE 103

//UART FUNCTIONS

void UART_Init()
{
	UBRR0H = (UBRR_VALUE >> 8);
	UBRR0L = UBRR_VALUE;

	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void UART_Transmit(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_SendString(char *str)
{
	while (*str)
	{
		UART_Transmit(*str++);
	}
}

/* Receive string */
void UART_ReceiveString(char *buffer)
{
	char c;
	uint8_t i = 0;

	while (1)
	{
		while (!(UCSR0A & (1 << RXC0)));

		c = UDR0;

		if (c == '\n' || c == '\r')
		{
			buffer[i] = '\0';
			break;
		}
		else
		{
			buffer[i++] = c;
		}
	}
}

// PWM FUNCTION 

void PWM_Init()
{
	DDRD |= (1 << DDD6); // PD6 OC0A

	// Fast PWM, non-inverting
	TCCR0A = (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
	TCCR0B = (1 << CS01) | (1 << CS00); // prescaler 64
}

void set_brightness(uint8_t percent)
{
	if (percent > 100) percent = 100;

	OCR0A = (percent * 255) / 100;
}



int main(void)
{
	char cmd[20];

	UART_Init();
	PWM_Init();

	set_brightness(0);

	UART_SendString("System Ready\r\n");

	while (1)
	{
		UART_ReceiveString(cmd);

	
		if (strcmp(cmd, "ON") == 0)
		{
			set_brightness(100);
			UART_SendString("LED is now ON\r\n");
		}

		else if (strcmp(cmd, "OFF") == 0)
		{
			set_brightness(0);
			UART_SendString("LED is now OFF\r\n");
		}

	
		else
		{
			int value = atoi(cmd);

			if (value >= 0 && value <= 100)
			{
				set_brightness(value);

				UART_SendString("Brightness set to ");
				
				char msg[10];
				itoa(value, msg, 10);

				UART_SendString(msg);
				UART_SendString("%\r\n");
			}
			else
			{
				UART_SendString("Invalid Command\r\n");
			}
		}
	}
}
