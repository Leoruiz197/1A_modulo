#include <Servo.h>

Servo s;
int pos;

const int bot1 = 2;
const int bot2 = 3;
const int bot3 = 4;

void setup() {
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  pinMode(bot3, INPUT);
  
  s.attach(6);
  Serial.begin(9600);
  s.write(160);
}

int var1;
int var2;
int var3;

void loop() {
  var1 = digitalRead(bot1);
  var2 = digitalRead(bot2);
  var3 = digitalRead(bot3);
  
  if(var1){
    for(pos = 100; pos < 160; pos++)
    {
      s.write(pos);
      delay(15);
    }
  }

  if(var2){
    for(pos = 160; pos > 100; pos--)
    {
      s.write(pos);
      delay(15);
    }
  }

  if(var3){
    for(pos = 100; pos < 160; pos++)
    {
      s.write(pos);
      delay(15);
    }
    delay(3000);
    for(pos = 160; pos > 100; pos--)
    {
      s.write(pos);
      delay(15);
    }
  }
}
