// Initialize variables
int IRDetectorPin = D4;  // variable for the detector Pin of the photogate
int IRLEDPin = D8;      // variable for the IR LED Pin of the photogate
int interval = 75;
char DELIM = '\t';      // data column delimitter character
#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
long baud_rate = 9600;  // use the fastest baud rate poassible.

boolean photoGate;      // stores the state of the photoGate  
boolean lastState = 0;  // stores the last State of photoGate used to detect a change

int eventNum = 1;
long eventTime;

void setup()
{
  Serial.begin(baud_rate);         // setup Serial communication

  pinMode(IRDetectorPin, INPUT_PULLUP);
  pinMode(IRLEDPin, OUTPUT);    // setup IRLEDPin as an output
  pinMode(13, OUTPUT);          // setup debug LED as an output
  
  digitalWrite(IRLEDPin, HIGH); // turn on the IR LED

  Serial.print("event");
  Serial.print(DELIM);

  Serial.print("time");
  Serial.print(DELIM);

  Serial.println("state");
  Serial.println("======================");

}

// the loop routine runs over and over again forever:
void loop()
{
  // read the input pin:
  photoGate = digitalRead(IRDetectorPin);  // Gate is HIGH when IR beam is broken.
  if (photoGate != lastState && photoGate != 0)  // if there is a change, 
    {
      eventTime = millis();
      Serial.print(eventNum);  // print out the event number
      Serial.print(DELIM);
      Serial.print(eventTime / 1000.0, 3);  // print out the # of seconds 
                            // as a floating point decimal
      Serial.print(DELIM);
      Serial.println(photoGate); // print out the state of the gate
      eventNum++; // increment the eventNum
      delay(75);
    }
  lastState = photoGate;

}
