
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode (8, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

if (sensorValue <= 420) 
        {
        Serial.println (" Alcohol Absent ");
        Serial.print (" Value = ");              
        Serial.println (sensorValue);        
        digitalWrite (8, LOW);
        delay (200);
        }

  else {
        Serial.println (" Alcohol Present ");
        Serial.print (" Value = ");              
        Serial.println (sensorValue);        
        digitalWrite (8, HIGH);
        delay (500);        
  } 


  
}
