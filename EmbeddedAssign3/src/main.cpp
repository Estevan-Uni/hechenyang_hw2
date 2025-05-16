#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define I2C_SDA 21
#define I2C_SCL 22
#define OLED_ADDR 0x3C
#include "bmp.h"

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup(){
  Serial.begin(115200);
  Wire.begin();
  display.clearDisplay();
  display.drawBitmap(32,0,BMP_1,64,64,SSD1306_WHITE);
  display.display();
}
void loop(){
  delay(500);
  display.invertDisplay(false);
}