#include <Wire.h>
#define MPU_ADDR 0x68
#define GYRO_CONFIG 0x1B
#define GYRO_Z_H 0x47
#define GYRO_Z_L 0x48
#define ACCEL_CONFIG 0x1C
#define ACCEL_X_H 0x3B
#define ACCEL_X_L 0x3C
#define ACCEL_Y_H 0x3D
#define ACCEL_Y_L 0x3E
#define ACCEL_Z_H 0x3F
#define ACCEL_Z_L 0x40
#define PWR_MGMT_1 0x6B
#define ACCEL_LSB_2G 16384.0 // MPU6050 accelerometer sensitivity at +/- 2g
float yaw_angle = 0.0;
float gyro_yaw_angle = 0.0;
float accel_yaw_angle = 0.0;

const float alpha = 0.97; // Complementary filter coefficient
const float gyro_scale_factor = 131; // Gyroscope scale factor in LSB/deg/s

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

  delay(10); 
}
/*
#include <Wire.h>

#define MPU6050_ADDR 0x68
#define GYRO_LSB_250DPS 131.0
#define ACCEL_LSB_2G 16384.0 // MPU6050 accelerometer sensitivity at +/- 2g

// Complementary filter gain
double alpha = 0.97;

// Yaw estimation variables
double yaw = 0;
double old_yaw = 0;
int old_time = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); //PWR_MGMT_1 register
  Wire.write(0);
  Wire.endTransmission();
  // Set gyro configuration
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x1B); //GYRO_CONFIG register
  Wire.write(0x00); //Full scale range = +/- 250 degrees per second
  Wire.endTransmission();

  // Set accel configuration
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x1C); //ACCEL_CONFIG register
  Wire.write(0x00); //Full scale range = +/- 2g
  Wire.endTransmission();
}

void loop() {
  // Read data from MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);  // Starting with register 0x3B (ACCEL_XOUT_H) 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR,12, true); // Request 12 registers starting from 0x3B
 
  double gyro_x =( Wire.read() << 8 | Wire.read())/GYRO_LSB_250DPS; 
  double gyro_y = ( Wire.read() << 8 | Wire.read())/GYRO_LSB_250DPS; 
  double gyro_Z =( Wire.read() << 8 | Wire.read())/GYRO_LSB_250DPS; 

  
  double accel_x =( Wire.read() << 8 | Wire.read())/ ACCEL_LSB_2G;
  double accel_y=( Wire.read() << 8 | Wire.read())/ ACCEL_LSB_2G;
  double accel_Z= ( Wire.read() << 8 | Wire.read())/ ACCEL_LSB_2G;

  // Calculate yaw angle using accelerometer data
  double accel_yaw = atan2(-accel_x, accel_y) * 180.0 / PI; // Convert to degrees


  // Update yaw estimate using the complementary filter
  int current_time = millis();
  double dt = double(current_time - old_time) / 1000.0;
  old_time = current_time;

  double gyro_yaw = ((gyro_Z+ old_yaw)/2.0) * dt;
  yaw += alpha * gyro_yaw + (1.0 - alpha) * accel_yaw;

  // Update variables for the next iteration
  old_yaw = gyro_Z;

  // Output the Yaw angle
  Serial.print("Yaw angle: ");
  Serial.println(yaw);
  delay(10);
}*/
