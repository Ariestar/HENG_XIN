#include <Arduino.h>
#include <Adafruit_NeoPixel.h> // 引入 NeoPixel 库

// --- NeoPixel RGB LED 相关定义 ---
#define NEOPIXEL_PIN 48     // 请根据你的ESP32-S3开发板实际引脚修改
#define NUM_PIXELS 1        // 板载只有一个RGB LED
#define BRIGHTNESS 50       // 亮度 (0-255，可以调整)

// 创建 NeoPixel 对象
Adafruit_NeoPixel pixels(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200); // 初始化串口用于调试输出

  // 初始化 NeoPixel 库
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS); // 设置亮度

  // 首次点亮 RGB 灯为蓝色
  pixels.setPixelColor(0, pixels.Color(0, 0, 255)); // 设置第一个像素为蓝色 (R, G, B)
  pixels.show(); // 更新显示

  Serial.println("RGB LED should be BLUE now.");
}

void loop() {
  // 你可以在这里添加其他代码，让灯闪烁或改变颜色
  // 例如，每2秒改变一次颜色
  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // 红色
  pixels.show();
  delay(2000);

  pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // 绿色
  pixels.show();
  delay(2000);
}