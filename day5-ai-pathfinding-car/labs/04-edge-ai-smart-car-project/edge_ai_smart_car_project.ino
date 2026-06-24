enum ControlMode {
  MODE_MANUAL,
  MODE_AUTO
};

ControlMode currentMode = MODE_MANUAL;

const int TRIG_PIN = 5;
const int ECHO_PIN = 6;
const int SOUND_PIN = 1;

int distanceRiskScore(float distanceCm) {
  if (distanceCm < 0) return 50;
  if (distanceCm <= 10) return 100;
  if (distanceCm >= 100) return 0;
  return map(distanceCm, 10, 100, 100, 0);
}

int soundRiskScore(int soundValue) {
  return constrain(map(soundValue, 20, 250, 0, 100), 0, 100);
}

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

int readSoundLevel() {
  int minValue = 4095;
  int maxValue = 0;
  for (int i = 0; i < 80; i++) {
    int value = analogRead(SOUND_PIN);
    if (value < minValue) minValue = value;
    if (value > maxValue) maxValue = value;
    delay(1);
  }
  return maxValue - minValue;
}

String edgeDecision(int riskScore) {
  if (riskScore >= 70) return "STOP";
  if (riskScore >= 35) return "SLOW";
  return "FORWARD";
}

void runAutoMode() {
  float distanceCm = readDistanceCm();
  int soundLevel = readSoundLevel();
  int risk = distanceRiskScore(distanceCm) * 0.7 + soundRiskScore(soundLevel) * 0.3;
  String action = edgeDecision(risk);

  Serial.print("Auto risk: ");
  Serial.print(risk);
  Serial.print(" | Action: ");
  Serial.println(action);

  // Replace these prints with real car action functions.
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Edge AI Smart Car Project started");
  Serial.println("Send M for manual mode, A for auto mode.");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'M') {
      currentMode = MODE_MANUAL;
      Serial.println("Mode: MANUAL");
    } else if (command == 'A') {
      currentMode = MODE_AUTO;
      Serial.println("Mode: AUTO");
    } else if (currentMode == MODE_MANUAL) {
      Serial.print("Manual command: ");
      Serial.println(command);
    }
  }

  if (currentMode == MODE_AUTO) {
    runAutoMode();
    delay(800);
  }
}
