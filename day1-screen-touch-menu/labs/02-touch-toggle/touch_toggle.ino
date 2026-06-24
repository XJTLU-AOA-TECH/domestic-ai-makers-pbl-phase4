const int TOUCH_PIN = 4;
const int LED_PIN = 2;

bool deviceOn = false;
bool lastTouch = false;
unsigned long lastChangeTime = 0;
const unsigned long DEBOUNCE_MS = 250;

void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool touched = digitalRead(TOUCH_PIN) == HIGH;
  unsigned long now = millis();

  if (touched && !lastTouch && now - lastChangeTime > DEBOUNCE_MS) {
    deviceOn = !deviceOn;
    lastChangeTime = now;
    Serial.print("Mode: ");
    Serial.println(deviceOn ? "ON" : "OFF");
  }

  digitalWrite(LED_PIN, deviceOn ? HIGH : LOW);
  lastTouch = touched;
  delay(20);
}
