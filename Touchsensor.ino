/*
==========================================
SARKIT EdTech Project
Title: TTP223 Capacitive Touch Sensor with Buzzer
Description:
This project uses the TTP223 Capacitive
Touch Sensor to detect touch input.
When the sensor is touched, the buzzer
produces a sound.

Author: SARKIT EdTech
==========================================
*/

int touchPin = 2;    // TTP223 sensor output pin
int buzzerPin = 8;   // Buzzer pin

void setup() {

  pinMode(touchPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int touchState = digitalRead(touchPin);   // Read touch sensor

  Serial.println(touchState);


  // Touch detection logic
  if (touchState == HIGH) {

    tone(buzzerPin, 1800);   // Generate 1.8 kHz tone

  } else {

    noTone(buzzerPin);       // Stop buzzer
  }

  delay(100);   // Small delay for stable readings
}
