const int SLIDER_X = 20;
const int SLIDER_W = 220;

int speedFromTouch(int touchX) {
  int constrainedX = constrain(touchX, SLIDER_X, SLIDER_X + SLIDER_W);
  return map(constrainedX, SLIDER_X, SLIDER_X + SLIDER_W, 0, 100);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Speed Slider lab started");
}

void loop() {
  // Replace simulated touchX values with real touchscreen readings.
  int simulatedTouchX[] = {20, 80, 160, 240};

  for (int i = 0; i < 4; i++) {
    int speedValue = speedFromTouch(simulatedTouchX[i]);
    Serial.print("Speed: ");
    Serial.println(speedValue);
    delay(1000);
  }
}
