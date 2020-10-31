#include <Ultrasonic.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <Wire.h>
// Instantiate trig and echo pins for ultrasonic sensors
Ultrasonic ultrasonic (D1, D2);
// Replace with your network credentials
const char* ssid = "ssid";
const char* password = "pass";

AsyncWebServer server(8080);

String getDistance() {
  // Read Distance
  float d = ultrasonic.read();
  if (isnan(d)) {
    Serial.println("Failed to read from HC-SR04 sensor!");
    return "";
  }
  else {
    Serial.println(d);
    return String(d);
  }
}
void setup () {
  // Serial port for debugging purposes
  Serial.begin (115200);

  // Initialize SPIFFS
  if (! SPIFFS.begin ()) {
    Serial.println ("An Error has occurred while mounting SPIFFS");
    return;
  }
  //Wifi config
  IPAddress local_IP(192, 168, 1, 22);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress primaryDNS(8, 8, 8, 8); // optional
  IPAddress secondaryDNS(8, 8, 4, 4); // optional
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)){
    Serial.println("STA failed to configure");
  }
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());

  // Route for web page
  server.on ("/", HTTP_GET, [] (AsyncWebServerRequest * request) {
    request-> send (SPIFFS, "/index.html");
  });
  server.on ("/distance", HTTP_GET, [] (AsyncWebServerRequest * request) {
    request-> send_P (200, "text / plain", getDistance(). c_str ());
  });

  // start server
  server.begin ();
}
void loop() {
}
