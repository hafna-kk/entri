#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define led_pin GPIO_NUM_2
#define button_pin  GPIO_NUM_4


void app_main(void)
{
    gpio_set_direction(button_pin,GPIO_MODE_INPUT);
    gpio_set_pull_mode(button_pin, GPIO_PULLUP_ONLY);
    gpio_reset_pin(led_pin); // reset gpio2
    gpio_set_direction(led_pin,GPIO_MODE_OUTPUT);


    while(1)
    {
        if(gpio_get_level(button_pin)==0){
            gpio_set_level(led_pin,1);  //Pin 2 High
           
        }
        else{
             gpio_set_level(led_pin,0); // Pin 2  Low
          
        }
    vTaskDelay(pdMS_TO_TICKS(500));  // 1s delay
       
    }
}
