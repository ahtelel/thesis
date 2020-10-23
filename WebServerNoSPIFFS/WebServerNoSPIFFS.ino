#include "ESP8266WiFi.h"
#include "ESPAsyncWebServer.h"
#include "ESPAsyncTCP.h"
#include "FS.h"
#include "Hash.h"

int IRDetectorPin = 2;  // variable for the detector Pin of the photogate
int IRLEDPin = 12;      // variable for the IR LED Pin of the photogate

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

boolean photoGate;      // stores the state of the photoGate  
boolean lastState = 0;  // stores the last State of photoGate used to detect a change

const char* ssid = "daotuandat";  
const char* password = "12345678"; 

AsyncWebServer server(80);

String readEventTime() {
  // read the input pin:
  photoGate = digitalRead(IRDetectorPin);  // Gate is HIGH when IR beam is broken.
  float eventTime = 0;
  if (photoGate != lastState && photoGate != 0)  // if there is a change, 
    {
      eventTime = millis()/1000;
      Serial.print(eventTime);  // print out the # of seconds 
      return String(eventTime);
    }
  lastState = photoGate;
}

void setup() {
  Serial.begin(115200);
  pinMode(IRDetectorPin, INPUT_PULLUP);
  pinMode(IRLEDPin, OUTPUT);    // setup IRLEDPin as an output
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readEventTime().c_str());
  });

  // Start server
  server.begin();
}

void loop() {}
