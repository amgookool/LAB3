#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "freertos/semphr.h"

#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_system.h"

#include <esp_sleep.h>

#include "sys/time.h"

#define GPIO_OUTPUT_IO 2 // LED

#define HIGH_PRIORITY 3
#define MEDIUM_PRIORITY 2
#define LOW_PRIORITY 1

//  Function Prototypes
static void active_wait();                 // Function for actively waiting for 0.5 seconds
static void status_message(void *pvParam); // Task function for printing status message
static void led_on(void *pvParam);         // Task function for turning on the LED (GPIO2 == 1)
static void led_off(void *pvParam);        // Task function for turning off the LED (GPIO2 == 0)
