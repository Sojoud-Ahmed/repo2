#include <Wire.h>

const int ledPin= 13;

void setup() {
  Wire.begin(9);  // Address of this Arduino for I2C communication
  Wire.onReceive(check);  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
 
}

void check(int numBytes) {
if (Wire.available() >= 2) { 
    int button1State = Wire.read();
    int button2State = Wire.read();

    // Determine LED intensity and message based on button states
    int led_Intensity = 0;
    String message = "No message";
  
    if (button1State == 0 && button2State == 0) {
      led_Intensity = 0;
      message = "No message";
    } else if (button1State == 1 && button2State == 0) {
      led_Intensity = 128;//50% of MAX
      message = "Vector focused";
    } else if (button1State == 0 && button2State == 1) {
      led_Intensity = 191; //75% of MAX
      message = "Vector distracted";
    } else  {
      led_Intensity = 255;// 100% of Max
      message = "Glitch";
    }

   analogWrite(ledPin, led_Intensity);
    Serial.println(led_Intensity);
    Serial.println(message);
}}