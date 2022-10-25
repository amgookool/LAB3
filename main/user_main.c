#include "user_main.h"

static const char *TEST = "Test";

SemaphoreHandle_t mutex_handle = NULL; // Handler for Mutex -> thing that controls which function access resource (GPIO2)

TaskHandle_t task_handle = NULL;

void app_main(void)
{
    gpio_config_t io_conf; // struct for configuring gpio pins

    // GPIO 2 IO Configuration
    io_conf.intr_type = GPIO_INTR_DISABLE;           // disable interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;                 // set as output mode
    io_conf.pin_bit_mask = (1ULL << GPIO_OUTPUT_IO); // bit mask of the pin that you want to set
    io_conf.pull_down_en = 0;                        // disable pull-down mode
    io_conf.pull_up_en = 0;                          // disable pull-up mode
    gpio_config(&io_conf);                           // configure GPIO with the given settings

    // Creating Mutex
    mutex_handle = xSemaphoreCreateMutex();

    // Give the Semaphore
    xSemaphoreGive(mutex_handle);

    /* Unit Testing: LED_ON Function */
    gpio_set_level(GPIO_OUTPUT_IO, 0);                                           // stub for setting GPIO2 (LED) to 0 (OFF)
    xTaskCreate(led_on, "led_on_task", 1024, NULL, HIGH_PRIORITY, &task_handle); // RTOS task to turn GPIO2 (LED) to 1 (ON)
    if (gpio_get_level(GPIO_OUTPUT_IO) == 1 && task_handle != NULL)              // Check if pin is high and use task handler to stop running RTOS task
    {
        ESP_LOGI(TEST,"Task has successfully triggered GPIO2 pin");
        vTaskSuspend(task_handle);
    }
    gpio_set_level(GPIO_OUTPUT_IO, 0);                                          // stub for setting GPIO2 (LED) to 0 (OFF)

    // Heap memory management
    for (;;)
        ;
}

static void active_wait()
{
    struct timeval present_tv; // Structure returned by gettimeofday function
    gettimeofday(&present_tv, NULL);

    int64_t start_time = (int64_t)present_tv.tv_sec * 1000000L + (int64_t)present_tv.tv_usec; // time since last reset in microseconds

    while (1)
    {
        gettimeofday(&present_tv, NULL);
        int64_t current_time = (int64_t)present_tv.tv_sec * 1000000L + (int64_t)present_tv.tv_usec;

        // check if 0.5 seconds have elapsed
        if ((current_time - start_time) >= 500000)
        {
            break;
        }
    }
}

static void status_message(void *pvParam)
{
    while (1)
    {
        ESP_LOGI(TEST, "The LED Status: %d\n", gpio_get_level(GPIO_OUTPUT_IO));
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delay for 1 second
    }
}

static void led_on(void *pvParam)
{
    while (1)
    {
        while (1)
        {
            if (xSemaphoreTake(mutex_handle, (TickType_t)15) == pdTRUE)
            {
                // Obtained Mutex...
                ESP_LOGI(TEST, "Turning LED ON\n");
                gpio_set_level(GPIO_OUTPUT_IO, 1);
                break;
            }
            else
            {
                continue;
            }
        }
        active_wait(); // wait for 0.5 seconds

        // Give back Mutex
        xSemaphoreGive(mutex_handle);

        // delay for 1 second
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

static void led_off(void *pvParam)
{
    while (1)
    {
        while (1)
        {
            if (xSemaphoreTake(mutex_handle, (TickType_t)15) == pdTRUE)
            {
                ESP_LOGI(TEST, "Turning LED OFF\n");
                gpio_set_level(GPIO_OUTPUT_IO, 0);
                break;
            }
            else
            {
                continue;
            }
        }
        active_wait(); // wait for 0.5 seconds

        // Give back Mutex
        xSemaphoreGive(mutex_handle);

        // delay for 1 second
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
