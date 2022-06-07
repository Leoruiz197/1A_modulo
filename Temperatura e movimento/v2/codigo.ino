#include "DHT.h"
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

const int rele = 7;

float celsius = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  pinMode(rele, OUTPUT);

  dht.begin();

  Serial.begin(9600);
}


void loop() {
  int var =  digitalRead(8);
  celsius = dht.readTemperature();
  
  Serial.print(celsius);
  Serial.print(" C, ");
  
  if(celsius > 31 && var){
  	digitalWrite(rele, HIGH);
  }else{
    digitalWrite(rele, LOW);
  }
  
  if(celsius > 30){
  	digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
  }
  
  if(celsius >28){
  	digitalWrite(led2, HIGH);
  }else{
    digitalWrite(led2, LOW);
  }
  
  if(celsius > 26){
  	digitalWrite(led3, HIGH);
  }else{
    digitalWrite(led3, LOW);
  }
  
  if(celsius > 24){
  	digitalWrite(led4, HIGH);
  }else{
    digitalWrite(led4, LOW);
  }
  
  if(celsius > 20){
  	digitalWrite(led5, HIGH);
  }else{
    digitalWrite(led5, LOW);
  }
  
  delay(100);
}
