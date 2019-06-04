#include <Servo.h>

Servo servo;

int servoPositions[] = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 0, 180, 90, 45, 150, 30, 90};

void setup() {
  servo.attach(D0);
}

void loop() {
  for (int i = 0; i <= sizeof(servoPositions); i += 1) {
    servo.write(servoPositions[i]);
    delay(250);
  }
}
