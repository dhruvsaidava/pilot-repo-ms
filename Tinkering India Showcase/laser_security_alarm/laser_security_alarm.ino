const int ledPin = 2;
const int buzzerPin = 12;
const int ldrPin = A0;
const int laserPin = 7;
void setup ()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode( laserPin , OUTPUT);
  digitalWrite( laserPin , HIGH);
}
void loop()
{
  int ldrStatus = analogRead(ldrPin);
  if (ldrStatus < 700)
  {
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    Serial.println("ALARM DEACTIVATED");
  }
  else
  {
    tone(buzzerPin, 100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(100);
    Serial.println("****************ALARM ACTIVATED****************");
  }
  Serial.println( ldrStatus );
  delay(100);
}
