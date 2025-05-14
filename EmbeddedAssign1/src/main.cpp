#include <Arduino.h>
int Pins[]={2,4,5,18,19,21}; 
int num=6;
void setup(){
  for(int i = 0; i < num; i++){
    pinMode(Pins[i],OUTPUT);
    digitalWrite(Pins[i],LOW);
  }
}
void loop(){
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