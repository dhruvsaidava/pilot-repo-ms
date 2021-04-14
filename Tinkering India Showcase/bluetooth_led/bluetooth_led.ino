//use Arduino BlueControl App for led
//use 

#include<SoftwareSerial.h>
#include<Servo.h>
Servo x;
int bttx=9;    //tx of bluetooth module is connected to pin 9 of arduino
int btrx=10;    //rx of bluetooth module is connected to pin 10 of arduino
SoftwareSerial bluetooth(bttx,btrx);

void setup() {
Serial.begin(9600);
 pinMode(13, OUTPUT); // put your setup code here, to run once:

 x.attach(11);        // servo is connected to pin 11 of arduino
 Serial.begin(9600);
 bluetooth.begin(9600);
 }
 
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': digitalWrite(13, HIGH);break; // when a is pressed on the app on your smart phone
        case 'd': digitalWrite(13, LOW);break; // when d is pressed on the app on your smart phone
        default : break;
      }
      Serial.println(data);
   }
  delay(50);

  if(bluetooth.available()>0)    //if bluetooth module is transmitting data
  {
    int pos=bluetooth.read(); // store the data in pos variable
    Serial.println(pos);
    x.write(pos);             //move servo head to the given position
  }

  
}
