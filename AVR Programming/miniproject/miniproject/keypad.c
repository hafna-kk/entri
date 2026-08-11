/*
 * keypad.c
 *
 * Created: 11-08-2026 15:45:43
 *  Author: hafna
 */ 
#define F_CPU 16000000UL
#include "keypad.h"
#include <util/delay.h>


/*
 * 4x3 Keypad
 *
 * Rows:
 * R1 -> PC0
 * R2 -> PC1
 * R3 -> PC2
 * R4 -> PC3
 *
 * Columns:
 * C1 -> PC4
 * C2 -> PC5
 * C3 -> PC6
 */


static const char keypad[4][3] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};


void keypad_init(void)
{
    /*
     * PC0-PC3 = outputs
     * PC4-PC6 = inputs
     */

    DDRC |= 0x0F;

    DDRC &= ~(0x70);

    /*
     * Rows HIGH
     */
    PORTC |= 0x0F;

    /*
     * Enable internal pull-ups
     * on PC4-PC6
     */
    PORTC |= 0x70;
}


char keypad_getkey(void)
{
    uint8_t row;
    uint8_t col;

    for (row = 0; row < 4; row++)
    {
        /*
         * Make all rows HIGH
         */
        PORTC |= 0x0F;

        /*
         * Make current row LOW
         */
        PORTC &= ~(1 << row);

        _delay_us(5);

        /*
         * Check three columns
         */
        for (col = 0; col < 3; col++)
        {
            /*
             * PC4, PC5, PC6
             */
            if (!(PINC & (1 << (col + 4))))
            {
                /*
                 * Debounce
                 */
                _delay_ms(20);

                /*
                 * Wait until key released
                 */
                while (!(PINC & (1 << (col + 4))))
                {
                    ;
                }

                _delay_ms(20);

                return keypad[row][col];
            }
        }
    }

    return 0;
}