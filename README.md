## Integration Testing

The integration test evaluated the functions being called and not the delays being called.

- **Purpose**: Ensures the sequential calling of appropriate functions.

- **Pre-Conditions**: 3V power supply to ESP8266-01 device; Operational LED.

- **Test Input**: Configured GPIO2 pin, call led_on, call status_msg, call led_off

- **Expected**: LED light turns on, status message is displayed, LED turns off and a status message is displayed.

- **Test Results**: LED light turns on, status message is displayed (shows 1), LED turns off, a status message is displayed (shows 0).

- **Test Result Evidence**: lab3_IntegrationTesting_816008385.out

The test was conducted via a driver function I created for testing the integration of the different task components. Additionally, break statements were included at the end of each task function to ensure the switching of the pin resource to different tasks  via the mutex handle.

The creation of the driver function is beneficial as this would ensure the task functions are executed when we look at the output of compiled program. The integration test is successful since the mutex handler was able to share the resource pin (GPIO 2) with both led_on and led_off functions.  
