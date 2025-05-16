#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED 尺寸
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C 默认引脚（ESP32 通常是 21, 22，Arduino UNO 固定引脚）
#define I2C_SDA 21
#define I2C_SCL 22

// OLED I2C 地址，常见为 0x3C 或 0x3D
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// 包含导出的图片，确保 bmp.h 中使用 PROGMEM
#include "bmp.h"

void setup() {
  // 串口初始化（调试信息）
  Serial.begin(115200);
  while (!Serial) { delay(10); }  // 等待串口就绪（可选）

  // 初始化 I2C
  // 对于 ESP32 可直接 Wire.begin()
  // Wire.begin(I2C_SDA, I2C_SCL);
  Wire.begin();

  // 初始化 OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);  // 停在这里
  }

  // 清屏并绘图
  display.clearDisplay();
  display.drawBitmap(
    (SCREEN_WIDTH  - 64) / 2,
    (SCREEN_HEIGHT - 64) / 2,
    BMP_1,
    64, 64,
    SSD1306_WHITE
  );
  display.display();
}

void loop() {
  // 示例动画：图片闪烁
  delay(500);
  display.invertDisplay(false);
}