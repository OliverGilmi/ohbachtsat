#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <OLED.h>
#include "Temperature_difference.h"
#define TEMP_DIFF_DHT_PIN 4 //Depends on Pin in Nano!!

DHT dhtDiff(TEMP_DIFF_DHT_PIN, DHT11);

float currentTemperature;
float storedTemperature;      // Temperatur am Ende des letzten Durchlaufs
bool hasStoredTemperature = false;

unsigned long startTimeTempDiff;
const int durationTempDiff = 5000;
const unsigned long refreshFrequencyTempDiff = 1000; // 1/1000ms = 1Hz

void tempDiffSetup() {
  dhtDiff.begin(); // initialize the sensor
}

void storeMeasurementsTempDiff() {
  currentTemperature = dhtDiff.readTemperature(); // Celsius
}

void visualizeMeasurementsTempDiff() {
  OLED::instance().getDisplay().clearDisplay();
  OLED::instance().getDisplay().setCursor(0, 0);
  if (isnan(currentTemperature)) {
    OLED::instance().getDisplay().println("Failed to read from DHT11 sensor!");
  } else {
    OLED::instance().getDisplay().println("Temp. Differenz");
    OLED::instance().getDisplay().print("Aktuell: ");
    OLED::instance().getDisplay().print(currentTemperature);
    OLED::instance().getDisplay().println("C");
    if (hasStoredTemperature) {
      OLED::instance().getDisplay().print("Diff: ");
      OLED::instance().getDisplay().print(currentTemperature - storedTemperature);
      OLED::instance().getDisplay().println("C");
    } else {
      OLED::instance().getDisplay().println("Noch kein Vergleich");
    }
  }
  OLED::instance().getDisplay().display();
}

void temperature_difference() {
    startTimeTempDiff = millis();
    unsigned long currentTime = millis(); //init
    while (currentTime - startTimeTempDiff < durationTempDiff)
    {
        currentTime = millis();
        storeMeasurementsTempDiff();
        visualizeMeasurementsTempDiff();
        delay(refreshFrequencyTempDiff);
    }
    // nach Ende der Schleife: Temperatur für den nächsten Durchlauf merken
    if (!isnan(currentTemperature)) {
      storedTemperature = currentTemperature;
      hasStoredTemperature = true;
    }
}
