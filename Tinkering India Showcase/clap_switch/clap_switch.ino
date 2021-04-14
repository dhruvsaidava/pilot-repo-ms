int micPin = A0;          // pin that the mic is attached to
int gndPin = A1;
int powerPin = A2;
int micValue1 = 100;  
int micValue2 = 100; // the Microphone value
int led1 = 2;
boolean lightOn = false;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(micPin, INPUT);
  digitalWrite(gndPin,LOW);
  delay(500);
  digitalWrite(powerPin,HIGH);
  Serial.begin(9600);  //for test the input value initialize serial
}

void loop() {
  micValue1 = analogRead(micPin);  // read pin value
  Serial.println(micValue1);
  delay(1);
  micValue2 = analogRead(micPin);
  Serial.println(micValue2);
  
  if (micValue1-micValue2 > 2 || micValue2-micValue1 > 2){
  lightOn = !lightOn;
  delay(100);
  digitalWrite(led1, lightOn);
  }
} 
