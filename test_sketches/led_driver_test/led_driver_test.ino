#include "melty_config.h"
#include "led_driver.h"

// Heading led = pin 8
void setup() {
  // put your setup code here, to run once:

  // Init Serial
  Serial.begin(115200);
  while (!Serial) {}; // Wait for Serial to connect
  Serial.println("Serial initialized");

  init_led();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Static on
  Serial.println("Static on");
  heading_led_on(0);
  delay(2500);
  heading_led_off();
  delay(1000);
  
  // Shimmer on
  Serial.println("Shimmering");

  unsigned long int start = micros();
  while (micros() - start < 2500000) {
    heading_led_on(1);
  }

  heading_led_off();
  delay(1000);
}