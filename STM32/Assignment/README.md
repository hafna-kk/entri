
## Task 1: Button-Controlled LED
- The onboard USER button (PC13) is configured as input.
- The onboard LED (PA5) is configured as output.
- Each button press toggles the LED state.
- Software debounce is used to avoid flickering.

## Task 2: Alternating External LED Blink
- Two external LEDs are connected to PA6 and PA7.
- LEDs blink alternately:
  - LED1 ON, LED2 OFF → 250 ms
  - LED2 ON, LED1 OFF → 250 ms
- This creates a 500 ms blinking cycle.
- Blinking runs continuously inside the main loop.

## Observations
- Button toggles LED reliably without flicker.
- External LEDs blink smoothly in alternating pattern.

## Demo Video
Demo video showing button toggle and alternating LED blink:  
🔗 https://drive.google.com/file/d/1nvG4ncmaw3omff2a2Ksxyt56EHiKEbTV/view
