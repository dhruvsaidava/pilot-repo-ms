/*Based on digital output of two sensors
  Speed control added
*/
int left, right;
int value = 100;
int LS = A1;
int RS = A0;
int AM1 = 8;
int AM2 = 9;
int BM1 = 10;
int BM2 = 11;

void setup()
{
  pinMode(LS, INPUT); //left sensor
  pinMode(RS, INPUT); //right sensor
  pinMode(AM1, OUTPUT); //left motor
  pinMode(AM2, OUTPUT); //left motor
  pinMode(BM1, OUTPUT); //right motor
  pinMode(BM2, OUTPUT); //right motor
  //  Serial.begin(9600);
}
void read_sensors()
{
  left = digitalRead(LS);
  right = digitalRead(RS);
}
void move_forward()
{
  analogWrite(AM2, value); //3,9 for left motor
  digitalWrite(AM1, LOW);
  analogWrite(BM2, value); //10,5 for right motor
  digitalWrite(BM1, LOW);
}
void turn_left()
{
  digitalWrite(AM2, LOW); //9,3 for left motor
  digitalWrite(AM1, LOW);
  analogWrite(BM2, value); //10,5 for right motor
  digitalWrite(BM1, LOW);
}
void turn_right()
{
  analogWrite(AM2, value); // 9,3 for left motor
  digitalWrite(AM1, LOW);
  digitalWrite(BM2, LOW); // 10,5 for right motor
  digitalWrite(BM1, LOW);
}
void halt()
{
  digitalWrite(AM2, LOW); // 9,3 for left motor
  digitalWrite(AM1, LOW);
  digitalWrite(BM2, LOW); // 10,5 for right motor
  digitalWrite(BM1, LOW);
}
void print_readings()
{
  Serial.print(" leftsensor");
  Serial.print("\t");
  Serial.print(left);
  Serial.print("rightsensor");
  Serial.print("\t");
  Serial.print(right);
  Serial.println();
}
void loop()
{
  read_sensors();
  while ((left == 0) && (right == 1)) // left sensor is over black line
  {
    turn_left();
    read_sensors();
    print_readings();
  }
  while ((left == 1) && (right == 0)) // right sensor is over black line
  {
    turn_right();
    read_sensors();
    print_readings();
  }
  while ((left == 1) && (right == 1)) // both sensors over the back line
  {
    halt();
    read_sensors();
    print_readings();
  }
  while ((left == 0) && (right == 0)) // no sensor over black line
  {
    move_forward();
    read_sensors();
    print_readings();
  }
}
