/*
==========================================
SARKIT EdTech Project
Title: Flame Detector using Arduino
Description:
This project detects flame using a flame sensor.
When flame is detected, a buzzer is activated
and status is sent via Serial Monitor.

Author: SARKIT EdTech
==========================================
*/

// Pin Definitions
#define flamePin 2     // Flame sensor digital output pin
#define buzzer   8     // Buzzer pin


// ==============================
// SETUP FUNCTION
// ==============================
void setup() {

  // Configure pin modes
  pinMode(flamePin, INPUT);
  pinMode(buzzer, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}


// ==============================
// MAIN LOOP
// ==============================
void loop() {

  // Read flame sensor value
  int flameDetected = digitalRead(flamePin);


  // ==============================
  // FLAME DETECTION LOGIC
  // ==============================
  if (flameDetected == HIGH) {

    // Turn ON buzzer
    digitalWrite(buzzer, HIGH);

    // Send alert message
    Serial.println("🔥 Flame Detected!");

  } else {

    // Turn OFF buzzer
    digitalWrite(buzzer, LOW);

    // Send safe status
    Serial.println("✅ No Flame");
  }


  // Small delay to stabilize readings
  delay(200);
}