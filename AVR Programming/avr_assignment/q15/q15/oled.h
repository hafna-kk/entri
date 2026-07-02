/*
 * oled.h
 *
 * Created: 01-07-2026 23:15:59
 *  Author: hafna
 */ 


#ifndef OLED_H_
#define OLED_H_


void OLED_Command(uint8_t cmd);
void OLED_Data(uint8_t data);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_SetCursor(uint8_t row, uint8_t col);
void OLED_Char(char ch);
void OLED_String(char *str);



#endif /* OLED_H_ */