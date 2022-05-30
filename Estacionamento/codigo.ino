const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  Serial.begin(9600);
}


void loop() {
  long cm = 0.01723 * readUltrasonicDistance(8,9);
  Serial.println(cm);
  
  if(cm < 50){
  	digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
  }
  
  if(cm < 40){
  	digitalWrite(led2, HIGH);
  }else{
    digitalWrite(led2, LOW);
  }
  
  if(cm < 30){
  	digitalWrite(led3, HIGH);
  }else{
    digitalWrite(led3, LOW);
  }
  
  if(cm < 20){
  	digitalWrite(led4, HIGH);
  }else{
    digitalWrite(led4, LOW);
  }
  
  if(cm < 10){
  	digitalWrite(led5, HIGH);
  }else{
    digitalWrite(led5, LOW);
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