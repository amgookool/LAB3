# General Discussion on Unit Testing

For unit testing of the led_on function, I created my own test driver function which configures the GPIO pin and stubs the pin with the function.
It checks the value of the pin and returns an appropriate message to inform if the function was successfully executed or not. 

Creating my own driver function was beneficial to me as a student as it allowed me to actively think about the steps required to execute the test.
Additionally, it allowed me to fully explore more into the specific ESP8266_RTOS_SDK functions that can be used to execute the testing.

Since this project consists of only three task functions, the creation of the unit_test functions for each task functions is manageable. However, for larger projects (Group project) which contains many of task functions, the use of the unity test framework would be suitable as it would return appropriate test statistics.

[Resource on Unity Test Framework  ](http://www.throwtheswitch.org/unity)


# Unit Testing: LED_ON function

The LED_ON function sets the GPIO2 pin (On board LED) high.

- **Purpose**: Ensure that the functions sets GPIO2 pin high 

- **Pre-Conditions**: 3V power supply to ESP8266-01 device; Operational LED 

- **Test Input**: Configured GPIO2 pin, gpio pin set to LOW (0), call 'led_on' function

- **Expected**: The LED turns on 

- **Test Results**: The LED turned on 

- **Test Result Evidence**: lab3_UnitTest_LED-ON_816008385.out