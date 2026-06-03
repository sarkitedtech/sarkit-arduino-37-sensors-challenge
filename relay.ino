/*
==========================================
SARKIT EdTech Project
Title: Relay Module Control using Serial Monitor
Description:
This project controls a relay module using
commands sent through the Arduino Serial
Monitor. Type "ON" to activate the relay
and "OFF" to deactivate it.

Author: SARKIT EdTech
==========================================
*/

int relayPin = 7;   // Relay control pin

void setup() {

  pinMode(relayPin, OUTPUT);

  // Relay OFF by default (Active LOW relay)
  digitalWrite(relayPin, HIGH);

  Serial.begin(9600);

  Serial.println("Send ON or OFF");
}

void loop() {

  // Check for incoming serial data
  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');
    cmd.trim();   // Remove spaces and newlines

    // Turn relay ON
    if (cmd == "ON") {

      digitalWrite(relayPin, LOW);

      Serial.println("Relay ON");
    }

    // Turn relay OFF
    if (cmd == "OFF") {

      digitalWrite(relayPin, HIGH);

      Serial.println("Relay OFF");
    }
  }
}
