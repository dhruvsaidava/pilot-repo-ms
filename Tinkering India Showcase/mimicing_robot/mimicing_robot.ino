
#include <Servo.h>

Servo bottomServo;
Servo secondServo;
Servo thirdServo;
Servo pickServo;  // create servo object to control a servo

const int button1 = 2; //Buttons
const int button2 = 3;

int button1Presses = 0; //Button values
boolean button2Pressed = false;


int bottomServoPosSaves[] = {1,1,1,1,1}; //position saves
int secondServoPosSaves[] = {1,1,1,1,1};
int thirdServoPosSaves[] = {1,1,1,1,1};
int pickServoPosSaves[] = {1,1,1,1,1};

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  bottomServo.attach(9);  // attaches the bottomServo on pin 9 to the servo object
  secondServo.attach(10);  // attaches the 2ndServo on pin 10 to the servo object
  thirdServo.attach(11);  // attaches the 3rdServo on pin 11 to the servo object
  pickServo.attach(12);  // attaches the pickServo on pin 12 to the servo object

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // reads the value of the potentiometer at bottom(value between 0 and 1023)
  int bottomPotValue = analogRead(A0);
  
  // reads the value of the potentiometer in the middle(value between 0 and 1023)
  int middlePotValue = analogRead(A1);
  
  // reads the value of the potentiometer at top(value between 0 and 1023)
  int topPotValue = analogRead(A2);
  
  // reads the value of the potentiometer fixed seperately(value between 0 and 1023)
  int sepPotValue = analogRead(A3); 

  // scales it to use it with the servo (value between 0 and 180)
  int bottomPotAngle = map(bottomPotValue, 0, 1023, 0, 179);
  int middlePotAngle = map(middlePotValue, 0, 1023, 0, 179);
  int topPotAngle = map(topPotValue, 0, 1023, 0, 179);
  int sepPotAngle = map(sepPotValue, 0, 1023, 0, 179);

  // sets the servo position according to the scaled value
  bottomServo.write(bottomPotAngle);
  secondServo.write(middlePotAngle);
  thirdServo.write(topPotAngle);
  pickServo.write(sepPotAngle); 

  /*
  if(digitalRead(button1) == HIGH)
  { // This will check how many times button1 is pressed and save the positions to an array depending on how many times it is pressed; 
    //switch/case works like an if statement
    button1Presses++;
    switch(button1Presses){
      case 1:
        bottomServoPosSaves[0] = bottomPotAngle;
        secondServoPosSaves[0] = middlePotAngle;
        thirdServoPosSaves[0] = topPotAngle;
        pickServoPosSaves[0] = sepPotAngle;
        Serial.println("Pos 1 Saved");
        break;

      case 2:
        bottomServoPosSaves[1] = bottomPotAngle;
        secondServoPosSaves[1] = middlePotAngle;
        thirdServoPosSaves[1] = topPotAngle;
        pickServoPosSaves[1] = sepPotAngle;
        Serial.println("Pos 2 Saved");
        break;

      case 3:
        bottomServoPosSaves[2] = bottomPotAngle;
        secondServoPosSaves[2] = middlePotAngle;
        thirdServoPosSaves[2] = topPotAngle;
        pickServoPosSaves[2] = sepPotAngle;
        Serial.println("Pos 3 Saved");
        break;

      case 4:
        bottomServoPosSaves[3] = bottomPotAngle;
        secondServoPosSaves[3] = middlePotAngle;
        thirdServoPosSaves[3] = topPotAngle;
        pickServoPosSaves[3] = sepPotAngle;
        Serial.println("Pos 4 Saved");
        break;

      case 5:
        bottomServoPosSaves[4] = bottomPotAngle;
        secondServoPosSaves[4] = middlePotAngle;
        thirdServoPosSaves[4] = topPotAngle;
        pickServoPosSaves[4] = sepPotAngle;
        Serial.println("Pos 5 Saved");
        break;
    }
  }

  if(digitalRead(button2) == HIGH){ // Pretty self-explnatory here
    button2Pressed = true;   
  }

  if(button2Pressed){ // if the boolean button2Press is true, then the servos will run though all their saved positions
    for(int i = 0; i < 5; i++){
        bottomServo.write(bottomServoPosSaves[i]);
        secondServo.write(secondServoPosSaves[i]);
        thirdServo.write(thirdServoPosSaves[i]);
        pickServo.write(pickServoPosSaves[i]);
        
        Serial.println(" potentimeter Angles: ");
        
        Serial.println(bottomServoPosSaves[i]);
        Serial.println(secondServoPosSaves[i]);
        Serial.println(thirdServoPosSaves[i]);
        Serial.println(pickServoPosSaves[i]);
        delay(1050);
      }
  }
  delay(300);
  */

}
