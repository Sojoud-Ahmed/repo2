# Rotary Encoder 

This code represents  implementation for interfacing with a rotary encoder to print encoder position .

## Hardware Components

- Arduino Uno
- Rotary Encoder
- Wires

## Hardware Connection

- Connect the VCC and GND pins of the Encoder sensor to the respective 5V and GND pins on the Arduino board.
- Connect the channel A/B pin of the Encoder sensor to the interrupt  pins(2,3) on the Arduino board.
- 

![encoder.PNG](Rotary%20Encoder%20with%20Low-Pass%20Filter%20af4219e0f28740fd9ff078a9e09db976/encoder.png)

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


