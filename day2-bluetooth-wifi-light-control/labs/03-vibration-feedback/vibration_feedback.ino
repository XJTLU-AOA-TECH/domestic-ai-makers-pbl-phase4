const int VIBRATION_PIN = 5;

void vibrate(int durationMs) {
  digitalWrite(VIBRATION_PIN, HIGH);
  delay(durationMs);
  digitalWrite(VIBRATION_PIN, LOW);
}

void setup() {
  pinMode(VIBRATION_PIN, OUTPUT);
}

void loop() {
  vibrate(120);      // short feedback
  delay(1000);
  vibrate(350);      // long feedback
  delay(1000);
  vibrate(100);      // double feedback
  delay(150);
  vibrate(100);
  delay(1500);
}
