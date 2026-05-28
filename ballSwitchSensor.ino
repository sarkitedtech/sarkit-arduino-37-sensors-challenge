/*
==========================================
SARKIT EdTech Project
Title: Ball Switch Module with Arduino
Description:
This project uses a ball switch (tilt sensor)
to detect movement or orientation changes.
When the switch is tilted, the LED turns ON.

Author: SARKIT EdTech
==========================================
*/

int tiltPin = 2;    // Ball switch digital output pin
int ledPin  = 12;   // LED pin

void setup() {
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int state = digitalRead(tiltPin);   // Read sensor state

  if (state == LOW) {                 // Tilt detected
    digitalWrite(ledPin, HIGH);       // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);        // Turn LED OFF
  }
}
