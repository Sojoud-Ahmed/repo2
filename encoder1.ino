// Define the pins for the encoder
const int encoderPinA = 2;
const int encoderPinB = 3;
int encoderPosition = 0;
int filteredPosition = 0;
const float alpha = 0.1;  // LPF smoothing factor
const float fc = 20.0;    // LPF cutoff frequency=fmax/10= = ((v/r)* 540) / (2 * π)/10= (2.5 * 540) / (2 * π) = 215.4/10=21.5=20 

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), ISR_EncoderB, CHANGE);
  Serial.begin(9600);
}

void loop() {
  filteredPosition += alpha * (encoderPosition - filteredPosition);
  Serial.print("Encoder position: ");
  Serial.println(filteredPosition);
  delay(10);
}

void ISR_EncoderA() {
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    encoderPosition++;
  } else {
    encoderPosition--;
  }
}

void ISR_EncoderB() {
  if (digitalRead(encoderPinB) != digitalRead(encoderPinA)) {
    encoderPosition++;
  } else {
    encoderPosition--;
  }
}
