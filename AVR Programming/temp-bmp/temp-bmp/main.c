/*
 * temp-bmp.c
 *
 * Created: 11-01-2026 11:13:16
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
	uint32_t msb,lsb,xlsb,T1_L,T1_U,T2_L,T2_U,T3_L,T3_U;
	uint32_t temp;
	uint16_t dig_T1,T,T_int,T_frac;
	float var1,var2,t_fine,temperature;
	int16_t dig_T2,dig_T3;
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
	
		
		//Enabling measurment by writing 0x27 to 0xF4 reg of BMP280
		PORTB &= ~(1 << PB2); // slave select
		SPDR=(0xF4&0x7F); //ensuring 0 on MSB (write)
		while(!(SPSR & (1 << SPIF))); //waiting until flag is set		(void)SPDR;//for reading SPDR(dummy garbage value).
		
		SPDR=0x27; // sending 27 to F4
		while(!(SPSR & (1 << SPIF)));
		(void)SPDR;//for reading SPDR(dummy garbage value).
		PORTB |= (1 << PB2); //deselecting slave
		
		//reading data from FA
		PORTB &= ~(1 << PB2); // slave select
		SPDR=(0xFA|0x80); //ensuring 1 on MSB (read)
		while(!(SPSR & (1 << SPIF))); //waiting until flag is set		(void)SPDR;//for reading SPDR(dummy garbage value).
		
		SPDR=0x00; 
		while(!(SPSR & (1 << SPIF)));
		msb=SPDR;
		
		//reading data from FB
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		lsb=SPDR;
		
		//reading data from FC
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		xlsb=SPDR;
		PORTB |= (1 << PB2); //deselecting slave
		temp=((uint32_t )msb<<12)|((uint32_t )lsb<<4)|((uint32_t )xlsb>>4);
		
		//reading temperature compensation values
		PORTB &= ~(1 << PB2); // slave select
		SPDR=(0x88|0x80); //ensuring 1 on MSB (read)
		while(!(SPSR & (1 << SPIF))); //waiting until flag is set		(void)SPDR;//for reading SPDR(dummy garbage value).
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		T1_L=SPDR;
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		T1_U=SPDR;
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		T2_L=SPDR;
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		T2_U=SPDR;
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		T3_L=SPDR;
		
		SPDR=0x00;
		while(!(SPSR & (1 << SPIF)));
		T3_U=SPDR;
		PORTB |= (1 << PB2); //deselecting slave
		dig_T1=((uint16_t )T1_U<<8)|T1_L;
		dig_T2=((uint16_t )T2_U<<8)|T2_L;
		dig_T3=((uint16_t )T3_U<<8)|T3_L;
		
			var1 = (((temp / 16384.0f) - ((float)dig_T1 / 1024.0f)) * (float)dig_T2);
			var2 = ((((temp / 131072.0f) - ((float)dig_T1 / 8192.0f)) *
			((temp / 131072.0f) - ((float)dig_T1 / 8192.0f))) * (float)dig_T3);
		t_fine=var1+var2;
		temperature=t_fine/5120.0f;
		T=temperature*100;
		T_int=T/100;
		T_frac=T%100;
		uartTx_number(T_int);
		UART_TxChar('.');
		if(T_frac<10){
			UART_TxChar('0');
		}
		uartTx_number(T_frac);
		UART_TxChar('\n');
		
		_delay_ms(1000);
		
	}
}

