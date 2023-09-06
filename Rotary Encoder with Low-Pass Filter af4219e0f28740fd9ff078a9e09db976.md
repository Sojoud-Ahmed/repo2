# Rotary Encoder with Low-Pass Filter

This code represents  implementation for interfacing with a rotary encoder and filtering the position readings using a low-pass filter.

## Hardware Components

- Arduino Uno
- Rotary Encoder
- Wires

## Hardware Connection

- Connect the VCC and GND pins of the Encoder sensor to the respective 5V and GND pins on the Arduino board.
- Connect the channel A/B pin of the Encoder sensor to the interrupt  pins(2,3) on the Arduino board.

![kkk.PNG](Rotary%20Encoder%20with%20Low-Pass%20Filter%20af4219e0f28740fd9ff078a9e09db976/kkk.png)

## Software

### Code Functions

```c
  setup()
- Initializes the encoder pins as inputs.
- Attaches interrupt routines to both encoder pins.
- Initializes the serial communication at a baud rate of 9600.

loop()
- Calculates the filtered position of the encoder by using a complementary filter.
- Prints the filtered position to the serial monitor.
ISR_EncoderA()
- Interrupt service routine (ISR) when encoder pin A changes state.
- Determines the direction of rotation based on the current states of encoder pins A and B.
- Adjusts the encoder position based on the determined direction of rotation.

ISR_EncoderB()
- Interrupt service routine (ISR) when encoder pin B changes state.
- Determines the direction of rotation based on the current states of encoder pins A and B.
- Adjusts the encoder position based on the determined direction of rotation.
```

```c
//code snippet
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
```