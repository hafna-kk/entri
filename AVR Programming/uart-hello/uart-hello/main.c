/*
 * uart-hello.c
 *
 * Created: 31-12-2025 21:47:20
 * Author : hafna
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void uart_tx(char data)
{
	while(!(UCSR0A&(1<<UDRE0))); //wait until transmission is complete
	UDR0=data;
}
int main(void)
{
	
	char arr[]="HELLO";
	UBRR0H=0;
	UBRR0L=103; //set baud rate to 9600
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00); // 8bit mode
	UCSR0C&=~((1<<UPM01)|(1<<UPM00)|(1<<USBS0)); //no parity and 1 stop bit
	UCSR0B|=(1<<TXEN0); //enable transmitter
	while (1)
	{
		
		
		 for (int i = 0; arr[i] != '\0'; i++)
		 {
			 uart_tx(arr[i]);
		 }

		 uart_tx('\n');
		_delay_ms(1000);
	}
}

