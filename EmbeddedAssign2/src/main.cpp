#include <Arduino.h>

String myString=""; 
String short_String=""; 

void setup() {
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(33,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  myString=Serial.readStringUntil('\n');
  short_String=myString.substring(0, 1);
  if(short_String=="1")
  {
    digitalWrite(13, HIGH); 
    digitalWrite(14, HIGH); 
    digitalWrite(26, HIGH); 
    digitalWrite(33, HIGH); 
    Serial.println("first mode\n");
  }
  else if(short_String=="2")
  {
    digitalWrite(12, HIGH); 
    digitalWrite(27, HIGH); 
    digitalWrite(25, HIGH); 
    Serial.println("second mode\n"); 
  }
  else if(short_String=="3")
  {
    Serial.println("third mode\n");
    int Pins[]={13,12,14,27,26,25,33}; 
    int num=7;
    for(int i=0;i<num;i++){
      digitalWrite(Pins[i],HIGH); 
      delay(200);
      digitalWrite(Pins[i],LOW);
    }
    for(int i=num-1;i>=0;i--){
      digitalWrite(Pins[i],HIGH);
      delay(200);
      digitalWrite(Pins[i],LOW);
    }
  }
  if(short_String=="4"){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(14, LOW);
    digitalWrite(27, LOW);
    digitalWrite(26, LOW);
    digitalWrite(25, LOW);
    digitalWrite(33, LOW);
    Serial.println("end\n");
  }
}