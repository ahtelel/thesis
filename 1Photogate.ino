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

int eventNum = 1; // Số lần vật đi qua cổng quang
long eventTime; // Thời điểm vật đi qua cổng quang ứng với số lần đó kể từ khi bắt đầu bật mạch

//extern volatile unsigned long timer0_millis;
//unsigned long new_val=0;

void setup()
{
  Serial.begin(baud_rate);         // Có lệnh này để mở được Serial Monitor để debug

  pinMode(IRDetectorPin, INPUT_PULLUP); // Mở những chân cắm LED thu thành INPUT. PULLUP: nối với trở 5k-20k có sẵn.
  pinMode(IRLEDPin, OUTPUT);    // Mở những chân cắm LED phát thành OUTPUT.
  pinMode(13, OUTPUT);          // Có thể nối một LED có ánh sáng khả kiến để nó sáng lên khi cổng quanh chuyển đổi trạng thái
  
  digitalWrite(IRLEDPin, HIGH); // Bật LED phát dùng tín hiệu HIGH

  //Serial.print("event");
  //Serial.print(DELIM);
  //Serial.print("time");
  //Serial.print(DELIM);
  //Serial.println("state");
  //Serial.println("======================");

}

void loop()
{
  // Đọc chân input:
  photoGate = digitalRead(IRDetectorPin);  // Mất tia hồng ngoại thì LED thu sẽ báo tín hiệu HIGH
  digitalWrite(13, !photoGate); // Vẫn còn tia hồng ngoại thì LED ở cổng 13 sẽ tắt
  if (photoGate != lastState && photoGate != 0)  // Nếu có sự thay đổi trạng thái của cổng quang:
    {
      eventTime = millis(); // Đo eventTime ^ (đơn vị mili giây)
      Serial.print(eventNum);  // Báo eventNum ^
      Serial.print(DELIM); // Cách cột
      Serial.print(eventTime / 1000.0, 3);  // Báo eventTime sau khi chia 100 và lấy 3 chứ số hàng thập phân
      Serial.print(DELIM); // Cách cột
      eventNum++; // Tăng eventNum lên 1
      //setMillis(new_val);
      delay(75); // Thời gian cách mỗi lần đo 
    }
  lastState = photoGate; // Reset lại trạng thái của cổng quang

}
//void setMillis(unsigned long new_millis)
//{
  //uint8_t oldSREG = SREG;
  //cli();
  //timer0_millis = new_millis;
  //SREG = oldSREG;
//}
