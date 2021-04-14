#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550;
PulseSensorPlayground pulseSensor;

void setup(){
  Serial.begin(9600);
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);

  pulseSensor.setThreshold(Threshold);

  if(pulseSensor.begin()){
    Serial.println("We Created a pulseSensor Object!");
  }
}

void loop(){
  int myBPM = pulseSensor.getBeatsPerMinute();

  if(pulseSensor.sawStartOfBeat()){
    Serial.println("A HEARTBEAT HAPPENED!");
    Serial.println("BPM: ");
    Serial.println(myBPM);
}
    delay(100);
}
