#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int L_IN1 = 7;
const int L_IN2 = 8;
const int L_PWM = 9;
const int R_IN1 = 11;
const int R_IN2 = 12;
const int R_PWM = 13;

int carSpeed = 120;

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

void forward() { moveCar(carSpeed, carSpeed); }
void backward() { moveCar(-carSpeed, -carSpeed); }
void turnLeft() { moveCar(-carSpeed, carSpeed); }
void turnRight() { moveCar(carSpeed, -carSpeed); }
void stopCar() { moveCar(0, 0); }

void handleCommand(char command) {
  if (command == 'F') forward();
  else if (command == 'B') backward();
  else if (command == 'L') turnLeft();
  else if (command == 'R') turnRight();
  else if (command == 'S') stopCar();
  else if (command == '1') carSpeed = 80;
  else if (command == '2') carSpeed = 140;
  else if (command == '3') carSpeed = 200;
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Phase4-Car");
  pinMode(L_IN1, OUTPUT); pinMode(L_IN2, OUTPUT); pinMode(L_PWM, OUTPUT);
  pinMode(R_IN1, OUTPUT); pinMode(R_IN2, OUTPUT); pinMode(R_PWM, OUTPUT);
  stopCar();
  Serial.println("Bluetooth car ready. Send F/B/L/R/S.");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.print("Command: ");
    Serial.println(command);
    handleCommand(command);
  }
}
