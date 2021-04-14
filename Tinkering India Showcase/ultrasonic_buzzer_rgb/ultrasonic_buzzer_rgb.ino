int const trigPin = 6;
int const echoPin = 5;
int const buzzPin = 7;
int rpin = 4;
int gpin = 3;
int bpin = 2;
int b2pin = 10;

void setup(){
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT); 
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  
}

void loop(){
  int duration, distance;

  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;

  if(distance <= 9 && distance >= 0)
  {
    digitalWrite(buzzPin, HIGH);
    digitalWrite(rpin, HIGH);
    digitalWrite(gpin,LOW);
    digitalWrite(bpin,LOW);
  }
  else if(distance <= 15 && distance >= 10){
    digitalWrite(gpin, HIGH);
    digitalWrite(rpin,LOW);
    digitalWrite(bpin,LOW);
  }
  else if(distance <= 25 && distance >= 17){
    digitalWrite(bpin,HIGH);
    digitalWrite(rpin,LOW);
    digitalWrite(gpin,LOW);
  }
  else
  {
    digitalWrite(buzzPin, LOW);
    digitalWrite(rpin, LOW);
    digitalWrite(gpin, LOW);
    digitalWrite(bpin, LOW);
  }
  delay(60);
}
