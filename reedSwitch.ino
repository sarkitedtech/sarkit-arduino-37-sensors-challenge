/*
==========================================
SARKIT EdTech Project
Title: Reed Switch Magnetic Sensor with Arduino
Description:
This project uses a Reed Switch Sensor to
detect the presence of a magnet. When a
magnet comes near the sensor, an LED turns ON
and the sensor state is displayed on the
Serial Monitor.

Author: SARKIT EdTech
==========================================
*/

int reedPin = 2;   // Reed switch sensor pin
int ledPin  = 8;   // LED pin

void setup() {

  pinMode(reedPin, INPUT_PULLUP);   // Enable internal pull-up resistor
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int state = digitalRead(reedPin);   // Read reed switch state

  Serial.print("Reed State: ");
  Serial.println(state);

  // Magnet detected
  if (state == LOW) {

    digitalWrite(ledPin, HIGH);   // Turn LED ON

  } else {

    digitalWrite(ledPin, LOW);    // Turn LED OFF
  }

  delay(100);   // Small delay for stable readings
}
