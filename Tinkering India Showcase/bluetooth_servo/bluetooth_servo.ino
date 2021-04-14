#include<SoftwareSerial.h>
#include<Servo.h>
Servo x;
int bttx=9;    //tx of bluetooth module is connected to pin 9 of arduino
int btrx=10;    //rx of bluetooth module is connected to pin 10 of arduino
SoftwareSerial bluetooth(bttx,btrx);

char junk;
String inputString="";


void setup()
{
  x.attach(11);        // servo is connected to pin 11 of arduino
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(13, OUTPUT);
}
void loop()
{
  if(bluetooth.available()>0)    //if bluetooth module is transmitting data
  {
    int pos=bluetooth.read(); // store the data in pos variable
    Serial.println(pos);
    x.write(pos);             //move servo head to the given position
  }


  
}
