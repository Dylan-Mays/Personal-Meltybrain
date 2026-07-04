#include "melty_config.h"
#include "led_driver.h"
#include "rc_handler.h"

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

void setup() {
  // put your setup code here, to run once:

  // Init led and rc pins
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
  Serial.print("Throttle percent: "); Serial.println(rc_get_throttle_percent());
  Serial.print("Leftright pulse length: "); Serial.println(rc_get_leftright());
  Serial.print("Forback position: "); Serial.println(rc_get_forback());
  delay(1000);
}
