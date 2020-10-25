#define BLYNK_PRINT Serial
#define TRIG_PIN 3
#define ECHO_PIN 2
#define TRIG_PIN2 5
#define ECHO_PIN2 4

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "hn32yJ5p9jIjrr_YHGxlDDn17usduimc";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "daotuandat";
char pass[] = "12345678";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&Serial);

void setup()
{
  // Debug console
  Serial.begin(ESP8266_BAUD);
  Blynk.begin(auth, wifi, ssid, pass);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);

}

void loop()
{
  long duration,Range,duration2,Range2;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  Range = duration / 29.1 / 2;
  // Duplicate of above code
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  Range2 = duration2 / 29.1 / 2;
  Serial.println("Distance_(cm): ");
  Serial.print(Range);
  // Periodically printing both distance values into virtual pin V5
  Blynk.run();
  Blynk.virtualWrite(V5,Range);
  delay(50);
  Blynk.virtualWrite(V5,Range2);
  delay(50);
}
