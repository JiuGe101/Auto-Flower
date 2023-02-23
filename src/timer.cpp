#include <Arduino.h>
#include "online.h"
#include <Ticker.h>
#include "timer.h"

Ticker timer1;

void Timer_Init()
{
    timer1.attach(1, timer1_callback);
    if (timer1.active())
    {
        Serial.println("The timer1 is active");
    }
    else
    {
        Serial.println("The timer1 is non-active");
    }
}
void timer1_callback()
{
    Humidity_callbak();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}