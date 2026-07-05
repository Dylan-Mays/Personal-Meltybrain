#include "melty_config.h"
#include "accel_handler.h"
#include <Wire.h>
#include "SparkFun_LIS331.h"

// SDA = Blue wire   | Pin 2
// SCL = Yellow wire | Pin 3
void setup() {
  // put your setup code here, to run once:

  // Init Serial
  Serial.begin(115200);
  while (!Serial) {} // Wait for Serial to connect
  Serial.println("Serial initialized");

  init_accel();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("X-axis reading: "); Serial.println(get_accel_force_g());
  delay(100);
}