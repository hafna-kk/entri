/*
 * miniproject.c
 *
 * Created: 01-05-2026 15:37:19
 * Author : hafna
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdint.h>

#include "lcd.h"
#include "keypad.h"
#include "servo.h"


/*
 * Correct password
 */
#define PASSWORD "1534"


int main(void)
{
    char key;

    char password[5];

    uint8_t index;


    /*
     * Initialize peripherals
     */
    lcd_init();

    keypad_init();

    servo_init();


    /*
     * Initial LCD message
     */
    lcd_clear();

    lcd_set_cursor(0, 0);
    lcd_print("PASSWORD DOOR");

    lcd_set_cursor(1, 0);
    lcd_print("LOCK SYSTEM");

    _delay_ms(2000);


    while (1)
    {
        /*
         * Clear password buffer
         */
        for (uint8_t i = 0; i < 5; i++)
        {
            password[i] = '\0';
        }

        index = 0;


        /*
         * Ask for password
         */
        lcd_clear();

        lcd_set_cursor(0, 0);
        lcd_print("Enter Password:");

        lcd_set_cursor(1, 0);


        /*
         * Read exactly 4 digits
         */
        while (index < 4)
        {
            key = keypad_getkey();

            if (key != 0)
            {
                /*
                 * Only accept numbers
                 */
                if (key >= '0' && key <= '9')
                {
                    password[index] = key;

                    /*
                     * Display * instead
                     * of actual password
                     */
                    lcd_data('*');

                    index++;
                }
            }
        }


        /*
         * Null terminate string
         */
        password[4] = '\0';


        /*
         * Compare entered password
         * with correct password
         */
        if (strcmp(password, PASSWORD) == 0)
        {
            /*
             * Correct password
             */

            lcd_clear();

            lcd_set_cursor(0, 0);
            lcd_print("Access Granted");

            lcd_set_cursor(1, 0);
            lcd_print("Door Unlocked");


            /*
             * Unlock servo
             */
            servo_unlock();


            /*
             * Keep door unlocked
             * for 5 seconds
             */
            _delay_ms(5000);


            /*
             * Lock door again
             */
            servo_lock();


            lcd_clear();

            lcd_set_cursor(0, 0);
            lcd_print("Door Locked");

            _delay_ms(1500);
        }
        else
        {
            /*
             * Wrong password
             */

            lcd_clear();

            lcd_set_cursor(0, 0);
            lcd_print("Wrong Password");

            lcd_set_cursor(1, 0);
            lcd_print("Access Denied");

            _delay_ms(2000);
        }
    }
}