#include <Servo.h>

const int L_IN1 = 7;
const int L_IN2 = 8;
const int L_PWM = 9;
const int R_IN1 = 11;
const int R_IN2 = 12;
const int R_PWM = 13;
const int SERVO_PIN = 10;

const int SPEED = 120;
Servo directionServo;

void setMotor(int in1, int in2, int pwmPin, int speedValue) {
  speedValue = constrain(speedValue, -255, 255);
  if (speedValue > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwmPin, speedValue);
  } else if (speedValue < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(pwmPin, -speedValue);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(pwmPin, 0);
  }
}

void moveCar(int leftSpeed, int rightSpeed) {
  setMotor(L_IN1, L_IN2, L_PWM, leftSpeed);
  setMotor(R_IN1, R_IN2, R_PWM, rightSpeed);
}

void forward() { moveCar(SPEED, SPEED); }
void backward() { moveCar(-SPEED, -SPEED); }
void turnLeft() { moveCar(-SPEED, SPEED); }
void turnRight() { moveCar(SPEED, -SPEED); }
void stopCar() { moveCar(0, 0); }

void lookLeft() { directionServo.write(150); }
void lookCenter() { directionServo.write(90); }
void lookRight() { directionServo.write(30); }

void setup() {
  pinMode(L_IN1, OUTPUT); pinMode(L_IN2, OUTPUT); pinMode(L_PWM, OUTPUT);
  pinMode(R_IN1, OUTPUT); pinMode(R_IN2, OUTPUT); pinMode(R_PWM, OUTPUT);
  directionServo.attach(SERVO_PIN);
  lookCenter();
  stopCar();
}

void loop() {
  forward(); delay(1000);
  stopCar(); delay(500);
  turnLeft(); delay(700);
  stopCar(); delay(500);
  turnRight(); delay(700);
  stopCar(); delay(500);
  lookLeft(); delay(500);
  lookCenter(); delay(500);
  lookRight(); delay(500);
  lookCenter(); delay(1000);
}
