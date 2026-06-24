const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

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

String decideAction(float distanceCm) {
  if (distanceCm < 0) return "STOP - no distance data";
  if (distanceCm < 20) return "STOP - too close";
  if (distanceCm < 50) return "SLOW FORWARD";
  return "FORWARD";
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Rule-Based Decision started");
}

void loop() {
  float distanceCm = readDistanceCm();
  String action = decideAction(distanceCm);

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm | Action: ");
  Serial.println(action);

  delay(800);
}
