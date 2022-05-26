#include <Servo.h>

Servo s;
int pos;

const int bot1 = 2;
const int bot2 = 3;
const int led1 = 4;
const int led2 = 5;

void setup() {
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  s.attach(6);
  Serial.begin(9600);
  s.write(160);
}

int var1;
int var2;

void loop() {
  var1 = digitalRead(bot1);
  var2 = digitalRead(bot2);
  
  if(var1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    for(pos = 100; pos < 160; pos++)
    {
      s.write(pos);
      delay(15);
    }
  }
  
  long cm = 0.01723 * readUltrasonicDistance(8,9);
  Serial.println(cm);
  
  if(var2 && cm > 100){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    for(pos = 160; pos > 100; pos--)
    {
      s.write(pos);
      delay(15);
    }
  }
  delay(100);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
