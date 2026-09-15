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
    
## July 13, 2026
- Updated parts list and added it to docs

## July 14, 2026
- Chose Tattu 3S 650mAh battery for now
- SPARC ruleset has no rules for batteries under 48V, so 3S is legal

## Between July 14 and September 3, 2026
- I did a bad. I stopped keeping track of progress, so here's a short bulleted list of what I've done in this time
- Modeled each component in Onshape (**did not add mass to models**)
- Modeled and printed the spin test chassis
- Bought an 850mAh battery instead of the 650mAh

## September 4, 2026
- Added mass to each component in Onshape
- Created assembly for full spin test to verify fit

## September 7, 2026
- Wrote up motor driver test sketch. Have not run it yet.

## September 10, 2026
- Remodeled spin test chassis to include receiver. Accelerometer logic requires input from transmitter.
- Updated assembly, and verified center-of-mass is close to the center
    - More adjustment needs to be done when the test is built

## September 15, 2026
- Added link to Onshape CAD files
- Committed all changes since July 14 all at once (I should have been doing periodic commits, but was too lazy to set up git on my desktop)
