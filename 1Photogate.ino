// Cài đặt sẵn các biến 
int IRDetectorPin = 2;  // những chân để cắm đầu dương của LED thu hồng ngoại
int IRLEDPin = 7;      // những chân để cắm đầu dương của LED phát hồng ngoại
char DELIM = '\t';      // ký tự để chia cột trong Serial Monitor

// Cài đặt trước các hằng số nếu sau cần dùng
#define PI 3.1415926535897932384626433832795 
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886 // đổi độ sang radian
#define RAD_TO_DEG 57.295779513082320876798154814105

// Tốc độ giao tiếp cao nhất của Arduino là 115200 baud https://en.wikipedia.org/wiki/Baud
long baud_rate = 115200;  // use the fastest baud rate poassible.

// Lưu trạng thái của cổng quang bằng bool 0 hoặc 1
boolean photoGate; 
boolean lastState = 0;

int eventNum = 1; //
long eventTime;
//extern volatile unsigned long timer0_millis;
//unsigned long new_val=0;

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
  digitalWrite(13, !photoGate); // turns on the LED if the gate is NOT broken
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
      //setMillis(new_val);
      delay(75);
    }
  lastState = photoGate;

}
//void setMillis(unsigned long new_millis)
//{
  //uint8_t oldSREG = SREG;
  //cli();
  //timer0_millis = new_millis;
  //SREG = oldSREG;
//}
