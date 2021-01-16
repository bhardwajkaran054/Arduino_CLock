/*
  By Karan Bhardwaj
*/

#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  pinMode(12, OUTPUT);
  //digitalWrite(12, HIGH);
  //Arduino Pin-12 Bydefault set to 0;
  //NOTE: Relay Functions Reverse,Input=0 -> ON, Input=1 -> OFF

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Set sketch compiling time
  //clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  
  //Trigger Start Condition
  if (dt.hour == 13 && dt.minute == 44 && dt.second == 0)
  {
    Serial.println("Switch Triggered");
    digitalWrite(12, HIGH); //Note Relay funtions reverse HIGH means OFF
  }
  //Trigger End Condition
  if (dt.hour == 13 && dt.minute == 44 && dt.second == 30)
  {
    Serial.println("Switch Triggered");
    digitalWrite(12, LOW); //Note Relay funtions reverse LOW means ON
  }

  delay(1000);
}
