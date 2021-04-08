#define S0 5//Connecting S0 pin of sensor to 5th pin of Arduino
#define S1 6//Connecting S1 pin of sensor to 6th pin of Arduino
#define S2 7//Connecting S2 pin of sensor to 7th pin of Arduino
#define S3 8//Connecting S3 pin of sensor to 8th pin of Arduino
#define sensor 9//Taking Input from sensor from 9th pin of Arduino
int frequency = 0;//Initially setting the frequency integer of color input to be 0
void setup() {
 pinMode(S0,OUTPUT);
 pinMode(S1,OUTPUT);
 pinMode(S2,OUTPUT);
 pinMode(S3,OUTPUT);
 pinMode(sensor,INPUT);
 //Setting frequency-scaling to 20%, we can lear this from the table
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 Serial.begin(9600);//Setting the baud rate of serial communication to be 9600
}
void loop() {
 // Setting RED filtered photodiodes to be read by the Arduino
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 // Reading the output frequency
 frequency = pulseIn(sensor, LOW);
 //counting the frequency of signal to go from HIGH to LOW
 // Printing the value on the serial monitor
 Serial.print("R = "); //printing name of color
 Serial.print(frequency);//printing RED color frequency
 Serial.print(" ");
 delay(100);
 // Setting GREEN filtered photodiodes to be read by the Arduino
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 // Reading the output frequency
 frequency = pulseIn(sensor, LOW);
 //counting the frequency of signal to go from HIGH to LOW
 // Printing the value on the serial monitor
 Serial.print("G = ");//printing name of color
 Serial.print(frequency);//printing RED color frequency
 Serial.print(" ");
 delay(100);
 // Setting BLUE filtered photodiodes to be read by the Arduino
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 // Reading the output frequency
frequency = pulseIn(sensor, LOW);//counting the frequency of signal to go from HIGH to LOW
 // Printing the value on the serial monitor
 Serial.print("B = ");//printing name of color
 Serial.print(frequency);//printing RED color frequency
 Serial.println(" ");
 delay(100);
}
