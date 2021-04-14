String voice;

#define GREEN 10
#define BLUE 11
#define RED 9

void setup() 
{                                            // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);
   pinMode(RED, OUTPUT);
   analogWrite(RED,0); 
   analogWrite(GREEN,0);                    // Since LED must be off in the beginning
   analogWrite(BLUE,0);
}

   int redVal;
   int greenVal;
   int blueVal;


void loop() {
 
  while (Serial.available())   //Check if there is an available byte to read
  {                            
  delay(10);                   //Delay added to make thing stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  } 

  if (voice.length() > 0) {
    Serial.println(voice);
  //----------Control Multiple Pins/ LEDs----------// 

       if(voice == "red")//                                FOR RED COLOUR OF THE LED 
     {
     analogWrite(RED,0); 
     analogWrite(GREEN,0);
     analogWrite(BLUE,255);
     }  
  else if(voice == "green")//                              FOR GREEN COLOUR OF THE LED !
     {
    analogWrite(GREEN,255);
    analogWrite(RED,0);
    analogWrite(BLUE,0);
     }
  else if(voice == "blue")//                                FOR BLUE COLOUR OF THE LED !
     {
    analogWrite(RED,255);
    analogWrite(BLUE,0);
    analogWrite(GREEN,0);
     }
  
  else if(voice == "white")//                               FOR WHITE COLOUR OF THE LED !
     {
    analogWrite(RED,255);
    analogWrite(GREEN,0);
    analogWrite(BLUE,255);
     }
   else if(voice == "good night")//                          FOR TURNING OFF LED !
     {
    analogWrite(RED,0);
    analogWrite(GREEN,0);
    analogWrite(BLUE,0);
     }
    
    else if(voice == "chameleon") //                           FOR FADING/CHANGING COLOURS !
     {
     redVal = 255; // choose a value between 1 and 255 to change the color. 
     blueVal = 0;
     greenVal = 0;
     for(int i = 0; i < 255; i += 1) // fades out of red and into full (i = 255) green
    {
    greenVal += 1;
    redVal -= 1;
    analogWrite(GREEN, 255 - greenVal);
    analogWrite(RED, 255 - redVal);
    delay(5);
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for(int i = 0; i < 255; i += 1)
  {
    blueVal += 1;
    greenVal -= 1;
    analogWrite(BLUE, 255 - blueVal);
    analogWrite(GREEN, 255 - greenVal);
    delay(5);
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1)
  {
    redVal += 1;
    blueVal -= 1;
    analogWrite(RED, 255 - redVal);
    analogWrite(BLUE, 255 - blueVal);
    delay(5);
  }
   }
voice="";                                                       //Reset the variable after initiating
}
}
