const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

const int L_IN1 = 7;
const int L_IN2 = 8;
const int L_PWM = 9;
const int R_IN1 = 11;
const int R_IN2 = 12;
const int R_PWM = 13;

int carSpeed = 100;

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
void slowForward() { moveCar(70, 70); }
void stopCar() { moveCar(0, 0); }

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.0343 / 2.0;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(L_IN1, OUTPUT); pinMode(L_IN2, OUTPUT); pinMode(L_PWM, OUTPUT);
  pinMode(R_IN1, OUTPUT); pinMode(R_IN2, OUTPUT); pinMode(R_PWM, OUTPUT);
  stopCar();
}

void loop() {
  float distanceCm = readDistanceCm();

  if (distanceCm < 0 || distanceCm < 20) {
    stopCar();
    Serial.println("Decision: STOP");
  } else if (distanceCm < 50) {
    slowForward();
    Serial.println("Decision: SLOW FORWARD");
  } else {
    forward();
    Serial.println("Decision: FORWARD");
  }

  delay(300);
}
