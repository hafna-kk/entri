/*
 * spi.c
 *
 * Created: 06-01-2026 20:45:35
 * Author : hafna
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"



int main(void)
{
	uart_init();
	uint8_t chip_id;
   DDRB|=(1<<DDB3)|(1<<DDB5)|(1<<DDB2);//MOSI,SCK and SS configured as output
   DDRB&=~(1<<DDB4); //MISO configured as input
   SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
   SPCR&=~((1<<SPR1)|(1<<CPHA)|(1<<CPOL));
    while (1) 
    {
		PORTB &= ~(1 << PB2); // slave select
		SPDR=(0xD0|0x80); //ensuring 1 on MSB (read)
		while(!(SPSR & (1 << SPIF))); //waiting until flag is set		(void)SPDR;//for reading SPDR(dummy garbage value).
		
		SPDR=0x00; //sending dummy to read data  from BMP280
		while(!(SPSR & (1 << SPIF)));
		chip_id=SPDR;
		PORTB |= (1 << PB2); //deselecting slave
		uartTx_string("Chip ID : ");
		uart_Txhex(chip_id);
		
		
		
		
    }
}

