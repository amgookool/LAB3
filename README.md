# Unit Testing: STATUS_MESSAGE function

The status_message function displays the status of the GPIO2 (LED) pin.

- **Purpose**: Ensure the function displays the current status of the GPIO2 (LED) pin
- **Pre-Conditions**: 3V power supply to ESP8266-01 device; Operational LED.
- **Test Input**: Conifgured GPIO2 pin, gpio pin set to 1, call 'status_message' function, gpio pin set to 1, call 'status_message' function 
- **Expected**: Respective status of gpio pin is shown
- **Test Results**: Appropiate status is displayed that reflects the status of gpio pin.
- **Test Result Evidence**: lab3_UnitTest_STATUS-MESSAGE_816008385.out
