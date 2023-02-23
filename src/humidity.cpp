#include <Arduino.h>
#include "humidity.h"

int humidity()
{
  int humi = analogRead(A0) * 100 / 1024;
  Serial.print("The current humidity of soil is:");
  Serial.println(humi);
  if (humi < 30)
  {
    digitalWrite(D6, LOW);
  }
  else
  {
    digitalWrite(D6, HIGH);
  }
  return humi;
}