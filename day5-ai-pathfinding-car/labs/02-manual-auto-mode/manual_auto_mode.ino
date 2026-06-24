enum ControlMode {
  MODE_MANUAL,
  MODE_AUTO
};

ControlMode currentMode = MODE_MANUAL;

void handleManualCommand(char command) {
  if (command == 'F') Serial.println("Manual: forward");
  else if (command == 'B') Serial.println("Manual: backward");
  else if (command == 'L') Serial.println("Manual: left");
  else if (command == 'R') Serial.println("Manual: right");
  else if (command == 'S') Serial.println("Manual: stop");
}

void runAutoDecision() {
  Serial.println("Auto: read sensors and decide action");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Manual/Auto Mode started");
  Serial.println("Send M for manual, A for auto, F/B/L/R/S for manual commands.");
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
      handleManualCommand(command);
    }
  }

  if (currentMode == MODE_AUTO) {
    runAutoDecision();
    delay(1000);
  }
}
