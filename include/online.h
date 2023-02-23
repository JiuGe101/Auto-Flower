#ifndef __ONLINE_H__
#define __ONLINE_H__

#define BLINKER_PRINT Serial
#define BLINKER_WIFI
#include <WString.h>

void Online_Init();                         // 初始化联网模块和接发信息模块
void Online_Run();                          // 运行联网模块
void button1_callback(const String &state); // 按键1的回调函数
void Humidity_callbak();                    // 土壤湿度传感器的回调函数
void heartbeat();
void dataStorage();
#endif