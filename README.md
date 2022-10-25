# Unit Testing: LED_ON function

The LED_ON function sets the GPIO2 pin (On board LED) high.

- **Purpose**: Ensure that the functions sets GPIO2 pin high 

- **Pre-Conditions**: 3V power supply to ESP8266-01 device; Operational LED 

- **Test Input**: Conifgured GPIO2 pin, gpio pin set to LOW (0), call 'led_on' function

- **Expected**: The LED turns on 

- **Test Results**: The LED turned on 

- **Test Result Evidence**: lab3_UnitTest_LED-ON_816008385.out