## rc_handler
- Uses PWM, not iBUS
- Please note the unintuitive controls
- 3 true interrupt pins needed
    - Reading the control input is the most important thing, so interrupt pins are used for precise timing.
    - The exception is when the rc data is being used. You don't want it to update values in the middle of use.
- Sparkfun Pro Micro has 5 interrupt pins (provided by the Atmega 32u4). Hardware changes already done.
- FS-iA6B has 6 channels. No changes to code needed.
**Assessment: No changes to code or hardware needed.**

## accel_handler
- Meant to work with H3LIS331DL
- Verified to work with sparkfun and adafruit versions
- Uses Sparkfun's LIS331 library on the 400G setting (can configure to 200G for better accuracy, depending on forces)
- Uses I2C. Can use qwiic connector, but it's probably insecure in a combat robot.
- Default I2C address works with my board
- Only uses the accelerometer's x-axis
**Assessment: No changes to code or hardware needed. Make sure accelerometer experiences no more than 400Gs.**

## battery_monitor
- Not required, but it's a few extra resistors. I'll probably include it anyways.
- Requires configuration in melty_config to work
**Assessment: No code alteration needed, but it's optional to modify hardware.**

## config_storage
- Uses EEPROM to store accel radius, accel offset, and LED offset
- EEPROM conceptually acts as an ssd or hdd in a pc
- Only writes during setup
- LED offset changes angular position of LED flash to make it line up with translation direction
**Assessment: No changes to code or hardware needed.**

## led_driver
- Expects a standard LED. I have a 5V LED strip.
- Code can be changed fairly easily to work with LED strip.
- LED strip requires more wiring due to current draw, and drains battery faster.
**Assessment: No changes to code needed. Stick with single LED for now. Can modify to work with strip later.**

## melty_config
- Change when needed
- Most important things are pin mappings, accelerometer settings, and led offset
**Assessment: No changes to hardware. Code is changed as needed.**

## motor_driver
- Binary throttle is for brushed motors only. It is not PWM
- MUST switch off binary throttle in melty_config
- ESC's work with 490 Hz PWM, but need to make sure pulse widths are between 1000-2000us
- Might have issues with PWM motor off/coast being 100 (800us). ESC might not init. Need to test. Bump up if it fails.
**Assessment: No changes to hardware needed. Only melty_config needs to be messed with to work with ESCs.**

## spin_control
- AAAAAAAAAAAAAAAAAA
- This is where all the magic happens
- Helpful for understanding the logic for how bot moves, but nothing relevant to hardware here
- Will need to understand and modify code for bench test
    - Code assumes wheels are spinning. I need to modify motor logic to spin up/down with throttle instead.
**Assessment: Further inspection needed for bench test, but requires no hardware or code modifications for full build.**

## openmelt.ino
- Pull control stick back for 0.75s while idle to enter/exit config mode
- **When making modifications, make sure failsafes (rc good, watchdog, receiver failsafe) are all working properly**
**Assessment: No changes to code or hardware needed.**
