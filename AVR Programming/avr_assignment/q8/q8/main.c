/*objective: Write a program to control the brightness of an LED or the speed of a
small DC motor using the hardware PWM capability of Timer0.
Requirements: The program must initialize Timer0 in Fast PWM mode with the
output directed to the OC0A pin (PORTD Pin 6). The system should start with a 25%
duty cycle. A push-button connected to an input pin should be used to cycle the duty
cycle through four levels: 25%, 50%, 75%, and 100% OFF. Each time the button is
pressed, the program should update the Output Compare Register (OCR0A) to the
appropriate value corresponding to the selected duty cycle. The duty cycle sequence
should repeat continuously in a loop (i.e., after 100%, it should return to 25%).
The button input should be properly debounced (either via software delay or logic)
to avoid multiple unintended triggers.
* q9.c
*
* Created: 10-06-2026 10:55:52
* Author : hafna
*/


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Function to update duty cycle
void update_duty_cycle(uint8_t level)
{
switch(level)
{
case 0:
OCR0A = 64;    // 25%
break;

case 1:
OCR0A = 128;   // 50%
break;

case 2:
OCR0A = 192;   // 75%
break;

case 3:
OCR0A = 255;   // 100%
break;

case 4:
OCR0A = 0;   // off
break;
}
}

int main(void)
{
// PWM output (OC0A)
DDRD |= (1 << DDD6);

// Motor direction pins
DDRD |= (1 << DDD0) | (1 << DDD1);

// Set motor direction: Forward
PORTD |= (1 << PD0);      // IN1 = HIGH
PORTD &= ~(1 << PD1);     // IN2 = LOW

// Push button
DDRD &= ~(1 << DDD2);
PORTD |= (1 << PORTD2);   // Enable pull-up

// Timer0 Fast PWM, Non-Inverting
TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
TCCR0B = (1 << CS01) | (1 << CS00);   // Prescaler = 64

uint8_t level = 0;

// Start with 25% speed
update_duty_cycle(level);

while (1)
{
if (!(PIND & (1 << PIND2)))    // Button pressed
{
_delay_ms(20);            // Debounce

if (!(PIND & (1 << PIND2)))
{
level++;

if (level > 4)
{
level = 0;
}

update_duty_cycle(level);

// Wait until button is released
while (!(PIND & (1 << PIND2)));

_delay_ms(20);
}
}
}
} 