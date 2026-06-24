const int BUTTON_PIN = 0;
const unsigned long LONG_PRESS_MS = 1000;

bool lastPressed = false;
unsigned long pressStartTime = 0;
int mode = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  bool pressed = digitalRead(BUTTON_PIN) == LOW;
  unsigned long now = millis();

  if (pressed && !lastPressed) {
    pressStartTime = now;
  }

  if (!pressed && lastPressed) {
    unsigned long duration = now - pressStartTime;
    if (duration >= LONG_PRESS_MS) {
      mode = 0;
      Serial.println("Long press: reset mode to 0");
    } else {
      mode = (mode + 1) % 3;
      Serial.print("Short press: switch to mode ");
      Serial.println(mode);
    }
  }

  lastPressed = pressed;
  delay(20);
}
