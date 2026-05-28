#include <OneWire.h>
#include <DallasTemperature.h>

/*
==========================================
SARKIT EdTech Project
Title: DS18B20 Temperature Sensor with Arduino
Description:
This project reads temperature data from
the DS18B20 digital temperature sensor
and displays it on the Serial Monitor.

Author: SARKIT EdTech
==========================================
*/

#define ONE_WIRE_BUS 2   // DS18B20 data pin

// Create OneWire object
OneWire oneWire(ONE_WIRE_BUS);

// Pass OneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup() {

  Serial.begin(9600);

  // Initialize sensor
  sensors.begin();
}

void loop() {

  // Request temperature reading
  sensors.requestTemperatures();

  // Read temperature in Celsius
  float tempC = sensors.getTempCByIndex(0);

  // Display temperature
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  delay(1000);   // Update every 1 second
}
