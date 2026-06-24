// Touchscreen libraries differ by module.
// Replace these placeholder drawing functions with your display library calls.

struct Button {
  int x;
  int y;
  int w;
  int h;
  const char* label;
};

Button startButton = {20, 40, 100, 50, "START"};
Button stopButton = {140, 40, 100, 50, "STOP"};

void drawButton(Button button) {
  Serial.print("Draw button: ");
  Serial.print(button.label);
  Serial.print(" at ");
  Serial.print(button.x);
  Serial.print(", ");
  Serial.println(button.y);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Draw Buttons lab started");
  drawButton(startButton);
  drawButton(stopButton);
}

void loop() {
  delay(1000);
}
