#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int LED_PIN = 2;
bool blinkMode = false;

void handleCommand(String command) {
  command.trim();
  command.toUpperCase();

  if (command == "ON") {
    blinkMode = false;
    digitalWrite(LED_PIN, HIGH);
    SerialBT.println("Light ON");
  } else if (command == "OFF") {
    blinkMode = false;
    digitalWrite(LED_PIN, LOW);
    SerialBT.println("Light OFF");
  } else if (command == "BLINK") {
    blinkMode = true;
    SerialBT.println("Blink mode");
  } else {
    SerialBT.println("Unknown command. Try ON, OFF, BLINK.");
  }
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Phase4-Light");
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Bluetooth light ready. Send ON/OFF/BLINK.");
}

void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    handleCommand(command);
  }

  if (blinkMode) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(300);
  }
}
