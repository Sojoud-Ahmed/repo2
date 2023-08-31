
/*File: task1.4
 * Author: Sojoud Ahmed
 * Description:calculate the better measurement of of the missile projectile by Averaging methods.
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX_LENGTH 10

int main()
{   int i;
    float AVG[MAX_LENGTH],ACCURACY[2],
    MPU6050[MAX_LENGTH]= {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14,-0.26},
    BNo55[MAX_LENGTH]= {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79,-2.69};
/*
// or loop to insert elements of arrays,and accuracy

    for(i=0;i<MAX_LENGTH;i++){
    printf("MPU6050[%d]:\n",i);
    scanf("%f",&MPU6050[i]);
    printf("BNo55[%d]:\n",i);
    scanf("%f",&BNo55[i]);}*/
  // Input accuracy for first two sensors
    printf("Enter accuracy for MPU6050 sensor: ");
    scanf("%f", &ACCURACY[0]);
    printf("Enter accuracy for BNo55 sensor: ");
    scanf("%f", &ACCURACY[1]);
//to calculate& print average array
    for(i=0;i<MAX_LENGTH;i++)
{
    AVG[i]=((MPU6050[i]*ACCURACY[0])+(BNo55[i]*ACCURACY[1]) )/2;//Accuracy[0] for MPU6050,[1] for BNo55
     printf("AVG[%d] = %f\n",i, AVG[i]);}
   return 0;}
    /*
//Another Solution:

float MPU6050[MAX_LENGTH] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14,-0.26};

float BNo50[MAX_LENGTH] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79,-2.69};


float kalman_update( float M1,float M2) {
    // Kalman filter parameters
    float Q = 0.11;//process noise covariance
    float R=0.96;  //covariance of the measurement noise
    float x = 0.0; // State estimate
    float p = 1.0;// Error covariance

    // Time update
    //prediction values
    float x_p = x;
    float p_p = p + Q;

    // Measurement update
    float k = p_p / (p_p + R);
    x = x_p + k * ( M1+M2-x_p);
    p = (1 - k) * p_p;

    return x;
}

int main() {
    float AVG[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; i++) {
        AVG[i] = kalman_update(MPU6050[i], BNo50[i]);
        }
 for (int i = 0; i < MAX_LENGTH; ++i) {
     printf("AVG[%d]=%f\n",i,AVG[i]);
    }return 0;}
*/
