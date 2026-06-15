#include <WiFi.h>
#include <WebServer.h>

// ---- WiFi credentials ----
const char* ssid     = "Kuzey";
const char* password = "kuzeykuzey";

const int sensorPin = 34; // ADC1 pin

const int sensorMin = 0;     // raw=0    -> %100 (fully wet)
const int sensorMax = 4096;  // raw=4096 -> %0   (dry/nothing)

const int sulamaEsigiRaw = 3000; // raw value above this -> dry, needs watering

WebServer server(80);

int okuYuzde(int raw) {
  int pct = map(raw, sensorMin, sensorMax, 100, 0);
  return constrain(pct, 0, 100);
}

void handleRoot() {
  int raw = analogRead(sensorPin);
  int pct = okuYuzde(raw);

  String wateringStatus;
  String color;
  if (raw >= sulamaEsigiRaw) {
    wateringStatus = "🚨 Time to water your plant!";
    color = "#ff4d4d";
  } else {
    wateringStatus = "✅ Soil moisture is sufficient.";
    color = "#4CAF50";
  }

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<title>Soil Moisture Sensor</title>";
  html += "<style>";
  html += "body{font-family:Arial;text-align:center;background:#f0f0f0;padding-top:50px;}";
  html += "h1{font-size:60px;color:#333;}";
  html += ".box{background:white;border-radius:20px;padding:30px;margin:20px auto;width:300px;box-shadow:0 4px 10px rgba(0,0,0,0.1);}";
  html += ".status{font-size:22px;font-weight:bold;color:" + color + ";margin-top:20px;}";
  html += "</style></head><body>";
  html += "<div class='box'>";
  html += "<h2>Soil Moisture Status</h2>";
  html += "<h1>" + String(pct) + "%</h1>";
  html += "<p>Raw Value: " + String(raw) + "</p>";
  html += "<div class='status'>" + wateringStatus + "</div>";
  html += "</div>";
  html += "<p style='color:#888;'>This page automatically refreshes every 5 seconds.</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
