const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

String aiLabel = "clear";

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.0343 / 2.0;
}

String decidePath(float distanceCm, String label) {
  if (distanceCm < 0) return "stop";
  if (label == "stop") return "stop";
  if (label == "left") return "left";
  if (label == "right") return "right";
  if (distanceCm < 20) return "turn";
  return "forward";
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Intelligent Pathfinding Project started");
}

void loop() {
  float distanceCm = readDistanceCm();
  String action = decidePath(distanceCm, aiLabel);

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm | AI label: ");
  Serial.print(aiLabel);
  Serial.print(" | Action: ");
  Serial.println(action);

  // Replace these prints with real motor/servo action functions.
  delay(800);
}
