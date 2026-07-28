# FreeRTOS LED Blinking Project

## Description
This project is developed using STM32 and FreeRTOS to understand the basics of RTOS task management.

Three tasks are created to control three LEDs. Each LED blinks with a different delay time using FreeRTOS task scheduling.

## Tasks

- Green LED Task → Blinks every 1 second
- Blue LED Task → Blinks every 500 ms
- Red LED Task → Blinks every 250 ms

## Concepts Learned

- Creating FreeRTOS tasks using `xTaskCreate()`
- Starting scheduler using `vTaskStartScheduler()`
- Using `vTaskDelay()` for task timing
- GPIO control using STM32 HAL

## Output

The three LEDs blink independently at different rates, showing multitasking operation of FreeRTOS.
