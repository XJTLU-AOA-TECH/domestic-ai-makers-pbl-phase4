#include <Servo.h>

const int SERVO_PIN = 10;
Servo feedbackServo;

void setup() {
  feedbackServo.attach(SERVO_PIN);
}

void loop() {
  feedbackServo.write(0);
  delay(1000);
  feedbackServo.write(90);
  delay(1000);
  feedbackServo.write(180);
  delay(1000);
}
