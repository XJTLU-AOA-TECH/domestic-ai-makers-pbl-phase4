const int BUZZER_PIN = 4;

void playTone(int frequency, int durationMs) {
  tone(BUZZER_PIN, frequency, durationMs);
  delay(durationMs + 50);
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  playTone(800, 150);   // confirm
  delay(800);
  playTone(1200, 100);  // warning start
  playTone(1200, 100);  // warning repeat
  delay(1200);
}
