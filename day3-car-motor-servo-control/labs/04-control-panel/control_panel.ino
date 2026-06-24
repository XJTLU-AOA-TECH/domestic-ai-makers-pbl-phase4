struct Button {
  int x;
  int y;
  int w;
  int h;
  const char* command;
};

Button buttons[] = {
  {90, 20, 80, 40, "FORWARD"},
  {20, 70, 80, 40, "LEFT"},
  {110, 70, 80, 40, "STOP"},
  {200, 70, 80, 40, "RIGHT"},
  {90, 120, 80, 40, "BACK"}
};

bool insideButton(int touchX, int touchY, Button button) {
  return touchX >= button.x && touchX <= button.x + button.w &&
         touchY >= button.y && touchY <= button.y + button.h;
}

void handleTouch(int touchX, int touchY) {
  for (int i = 0; i < 5; i++) {
    if (insideButton(touchX, touchY, buttons[i])) {
      Serial.print("Command: ");
      Serial.println(buttons[i].command);
      return;
    }
  }
  Serial.println("No command");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Control Panel lab started");
}

void loop() {
  // Replace simulated coordinates with real touch readings.
  handleTouch(120, 35);
  delay(1000);
  handleTouch(145, 90);
  delay(1000);
}
