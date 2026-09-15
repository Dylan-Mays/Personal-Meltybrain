#include "melty_config.h"
#include "accel_handler.h"
#include "led_driver.h"
#include <Wire.h>
#include "SparkFun_LIS331.h"

// Accelerometer + microcontroller + led w/ 330 ohm resistor = 45mA current draw

// SDA = Blue wire   | Pin 2
// SCL = Yellow wire | Pin 3
// Heading led = pin 8
void setup() {
  // put your setup code here, to run once:

  // Init Serial
  Serial.begin(115200);
  while (!Serial) {} // Wait for Serial to connect
  Serial.println("Serial initialized");

  init_accel();
  init_led();
  heading_led_on(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("X-axis reading: "); Serial.println(get_accel_force_g());
  delay(10);
}