const int LED_PIN = 2;
int mode = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (mode == 0) {
    digitalWrite(LED_PIN, HIGH);
    delay(700);
    digitalWrite(LED_PIN, LOW);
    delay(700);
  } else if (mode == 1) {
    digitalWrite(LED_PIN, HIGH);
    delay(120);
    digitalWrite(LED_PIN, LOW);
    delay(120);
  } else {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
  }

  mode = (mode + 1) % 3;
}
