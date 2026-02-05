/*
 * uart.h
 *
 * Created: 06-01-2026 21:01:58
 *  Author: hafna
 */ 
#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <avr/io.h>

#define F_CPU 16000000UL
#define BAUDRATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUDRATE)) - 1)

// Function Prototypes
void UART_Init(void);
void UART_TxChar(char data);
void UART_TxString(const char *str);
void UART_TxHex(uint8_t value);
void UART_TxNumber(uint32_t num);
char UART_RxChar(void);
char UART_GetChar(void);
uint8_t UART_DataAvailable(void);

#endif
