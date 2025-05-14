#include <Arduino.h>

String myString = ""; //接收串口发送过来的值

String short_String = ""; //存储myString截取后的字符串

String xstr = ""; //存储led_flash(x)的字符串x

String Control_LED[] = {"1", "2"}; //定义字符串数组

void setup() {
  pinMode(26, OUTPUT); // Set pin D27 as output
  pinMode(27, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2,OUTPUT);
  Serial.begin(115200); // Start the serial communication at 115200 baud rate
  Serial.println("Serial started"); // Print a message to the serial monitor
}

void loop() {
  myString = Serial.readStringUntil('\n'); // Read the incoming string until a newline character is received
  short_String = myString.substring(0, 8); // Extract the first character from the string

  if(short_String =="1")
{
  digitalWrite(2, HIGH); 
  digitalWrite(27, HIGH); 
  digitalWrite(26, HIGH); 

  digitalWrite(25, HIGH); 


  printf("部分1打开\n"); // Print a message to the serial monitor

}
else if(short_String =="2")
{
  digitalWrite(33, HIGH); 

  digitalWrite(32, HIGH); 
  digitalWrite(14, HIGH); 

  printf("部分2打开\n"); 
}

else if(short_String == "3")
{
  printf("流水灯模式\n"); // Print a message to the serial monitor
  digitalWrite(26, HIGH); 
  delay(100);
  digitalWrite(26, LOW); 
  delay(100);
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(2, HIGH); 
    delay(100);
    digitalWrite(2, LOW); 
    delay(100);
  }
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(27, HIGH); 
    delay(100);
    digitalWrite(27, LOW); 
    delay(100);
  }
}


if(short_String =="4"){
    digitalWrite(2, LOW);
    digitalWrite(27, LOW);
    digitalWrite(26, LOW);
    digitalWrite(25, LOW);
    digitalWrite(33, LOW);
    digitalWrite(32, LOW);
    digitalWrite(14, LOW);
    printf("全部关闭\n"); // Print a message to the serial monitor
}
}