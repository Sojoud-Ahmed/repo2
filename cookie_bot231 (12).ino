#define trigPin1 7
#define echoPin1 6
#define trigPin2 3
#define echoPin2 2
#define trigPin3 9
#define echoPin3 8
#define trigPin4 5
#define echoPin4 4

//  the robot's initial position (x, y) in the chamber
#define initial_X 0
#define initial_Y 0

// dimensions of the chamber in meters
#define width 5
#define height 6
#define MAX_DIS 8

void setup() {
  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
}

void loop() {
  // Measure distances from the walls in different directions
  float d1 = measureDistance(trigPin1, echoPin1);  // Distance in front of the Cookie Bot(sensor1)
  float d2 = measureDistance(trigPin2, echoPin2);  // Distance to the right of the Cookie Bot(sensor2)
  float d3 = measureDistance(trigPin3, echoPin3);  // Distance to the left of the Cookie Bot(sensor3)
  float d4 = measureDistance(trigPin4, echoPin4);  // Distance behind the Cookie Bot(sensor4)

  
  float x = (width-(d2 + d3)) / 2  +initial_X;  // x-coordinate of the Cookie Bot 
  float y = (height - (d1 + d4)) / 2  +initial_Y;  // y-coordinate of the Cookie Bot

  // Print the Cookie Bot's position
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(", y: ");
  Serial.println(y);

  delay(500);
}

float measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2/100; // Calculate distance in meters
   distance = min(distance, MAX_DIS); // Limit distance to MAX_DIS
  return distance;
} 
/*
//number of pin of sensors1,2
#define trigPin1 7
#define echoPin1 6
#define trigPin2 2
#define echoPin2 3

//  the robot's initial position (x, y) in the chamber
   #define initial_X = 0;
   #define initial_Y = 0;
   
// positions of the sensors
#define x1 2.5
#define y1 0
#define x2 0
#define y2 3

// dimensions of the chamber in meter
#define width 5
#define height 6

void setup() {
  Serial.begin(9600);

  // set up the pins for ultrasonic sensors
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // measure distance d1 from sensor 1
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  float duration1 = pulseIn(echoPin1, HIGH);
  float d1 = duration1 * 0.0343 / 2;//0.0343 is speed of sound in mm/microseconds

  // measure distance d2 from sensor 2
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  float duration2 = pulseIn(echoPin2, HIGH);
  float d2 = duration2 * 0.0343 / 2/100;

  // calculate robot's position (x, y)
  float a = atan2((y2 - y1),(x1 - x2));  // angle between the sensors
  float b = acos((d1 * d1 + 15.25 - d2 * d2) / (2 * d1 * 3.9));  // angle between sensor1, robot, and the line between the sensors,3.9 is distance between 2 sensors sqrt((y2 - y1))^2+(x2 - x1)^2)
  float e = acos((d2 * d2 + 15.25- d1 * d1) / (2 * d2 * 3.9));  // angle between sensor2, robot, and the line between the sensors
  float x;
   float y;
  if(b+a>=90){
  
  float c = 180-(a + b);  // angle between sensor1, robot, and the x-axis
  float g =180-((90-a) + e);  // angle between sensor2, robot, and the x-axis
  float x = d2 * sin(g);  // x-coordinate of the robot in the chamber
  float y = d1* sin(c);  // y-coordinate of the robot in the chamber
  }
  else {
    float c = (a - b);// angle between sensor1, robot, and the x-axis
    float g=(90-a)-e;// angle between sensor2, robot, and the x-axis
    float x = d2 * sin(g);  // x-coordinate of the robot in the chamber
  float y = d1* sin(c);  // y-coordinate of the robot in the chamber
  }

  // print the robot's position
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(", y: ");
  Serial.println(y);

  delay(500);
}*/