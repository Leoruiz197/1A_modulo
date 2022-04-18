const int led = 2;
const int bot = 3;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(bot, INPUT);
}

void loop()
{
  int var = digitalRead(bot);
  if(var){
    digitalWrite(led,LOW);
  }else{
    digitalWrite(led,HIGH);
  }
  delay(100);
}