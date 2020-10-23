#include <AFMotor.h>

AF_DCMotor motor(4); // Tạo động cơ #4, 64KHz pwm 

char junk;
String inputString="";

void setup() 
{
   Serial.begin(9600); // mở cổng Serial monitor 9600 bps 
   Serial.println("Start"); 
   motor.setSpeed(255); // chọn tốc độ maximum 255`/255
} 

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //Đọc lệnh đưa vào
      inputString += inChar;        //Biến lệnh đưa vào thành 1 string
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      //Xóa serial buffer
    if(inputString == "a"){         //Nếu string đưa vào là 'a', motor tiến
      motor.run(FORWARD); 
      delay(5); 
    }else if(inputString == "b"){   //Nếu string đưa vào là 'b', motor lùi
      motor.run(BACKWARD);
      delay(5);
    }else if(inputString == "c"){   //Nếu string đưa vào là 'c', motor dừng
      motor.run(RELEASE);
      delay(5);
    }
    inputString = "";
  }
}
