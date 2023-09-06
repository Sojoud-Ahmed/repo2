const int encoderPinA = 2;
const int encoderPinB = 3;
int encoderPosition = 0;

void setup() {
pinMode(encoderPinA, INPUT_PULLUP);
pinMode(encoderPinB, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderA, CHANGE);
attachInterrupt(digitalPinToInterrupt(encoderPinB), handleEncoderB, CHANGE);
Serial.begin(9600);
}

void loop() {
Serial.print("Encoder position: ");
Serial.println(encoderPosition);
delay(500);
}

void handleEncoderA() {
if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
encoderPosition++;
} else {
encoderPosition--;
}
}

void handleEncoderB() {
if (digitalRead(encoderPinB) != digitalRead(encoderPinA)) {
encoderPosition++;
} else {
encoderPosition--;
}
}
