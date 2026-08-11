#  Password-Based Door Lock System

An AVR-based password door lock system using a **4×3 keypad, 16×2 LCD, and servo motor**.

##  Components

* AVR Microcontroller
* 4×3 Keypad
* 16×2 LCD
* Servo Motor

##  Working

1. The LCD asks the user to enter a 4-digit password.
2. Password digits are displayed as `****`.
3. The entered password is compared with the stored password.
4. If the password is correct:

   * LCD displays **Access Granted**
   * Servo unlocks the door
   * Door remains unlocked for **5 seconds**
   * Servo locks the door again
5. If the password is incorrect:

   * LCD displays **Access Denied**
   * Door remains locked

##  Default Password

```c
#define PASSWORD "1534"
```

## 📁 Files

```text
main.c
lcd.c
lcd.h
keypad.c
keypad.h
servo.c
servo.h
README.md
```

## 🛠️ Concepts Used

* AVR GPIO
* 4×3 Keypad Interfacing
* LCD Interfacing
* Servo Motor / PWM
* Embedded C
* Password Authentication

