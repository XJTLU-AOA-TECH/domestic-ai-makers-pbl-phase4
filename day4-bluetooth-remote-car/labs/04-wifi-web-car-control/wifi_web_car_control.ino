#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

WebServer server(80);

const int L_IN1 = 7;
const int L_IN2 = 8;
const int L_PWM = 9;
const int R_IN1 = 11;
const int R_IN2 = 12;
const int R_PWM = 13;

int carSpeed = 120;

void setMotor(int in1, int in2, int pwmPin, int speedValue) {
  speedValue = constrain(speedValue, -255, 255);
  if (speedValue > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwmPin, speedValue);
  } else if (speedValue < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(pwmPin, -speedValue);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(pwmPin, 0);
  }
}

void moveCar(int leftSpeed, int rightSpeed) {
  setMotor(L_IN1, L_IN2, L_PWM, leftSpeed);
  setMotor(R_IN1, R_IN2, R_PWM, rightSpeed);
}

void forward() { moveCar(carSpeed, carSpeed); }
void backward() { moveCar(-carSpeed, -carSpeed); }
void turnLeft() { moveCar(-carSpeed, carSpeed); }
void turnRight() { moveCar(carSpeed, -carSpeed); }
void stopCar() { moveCar(0, 0); }

String pageHtml() {
  return "<!doctype html><html><head><meta name='viewport' content='width=device-width,initial-scale=1'>"
         "<style>body{font-family:Arial;text-align:center}button{font-size:24px;margin:8px;padding:16px 24px}</style>"
         "</head><body><h1>Phase 4 Car Control</h1>"
         "<p><a href='/F'><button>Forward</button></a></p>"
         "<p><a href='/L'><button>Left</button></a><a href='/S'><button>Stop</button></a><a href='/R'><button>Right</button></a></p>"
         "<p><a href='/B'><button>Backward</button></a></p>"
         "</body></html>";
}

void setupRoutes() {
  server.on("/", []() { server.send(200, "text/html", pageHtml()); });
  server.on("/F", []() { forward(); server.send(200, "text/html", pageHtml()); });
  server.on("/B", []() { backward(); server.send(200, "text/html", pageHtml()); });
  server.on("/L", []() { turnLeft(); server.send(200, "text/html", pageHtml()); });
  server.on("/R", []() { turnRight(); server.send(200, "text/html", pageHtml()); });
  server.on("/S", []() { stopCar(); server.send(200, "text/html", pageHtml()); });
}

void setup() {
  Serial.begin(115200);
  pinMode(L_IN1, OUTPUT); pinMode(L_IN2, OUTPUT); pinMode(L_PWM, OUTPUT);
  pinMode(R_IN1, OUTPUT); pinMode(R_IN2, OUTPUT); pinMode(R_PWM, OUTPUT);
  stopCar();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Open: http://");
  Serial.println(WiFi.localIP());

  setupRoutes();
  server.begin();
}

void loop() {
  server.handleClient();
}
