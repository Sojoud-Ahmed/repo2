# Complementary Filter for MPU6050 Yaw Angle Calculation

This code represents the implementation of a complementary filter for calculating the yaw angle of an MPU6050 sensor using both accelerometer and gyroscope data.

## Hardware Components

- Arduino Uno
- wires
- MPU6050 sensor
    
    ![mpu3.PNG](Complementary%20Filter%20for%20MPU6050%20Yaw%20Angle%20Calcula%200947e9da8903486bb624f924ad2a293f/mpu3.png)
    

## Hardware Connection

1. Connect the VCC and GND pins of the MPU6050 sensor to the respective 5V and GND pins on the Arduino board.
2. Connect the SDA/SCL pin of the MPU6050 sensor to the SDA/SCL pin on the Arduino board.

![mpu.PNG](Complementary%20Filter%20for%20MPU6050%20Yaw%20Angle%20Calcula%200947e9da8903486bb624f924ad2a293f/mpu.png)

# Software

## Code Explanation

- The code uses the Wire library to communicate with the MPU6050 sensor over the I2C interface.
- The complementary filter is used to combine the gyro and accelerometer data for more accurate results
- The yaw angle is calculated using both gyroscope and accelerometer data.

### Code Functions

```c
 setup()
- Initializes the serial communication at a baud rate of 9600.
- Initializes the Wire library for I2C communication.
- Configures the gyroscope range to 250 deg/s.
- Configures the accelerometer range to +/- 2g.

loop()
- Reads the accelerometer and gyroscope data from the MPU6050 sensor.
- Converts the raw sensor data to physical values.
- Calculates the yaw angle using both gyroscope and accelerometer data.
- Combine gyro and accelerometer data using complementary filterThe (can be thought of as a union of two different filters: a high-pass filter for the gyroscope and a low-pass filter for the accelerometer).
- Prints the calculated yaw angle to the serial monitor.
```

```c
//Code Snippet to Clarify The Functions
void setup() {

  Serial.begin(9600); // Initializes the serial communication at a baud rate of 9600.
  Wire.begin(); 
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(PWR_MGMT_1); 
  Wire.write(0); 
  Wire.endTransmission();
  // Configure MPU6050 gyroscope range to 250 deg/s
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x00);
  Wire.endTransmission();
  // Configure MPU6050 accelerometer range to +/- 2g
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x00);
  Wire.endTransmission();
}

void loop() {
  float accel_x, accel_y, accel_z, gyro_z;
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_X_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDR, 6);
 //Converts the raw sensor data to physical  values.
  accel_x = (Wire.read() << 8 | Wire.read())/ 16384.0; // Convert to g's
  accel_y = (Wire.read() << 8 | Wire.read())/ 16384.0;
  accel_z =(Wire.read() << 8 | Wire.read()) / 16384.0;
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(GYRO_Z_H);
  Wire.endTransmission();
  Wire.requestFrom(MPU_ADDR,2);
  gyro_z =  (Wire.read() << 8 | Wire.read())/ gyro_scale_factor; // Convert to deg/s
  // Calculates the yaw angle using both gyroscope and accelerometer data.
  //1. Calculate yaw angle using gyro data
  gyro_yaw_angle += gyro_z * 0.01; // Sampling time is 10 ms
  
  // 2.Calculate yaw angle using accelerometer data
  accel_yaw_angle = atan2(-accel_x, accel_y) * 180.0 / PI; // Convert to degrees
  
  // Combine gyro and accelerometer data using complementary filter
  yaw_angle = alpha * gyro_yaw_angle + (1.0 - alpha) * accel_yaw_angle;
  //Prints the calculated yaw angle to the serial monitor.
  Serial.print("Yaw angle: ");
  Serial.print(yaw_angle);
  Serial.println("`\n");

```

### Q: If the Sensor is surrounded by a noisy environment, what type of
filter could used and what is the recommended cutoff frequency
depending on the sensor datasheet?

Ans: A low-pass filter can be used to filter out noise from the sensor, allows low-frequency signals to pass through and cuts off high-frequency signals.

cutoff frequency = bandwidth / 10=260/10=26HZ

# Resources

[MPU-6050 pdf, MPU-6050 Description, MPU-6050 Datasheet, MPU-6050 view ::: ALLDATASHEET :::](https://pdf1.alldatasheet.com/datasheet-pdf/view/1132807/TDK/MPU-6050.html#:~:text=MPU-6050%20Datasheet%20%28PDF%29%20-%20TDK%20Electronics%20If%20the,Similar%20Description%20-%20MPU-6050%20More%20results%20Link%20URL)

[datasheet.pdf](Complementary%20Filter%20for%20MPU6050%20Yaw%20Angle%20Calcula%200947e9da8903486bb624f924ad2a293f/datasheet.pdf)
