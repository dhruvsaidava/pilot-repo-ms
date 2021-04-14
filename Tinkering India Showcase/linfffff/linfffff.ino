//#include<UltraDistSensor.h>
//UltraDistSensor mysensor;
//float reading;
//int const trigPin = 12;
//int const echoPin = 13;
//int const buzzPin = 2;

//NOW IT IS A PERFECT LINE FOLLOWER ROBOT!

int vSpeed = 110;        // MAX 255
int turn_speed = 230;    // MAX 255
int turn_delay = 10;

//L293 Connection
const int motorA1      = 6;  //side not having MTR IN
const int motorA2      = 9;
//const int motorAspeed  = 12;
const int motorB1      = 11; //screw sided MTR IN
const int motorB2      = 10;
//const int motorBspeed  = 13;

//Sensor Connection
const int left_sensor_pin = A1;
const int right_sensor_pin = A0;



int left_sensor_state;
int right_sensor_state;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

  delay(3000);

  //  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  //  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  //  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering




}

void loop() {





  left_sensor_state = analogRead(left_sensor_pin);
  right_sensor_state = analogRead(right_sensor_pin);

  if (right_sensor_state < 100 && left_sensor_state > 100)
  {
    Serial.println("turning right");

    digitalWrite (motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite (motorB1, HIGH);
    digitalWrite(motorB2, LOW);

//    analogWrite (motorAspeed, vSpeed);
//    analogWrite (motorBspeed, turn_speed);

  }
  if (right_sensor_state > 100 && left_sensor_state < 100)
  {
    Serial.println("turning left");

    digitalWrite (motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite (motorB1, LOW);
    digitalWrite(motorB2, HIGH);

//    analogWrite (motorAspeed, turn_speed);
//    analogWrite (motorBspeed, vSpeed);
    //
    delay(turn_delay);
  }

  if (right_sensor_state < 100 && left_sensor_state < 100)
  {
    Serial.println("going forward");

    digitalWrite (motorA2, HIGH);
    digitalWrite(motorA1, LOW);
    digitalWrite (motorB2, LOW);
    digitalWrite(motorB1, HIGH);

//    analogWrite (motorAspeed, vSpeed);
//    analogWrite (motorBspeed, vSpeed);
    //
    delay(turn_delay);

  }

  if (right_sensor_state > 100 && left_sensor_state > 100)
  {
    Serial.println("stop");

    //  analogWrite (motorAspeed, 0);
    //  analogWrite (motorBspeed, 0);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorA1, LOW);
    digitalWrite(motorB2, LOW);
    digitalWrite(motorB1, LOW);

  }



  //  int duration, distance;
  //  digitalWrite(trigPin, HIGH);
  //  delay(1);
  //  digitalWrite(trigPin, LOW);
  //  // Measure the pulse input in echo pin
  //  duration = pulseIn(echoPin, HIGH);
  //  // Distance is half the duration devided by 29.1 (from datasheet)
  //  distance = (duration/2) / 29.1;
  //  // if distance less than 0.5 meter and more than 0 (0 or less means over range)
  //  if (distance <= 10 && distance >= 0) {
  //  // Buzz
  //  digitalWrite(buzzPin, HIGH);
  //  Serial.println("stop");
  //
  ////  analogWrite (motorAspeed, 0);
  ////  analogWrite (motorBspeed, 0);
  //    digitalWrite(motorA2,LOW);
  //    digitalWrite(motorA1,LOW);
  //    digitalWrite(motorB2,LOW);
  //    digitalWrite(motorB1,LOW);
  //  }
  //  else {
  //  // Don't buzz
  //  digitalWrite(buzzPin, LOW);
  //  if(right_sensor_state < 100 && left_sensor_state > 100)
  //    {
  //      Serial.println("turning right");
  //
  //      digitalWrite (motorA1,LOW);
  //      digitalWrite(motorA2,HIGH);
  //      digitalWrite (motorB1,LOW);
  //      digitalWrite(motorB2,HIGH);
  //
  //    //  analogWrite (motorAspeed, vSpeed);
  //    //  analogWrite (motorBspeed, turn_speed);
  //
  //      }
  //    if(right_sensor_state > 100 && left_sensor_state < 100)
  //    {
  //      Serial.println("turning left");
  //
  //      digitalWrite (motorA1,HIGH);
  //      digitalWrite(motorA2,LOW);
  //      digitalWrite (motorB1,HIGH);
  //      digitalWrite(motorB2,LOW);
  //
  //    //  analogWrite (motorAspeed, turn_speed);
  //    //  analogWrite (motorBspeed, vSpeed);
  //    //
  //      delay(turn_delay);
  //      }
  //
  //    if(right_sensor_state < 100 && left_sensor_state < 100)
  //    {
  //      Serial.println("going forward");
  //
  //      digitalWrite (motorA2,LOW);
  //      digitalWrite(motorA1,HIGH);
  //      digitalWrite (motorB2,HIGH);
  //      digitalWrite(motorB1,LOW);
  //
  //    //  analogWrite (motorAspeed, vSpeed);
  //    //  analogWrite (motorBspeed, vSpeed);
  //    //
  //      delay(turn_delay);
  //
  //    }
  //  }



}
