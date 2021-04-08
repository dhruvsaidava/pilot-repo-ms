int sensorinput = 2;
// the digital pin connected to thesensor
int ledoutput = 12;
// pin connected to LED
void setup()
{
 pinMode(ledoutput, OUTPUT);
// this function is used to declare led connected pin as output
 pinMode(sensorinput, INPUT);
// this function is used to declaresensor connected pin as input
}
void loop()
{
 int value =
digitalRead(sensorinput);
// function to read analog voltage from sensor
 if (value==HIGH)
// function to check voltage level from sensor
 {
 digitalWrite(ledoutput, HIGH);
// make LED - ON
 delay(100);
// to make the LED visible
 }
 else
 digitalWrite(ledoutput, LOW); //make LED - OFF
}
