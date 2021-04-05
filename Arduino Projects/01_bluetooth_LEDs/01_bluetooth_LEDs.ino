
#include<SoftwareSerial.h>
char val;
SoftwareSerial my(3,4);

void setup()
{
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
  
    my.begin(9600);
}

void loop()
{
  while( ! my.available() ) ;
  val = my.read();

  if ( val == 'H'){
    digitalWrite(12, HIGH);  
  }else if ( val == 'L'){
     digitalWrite(12, LOW);
  }

  if ( val == 'A'){
    digitalWrite(11, HIGH);  
  }else if ( val == 'B'){
     digitalWrite(11, LOW);
  }

    if ( val == 'X'){
    digitalWrite(8, HIGH);  
  }else if ( val == 'Y'){
     digitalWrite(8, LOW);
  }

    if ( val == 'M'){
    digitalWrite(7, HIGH);  
  }else if ( val == 'N'){
     digitalWrite(7, LOW);
  }

        if ( val == 'O'){
    digitalWrite(6, HIGH);  
  }else if ( val == 'P'){
     digitalWrite(6, LOW);
  }

        if ( val == 'F'){
    digitalWrite(5, HIGH);  
  }else if ( val == 'G'){
     digitalWrite(5, LOW);
  }


}
