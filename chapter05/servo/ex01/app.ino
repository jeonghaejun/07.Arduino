#include <Servo.h>
#include <MiniCom.h>
Servo myServo;           // 사용할 서보 모터명 선언
const int servo_pin = 7; // 서보 모터 연결핀

MiniCom com;

void control()
{
    // 조이스틱의 x 값으로 서보 모터의 움직임을 제어..
    int value = analogRead(A1);
    int angle = map(value, 0, 1023, 180, 0);
    myServo.write(angle);
    com.print_i(0, "Angle: ", -angle + 90);
}

void setup()
{
    myServo.attach(servo_pin); // 사용할 서보명에 핀 할당
    com.init();
    com.setInterval(100, control);
}
void loop()
{
    com.run();
}