# Integration and Verfication Testing

Since the requirements were established in advance and implementation was completed to satisfy the requirements, the integration and verification test were conducted simultaneously.

## Integration Testing

The integration test evaluated the functions being called and not the delays being called.

- **Purpose**: Ensures the sequential calling of appropiate functions.
- **Pre-Conditions**: 3V power supply to ESP8266-01 device; Operational LED.
- **Test Input**: Conifgured GPIO2 pin, call led_on, call status_msg, call led_off
- **Expected**: LED light turns on, status message is displayed, LED turns off and a status message is diplayed.
- **Test Results**: LED light turns on, status message is displayed (shows 1), LED turns off, a status message is diplayed (shows 0).
- **Test Result Evidence**: lab3_IntegrationVerification_816008385.out

## Verification Testing

The verification test evaluated the delay times used in each of the functions called. This test is conducted to verify the system meeting its specified requirements.

**Requirement Specification:**

1. Task 1: Turn GPIO2 pin HIGH (ON); actively wait for 0.5 seconds; task-delay for 1 second.
1. Task 2: Turn GPIO2 pin LOW (OFF); actively wait for 0.5 seconds; task-delay for 1 second
1. Task 3: Prints the status of GPIO2 pin; task delay for 1 second
1. Task 1 and Task 2 functions manage access to GPIO pin using a mutex
1. Each task has its own Priority Level.

- **Purpose**: Ensures that the system meets its requirements.
- **Test Input**: Conifgured GPIO2 pin, call 'led_on' function, call 'status_message' function, call 'led_off' function
- **Expected**: LED light turns on for 1.5 seconds, status message shows a value of 1 for 1 second, LED light turns off for 1.5 seconds, status message displayed shows a value of 0 for 1 second.
- **Test Results**: LED light turns on for 1.5 seconds, status message displayed value of 1 for 1 second, LED light turns off for 1.5 seconds, status message displayed value of 0 for 1 second.
- **Test Result Evidence**: lab3_IntegrationVerification_816008385.out
