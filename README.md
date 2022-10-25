# Unit Testing: LED_OFF function 

The LED_OFF function sets the GPIO2 pin (On-board LED) low.

- **Purpose**: Ensure that the function sets the gpio pin low.

- **Pre-Conditions**: 3V power supply to ESP8266-01 device; Operational LED.

- **Test Input**: Conifgured GPIO2 pin, gpio pin set to HIGH (1), call 'led_off' function.

- **Expected**: The LED turns off 

- **Test Results**: The LED turned off 

- **Test Result Evidence**: lab3_UnitTest_LED-OFF_816008385.out