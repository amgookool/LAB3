## Verification Testing

The verification test evaluated the delay times used in each of the functions called. This test is conducted to verify the system meeting its specified requirements.

**Requirement Specification:**

1. Task 1: Turn GPIO2 pin HIGH (ON); actively wait for 0.5 seconds; task-delay for 1 second.
1. Task 2: Turn GPIO2 pin LOW (OFF); actively wait for 0.5 seconds; task-delay for 1 second
1. Task 3: Prints the status of GPIO2 pin; task delay for 1 second
1. Task 1 and Task 2 functions manage access to GPIO pin using a mutex
1. Each task has its own Priority Level.

- **Purpose**: Ensures that the system meets its requirements.

- **Test Input**: Configured GPIO2 pin, call 'led_on' function, call 'status_message' function, call 'led_off' function

- **Expected**: LED light turns on for 1.5 seconds, status message shows a value of 1 for 1 second, LED light turns off for 1.5 seconds, status message displayed shows a value of 0 for 1 second.

- **Test Results**: LED light turns on for 1.5 seconds, status message displayed value of 1 for 1 second, LED light turns off for 1.5 seconds, status message displayed value of 0 for 1 second.

- **Test Result Evidence**: lab3_VerificationTesting_816008385.out

For verifying if the system met its requirements, a camera and a stop watch were used. 
The camera was used to video the execution of the program during runtime. This gave visual verification of requirements. 

The stopwatch along with the video can be used to verify the active wait for 0.5 seconds. However, it should be noted that there may be human error when recording the time of the active wait when switching who has access to the GPIO pin resource.  