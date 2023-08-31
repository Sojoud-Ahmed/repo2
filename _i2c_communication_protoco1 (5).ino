#include <Wire.h>

const int button1 = 7;
const int button2 = 6;

void setup() {
  Wire.begin();  // Initialize I2C communication
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
}

void loop() {
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);

  Wire.beginTransmission(9);  // Address of the receiving Arduino
  Wire.write(button1State);
  Wire.write(button2State);
  Wire.endTransmission();}