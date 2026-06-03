/*
==========================================
SARKIT EdTech Project
Title: Vibration Sensor Alarm using Arduino
Description:
This project uses a vibration sensor to
detect movement or vibration. When vibration
is detected, a buzzer is activated and the
sensor status is displayed on the Serial Monitor.

Author: SARKIT EdTech
==========================================
*/

int sensor = 2;   // Vibration sensor output pin
int buzzer = 8;   // Buzzer pin

void setup() {

  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int state = digitalRead(sensor);   // Read sensor state

  Serial.println(state);

  // Vibration detection logic
  if (state == HIGH) {

    digitalWrite(buzzer, HIGH);   // Turn buzzer ON

  } else {

    digitalWrite(buzzer, LOW);    // Turn buzzer OFF
  }

  delay(100);   // Small delay for stable readings
}
