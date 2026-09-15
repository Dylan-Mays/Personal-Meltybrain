#include "motor_driver.h"
#include "rc_handler.h"
#include "led_driver.h"
#include "melty_config.h"

// This function is copied from openmelt.ino
//loops until a good RC signal is detected and throttle is zero (assures safe start)
static void wait_for_rc_good_and_zero_throttle() {

  while (rc_signal_is_healthy() == false || rc_get_throttle_percent() > 0) {

    //"slow on/off" for LED while waiting for signal
    heading_led_on(0); delay(250);
    heading_led_off(); delay(250);
    
    // I don't need watchdog for this

    // //services watchdog and echo diagnostics while we are waiting for RC signal
    // service_watchdog();
    // echo_diagnostics();
  }
}

// Motor 1 pin = 9
// Throttle pin = 0
void setup() {
  // put your setup code here, to run once:

  // Init motors, led, and rc pins
  init_motors();
  init_led();
  init_rc();

  // Init serial monitor
  Serial.begin(115200);
  while (!Serial) {}   // blocks until Serial Monitor actually connects
  Serial.println("Serial started");

// Wait for healthy rc signal
#ifdef VERIFY_RC_THROTTLE_ZERO_AT_BOOT 
  wait_for_rc_good_and_zero_throttle();     //Wait for good RC signal at zero throttle
  delay(MAX_MS_BETWEEN_RC_UPDATES + 1);     //Wait for first RC signal to have expired
  wait_for_rc_good_and_zero_throttle();     //Verify RC signal is still good / zero throttle
#endif
}

void loop() {
  // put your main code here, to run repeatedly:
  float throttle_percent = rc_get_throttle_percent();

  // Flash heading led twice to indicate motor turned on
  heading_led_on(0);
  delay(250);
  heading_led_off();
  delay(250);
  heading_led_on(0);
  delay(250);
  heading_led_off();


  motor_1_on(throttle_percent);

  delay(10000) // 10 seconds to mess with the throttle

  // Flash heading led twice to indicate motor turned to coast (same as off)
  heading_led_on(0);
  delay(250);
  heading_led_off();
  delay(250);
  heading_led_on(0);
  delay(250);
  heading_led_off();

  motor_1_coast(); // Should be the same as off, but ok

  delay(5000); // coast for 5 seconds

  // Flash heading led twice to indicate motor turned off
  heading_led_on(0);
  delay(250);
  heading_led_off();
  delay(250);
  heading_led_on(0);
  delay(250);
  heading_led_off();

  motor_1_off();

  delay(5000); // Turn off for 5 seconds

}
