#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

RTC_DS3231 rtc;

// Create servo objects
Servo servo1, servo2, servo3, servo4, servo5, servo6;

void setup() {
  Serial.begin(115200);

  // Attach servos
  servo1.attach(14);
  servo2.attach(27);
  servo3.attach(26);
  servo4.attach(25);
  servo5.attach(33);
  servo6.attach(32);

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Optional: set RTC time once
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  // Array of servo objects
  Servo servos[] = {
    servo1,
    servo2,
    servo3,
    servo4,
    servo5,
    servo6
  };

  for (int i = 0; i < 6; i++) {

    // Move servo to 90° (open)
    servos[i].write(90);

    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.println(" opened");

    // Read RTC time
    DateTime now = rtc.now();

    Serial.print("Time: ");
    Serial.print(now.hour());
    Serial.print(":");
    Serial.print(now.minute());
    Serial.print(":");
    Serial.println(now.second());

    delay(10000); // Wait 10 seconds

    // Move servo back to 0° (close)
    servos[i].write(0);

    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.println(" closed");

    delay(500); // Small delay before next servo
  }
}
