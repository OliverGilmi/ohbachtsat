#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OLED.h>
#include "Name.h"

const char displayName[] = "Oliver"; // beliebiger Name
const unsigned int durationName = 3000;

void name_display() {
  OLED::instance().getDisplay().clearDisplay();
  OLED::instance().getDisplay().setCursor(0, 0);
  OLED::instance().getDisplay().println(displayName);
  OLED::instance().getDisplay().display();
  delay(durationName);
}
