// Cài đặt sẵn các biến 
int IRDetectorPin = 2;  // chân để cắm đầu dương của LED thu hồng ngoại
int IRDetectorPin2 = 4;  // chân thứ 2 của LED thu thứ 2
int IRLEDPin = 12;      // những chân để cắm đầu dương của LED phát hồng ngoại
char DELIM = '\t';      // ký tự để chia cột trong Serial Monitor

// Cài đặt trước các hằng số nếu sau cần dùng
#define PI 3.1415926535897932384626433832795 
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886 // đổi độ sang radian
#define RAD_TO_DEG 57.295779513082320876798154814105

// Tốc độ giao tiếp cao nhất của Arduino là 115200 baud https://en.wikipedia.org/wiki/Baud
long baud_rate = 115200;

// Lưu trạng thái của cổng quang 1 và 2 bằng bool 0 hoặc 1
boolean photoGate; 
boolean lastState = 0;
boolean photoGate2; 
boolean lastState2 = 0;

int eventNum = 1; // Số lần vật đi qua cổng quang
long eventTime,eventTime2; // Thời điểm vật đi qua mỗi cổng quang ứng với số lần đó kể từ khi bắt đầu bật mạch

//extern volatile unsigned long timer0_millis; //Code để reset tính millis()
//unsigned long new_val=0;

void setup()
{
  Serial.begin(baud_rate); // Có lệnh này để mở được Serial Monitor để debug

  pinMode(IRDetectorPin, INPUT_PULLUP); // Mở những chân cắm LED thu thành INPUT. PULLUP: nối với trở 5k-20k có sẵn.
  pinMode(IRDetectorPin2, INPUT_PULLUP);
  pinMode(IRLEDPin, OUTPUT); // Mở những chân cắm LED phát thành OUTPUT.
  //pinMode(13, OUTPUT); // Có thể nối một LED có ánh sáng khả kiến để nó sáng lên khi cổng quanh chuyển đổi trạng thái
                         // LED 13 là LED có sẵn trên mạch (?)
  
  digitalWrite(IRLEDPin, HIGH); // Bật LED phát dùng tín hiệu HIGH

  //Serial.print("event");
  //Serial.print(DELIM);
  //Serial.print("time"); //Serial.print("Gate no.")
  //Serial.print(DELIM);
  //Serial.println("state");
  //Serial.println("======================");

}

void loop()
{
  // Đọc chân input:
  photoGate = digitalRead(IRDetectorPin);  // Mất tia hồng ngoại thì LED thu sẽ báo tín hiệu HIGH
  //digitalWrite(13, !photoGate); // Vẫn còn tia hồng ngoại thì LED ở cổng 13 sẽ tắt
  if (photoGate != lastState && photoGate != 0)  // Nếu có sự thay đổi trạng thái của cổng quang:
    {
      eventTime = millis(); // Đo eventTime ^ (đơn vị mili giây)
      Serial.print(eventNum);  // Báo eventNum ^
      Serial.print(DELIM); // Cách cột
      Serial.print("Gate1");  // Đây là cổng 1
      Serial.print(DELIM); // Cách 
      Serial.println(eventTime / 1000.0, 3);  // Báo eventTime sau khi chia 100 và lấy 3 chứ số hàng thập phân
      eventNum++; // Tăng eventNum lên 1
      //setMillis(new_val);
      delay(50); // Thời gian cách mỗi lần đo 
    }
  lastState = photoGate; // Reset lại trạng thái của cổng quang

  photoGate2 = digitalRead(IRDetectorPin2);
  if (photoGate2 != lastState2 && photoGate2 != 0)
    {
      eventTime2 = millis(); // Đo eventTime2 ^
      Serial.print(eventNum);  // Báo eventNum ^
      Serial.print(DELIM); // Cách cột
      Serial.print("Gate2");  // Đây là cổng 2
      Serial.print(DELIM); // Cách cột
      Serial.println(eventTime2 / 1000.0, 3); 
      //setMillis(new_val);
      delay(50); // Thời gian cách mỗi lần đo 
    }
  lastState2 = photoGate2; // Reset lại trạng thái của cổng quang

}
//void setMillis(unsigned long new_millis)
//{
  //uint8_t oldSREG = SREG;
  //cli();
  //timer0_millis = new_millis;
  //SREG = oldSREG;
//}
