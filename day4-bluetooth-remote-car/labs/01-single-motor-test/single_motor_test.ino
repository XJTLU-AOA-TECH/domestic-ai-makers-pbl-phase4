const int IN1 = 7;
const int IN2 = 8;
const int PWM_PIN = 9;

void motor(int speedValue) {
  speedValue = constrain(speedValue, -255, 255);
  if (speedValue > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_PIN, speedValue);
  } else if (speedValue < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(PWM_PIN, -speedValue);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(PWM_PIN, 0);
  }
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  motor(120);
  delay(1500);
  motor(0);
  delay(800);
  motor(-120);
  delay(1500);
  motor(0);
  delay(1200);
}
