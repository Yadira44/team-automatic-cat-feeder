#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

int motorPin = 8;

int feedHour = 9;       
int feedMinute = 0;      
int motorRunTime = 5000; // Motor runs for 5 seconds (5000 ms)

bool alreadyFed = false;


void setup() {
  Serial.begin(9600);

  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }

  Serial.println("Cat Feeder Ready!");
}


void loop() {

  // Get current time from RTC
  DateTime now = rtc.now();

  int hour = now.hour();
  int minute = now.minute();

  // Display current time
  Serial.print("Current Time: ");
  Serial.print(hour);
  Serial.print(":");

  if (minute < 10) {
    Serial.print("0");
  }

  Serial.println(minute);


  if (hour == feedHour && minute == feedMinute && !alreadyFed) {

    Serial.println("FEEDING TIME!");

    // Turn motor ON
    digitalWrite(motorPin, HIGH);

    // Keep motor running for selected amount of time
    delay(motorRunTime);

    // Turn motor OFF
    digitalWrite(motorPin, LOW);

    Serial.println("Feeding complete!");

    alreadyFed = true;
  }


  if (minute != feedMinute || hour != feedHour) {
    alreadyFed = false;
  }

  delay(1000);
}
