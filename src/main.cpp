#include <Arduino.h>
#include "Blink.h"
#include "OLED.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Gyro.h"
#include "Temperature_humidity.h"
#include "Brightness.h"

void setup() {
  
  blink_setup();
  gyro_setup();
  dht11Setup();
  setupBH1750();
  OLED::instance();
}

void loop() {
  gyro_gyrometer();
  gyro_accelerometer();
  temperature_humidity();
  bh1750();
}