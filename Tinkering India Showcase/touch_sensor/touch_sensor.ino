// constants won't change. They're used here to set pin numbers:
const int SENSOR_PIN = 7; // the Arduino's input pin that connects to the sensor's SIGNAL pin 

// Variables will change:
int lasttouchState = LOW;      // the previous state from the input pin
int currenttouchState;         // the current reading from the input pin
int ledstate = LOW;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_BUILTIN,OUTPUT);

//  currenttouchState = digitalRead(SENSOR_PIN);
}

void loop() {
  // read the state of the the input pin:
  currenttouchState = digitalRead(SENSOR_PIN);

  /*if(lasttouchState == LOW && currenttouchState == HIGH){
    ledstate = !ledstate;
    digitalWrite(LED_BUILTIN,ledstate);
    Serial.println("The sensor is TOUCHED");
  }
  
  if(lasttouchState == HIGH && currenttouchState == LOW){
    ledstate = !ledstate;
    digitalWrite(LED_BUILTIN,ledstate);
    Serial.println("The sensor is FREE");
  }*/


  switch(lasttouchState == HIGH && currenttouchState == LOW) {
    case 1:
      Serial.println("The sensor is TOUCHED!\n");

      // toggle state of LED
      ledstate = !ledstate;
  
      // control LED arccoding to the toggled state
      digitalWrite(13, ledstate);
    default:
      break;
  }

  
  // save the the last state
  lasttouchState = currenttouchState;
}
