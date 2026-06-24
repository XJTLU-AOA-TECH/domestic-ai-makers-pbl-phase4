struct Button {
  int x;
  int y;
  int w;
  int h;
  const char* label;
};

Button startButton = {20, 40, 100, 50, "START"};
Button stopButton = {140, 40, 100, 50, "STOP"};

bool insideButton(int touchX, int touchY, Button button) {
  return touchX >= button.x && touchX <= button.x + button.w &&
         touchY >= button.y && touchY <= button.y + button.h;
}

void handleTouch(int touchX, int touchY) {
  if (insideButton(touchX, touchY, startButton)) {
    Serial.println("Touched: START");
  } else if (insideButton(touchX, touchY, stopButton)) {
    Serial.println("Touched: STOP");
  } else {
    Serial.println("Touched: empty area");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Touch Button Detection lab started");
}

void loop() {
  // Replace these simulated coordinates with real touch readings.
  handleTouch(50, 60);
  delay(1000);
  handleTouch(170, 60);
  delay(1000);
  handleTouch(10, 10);
  delay(1000);
}
