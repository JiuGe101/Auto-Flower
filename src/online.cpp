#include "online.h"
#include <Blinker.h>
#include "humidity.h"

char auth[] = "67cbed604159"; // secuer-key

char ssid[] = "CMCC-eSXU";
char pswd[] = "17630038480";

// char ssid[] = "we";
// char pswd[] = "1234567898";

BlinkerButton Button1("btn-abc");
BlinkerNumber Humidity_Number("soil_humidity");
// BlinkerNumber data("data");

void Online_Init() // 初始化联网模块和接发信息模块
{
    //BLINKER_DEBUG.stream(BLINKER_PRINT);
    Blinker.begin(auth, ssid, pswd);
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    Button1.attach(button1_callback);
    Blinker.attachDataStorage(dataStorage,5);
}

void Online_Run() // 运行联网模块
{
    Blinker.run();
    Blinker.delay(1000*10);//wait MQTT connected
}

void button1_callback(const String &state) // 按键1的回调函数
{
    BLINKER_LOG("get button state: ", state);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void Humidity_callbak() // 土壤湿度传感器的回调函数
{
    int humidity_data = humidity();
    Humidity_Number.print(humidity_data);
}

// 心跳包函数
void heartbeat()
{
    Button1.icon("fas fa-lightbulb");
    Button1.color("#fddb00");
    Button1.text("关灯", "打开啦");
    Button1.print("on");
}

void dataStorage()
{
    int humidity_data = humidity();
    Blinker.dataStorage("data", humidity_data);
    Serial.println("The humidity data have bean storage.");
}