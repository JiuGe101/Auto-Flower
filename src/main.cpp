#include "Arduino.h"
#include "online.h"
#include "timer.h"
// #include <ESP8266WiFi.h>
// #include <Blinker.h>
void setup()
{
  // 初始化串口
  Serial.begin(115200);
  // 初始化有LED的IO
  pinMode(A0, INPUT);
  pinMode(D6, OUTPUT);
  digitalWrite(D6, HIGH);
  pinMode(D8, OUTPUT);
  digitalWrite(D8, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // 初始化blinker
  Online_Init();
  // 定时器初始化
  // Timer_Init();
}

void loop()
{
  Online_Run();
  // Humidity_callbak();
  // digitalWrite(LED_BUILTIN, LOW);
  Serial.println("进入深度睡眠模式");
  ESP.deepSleep(1e6*60*60);
  //Serial.println("进入深度睡眠模式");
}

// #include <Arduino.h>
// #include <Wire.h>
// #include "Adafruit_SHT31.h"
// #include "Adafruit_SSD1306.h"

// Adafruit_SHT31 sht31 = Adafruit_SHT31();

// #if defined(ARDUINO_ARCH_SAMD)
// // for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
// #define Serial SerialUSB
// #endif

// void setup()
// {
// #ifndef ESP8266
//   while (!Serial)
//     ; // will pause Zero, Leonardo, etc until serial console opens
// #endif
//   Serial.begin(115200);
//   Serial.println("SHT31 test");
//   if (!sht31.begin(0x44))
//   { // Set to 0x45 for alternate i2c addr
//     Serial.println("Couldn't find SHT31");
//     while (1)
//       delay(1);
//   }
// }

// void loop() {
//   float t = sht31.readTemperature();
//   float h = sht31.readHumidity();

//   if (! isnan(t)) {  // check if 'is not a number'
//     Serial.print("Temp *C = "); Serial.println(t);
//   } else {
//     Serial.println("Failed to read temperature");
//   }

//   if (! isnan(h)) {  // check if 'is not a number'
//     Serial.print("Hum. % = "); Serial.println(h);
//   } else {
//     Serial.println("Failed to read humidity");
//   }
//   Serial.println();
//   delay(1000);
// }

// #include <SPI.h>              // 加载SPI库
// #include <Wire.h>             // 加载Wire库
// #include <Adafruit_GFX.h>     // 加载Adafruit_GFX库
// #include <Adafruit_SSD1306.h> // 加载Adafruit_SSD1306库
// #include "U8g2lib.h"
// //Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
// U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /*clock=*/SCL, /*data=*/SDA, /*reset=*/U8X8_PIN_NONE);
// void setup()
// {
//   Serial.begin(115200);                      // 设置串口波特率
//   u8g2.begin();
//   u8g2.enableUTF8Print();
// }
// void loop()
// {
//   u8g2.setFont(u8g2_font_unifont_t_symbols);
//   u8g2.firstPage();
//   do
//   {
//     u8g2.setCursor(0, 15); //指定显示位置
//     u8g2.print("Hello World!"); //使用print来显示字符串
//   } while (u8g2.nextPage());
//   delay(1000);
// }