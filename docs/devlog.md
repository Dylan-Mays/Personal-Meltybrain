## June 29, 2026
- Soldered header pins to sparkfun pro micro
- Audited rc_handler
    - Figured out control logic
    - Learned it uses PWM and not iBUS
    - Also learned number of interrupt pins caused compatibility issues with certain boards
    
## July 2, 2026
- Audited all openmelt code for required modifications to code/hardware
- Also learned how code worked to tune tests for usefulness

## July 3, 2026
- Installed board package for Pro Micro
- Tested rc handler, and most of led driver (missing shimmer, but led_driver is so simple, it doesn't need testing)
- Verified failsafe for iA6B
    - I did this by turning off the transmitter while main loop was running. Throttle immediately jumped to 0.  

**Important notes on RC behavior**
- When receiver is first powered, it does not send any interrupts
- Once it receives a signal from the transmitter, it does not stop sending interrupts until it loses power again, even if the transmitter is turned off
- This means the rc signal is technically healthy (and in a benign state because of failsafe), even if transmitter is off

## July 5, 2026
- Tested Adafruit accelerometer using accel_handler with qwiic to pins connector
    - 400G had small offset (corrected for during setup), and roughly +-0.7G error (normal).
    - 200G had almost no offset, and roughly +-0.3G error.
- Tested led_driver. The standard on worked (it would be concerning if it didn't), but the shimmer is weird.
    - Shimmer (assuming its called continuously) turns the LED on and off at 488 Hz, inperceptible to the human eye unless the bot is spinning
    - I need to figure out when shimmer is supposed to be called, because that's strange. Issue added.
