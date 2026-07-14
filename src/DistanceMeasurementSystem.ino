#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (I2C Address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// HC-SR04 Pins
const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {

  // Clear Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send Trigger Pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read Echo Pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate Distance (cm)
  distance = duration * 0.0343 / 2;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  lcd.setCursor(0, 1);
  lcd.print(distance, 2);
  lcd.print(" cm   ");

  // Print to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
