#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const int LED_PIN = 2;

WebServer server(80);
bool blinkMode = false;

String pageHtml() {
  return "<!doctype html><html><head><meta name='viewport' content='width=device-width,initial-scale=1'>"
         "<style>body{font-family:Arial;text-align:center}button{font-size:24px;margin:8px;padding:16px 24px}</style>"
         "</head><body><h1>Phase 4 Light Control</h1>"
         "<p><a href='/on'><button>ON</button></a><a href='/off'><button>OFF</button></a><a href='/blink'><button>BLINK</button></a></p>"
         "</body></html>";
}

void setupRoutes() {
  server.on("/", []() { server.send(200, "text/html", pageHtml()); });
  server.on("/on", []() { blinkMode = false; digitalWrite(LED_PIN, HIGH); server.send(200, "text/html", pageHtml()); });
  server.on("/off", []() { blinkMode = false; digitalWrite(LED_PIN, LOW); server.send(200, "text/html", pageHtml()); });
  server.on("/blink", []() { blinkMode = true; server.send(200, "text/html", pageHtml()); });
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
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
  if (blinkMode) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(300);
  }
}
