// AUTHOR: Het Patel (HETP-07)
// FILE: ultrasonic_bluthoothhc05.ino
// VERSION: 1.0.0
// PURPOSE: ULtrasonic  Sensor and bluetooth  example for Arduino

#include <SoftwareSerial.h>

// Define the Bluetooth module's RX and TX pins
#define BT_RX 2  // Connect HC-05 TX to Arduino pin 2
#define BT_TX 4  // Connect HC-05 RX to Arduino pin 4

// Define the pins for ultrasonic sensor
const int triggerPin = 7;
const int echoPin = 6;

long timeInMicro;
long distanceInCm;

SoftwareSerial BTSerial(BT_RX, BT_TX);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);  // Start serial communication with HC-05
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Ultrasonic sensor measurement
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  timeInMicro = pulseIn(echoPin, HIGH);
  distanceInCm = ((timeInMicro / 29) / 2);
  
  // Send distance measurement over Bluetooth
  BTSerial.println(distanceInCm);

  // Wait for a short duration before the next measurement
  delay(100);
  // basic transmit-receive data for HC 05 Bluetooth
  // Check if data is available from Serial monitor
   // if (BTSerial.available()) {
  //   BT_data = BTSerial.readString();
  //   Serial.println(BT_data);
  // }
  // if (Serial.available()) {
  //   DATA = Serial.readString();
  //   BTSerial.println(DATA);
  // }
}
