#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>

// A/D 변환 결과 시리얼 모니터 창 표시
// 디지털 값과 전압값
const int var_pin = A0; // 가변저항 연결핀
int analog_val;         // 아날로그 값 저장 변수
SimpleTimer timer;

LiquidCrystal_I2C myLCD(0x27, 16, 2); // myLCD 객체 생성

void check()
{
    int digital_val;
    float ff;
    digital_val = analogRead(var_pin);     // 아날로그 값 디지털 변환
    ff = (float)digital_val / 1023. * 5.0; // 전압값 계산
    // LCD로 출력
    // 출력 모양
    // Volt: 4.3V
    // D. value: 805
    // 아두이노 문자열 클래스 : String

    char msg[17];

    String buf = "Volt: "; // String buf = "Volt: "+ ff + "V"; --> 에러
    buf = buf + ff + "v";

    sprintf(msg, "%-16s", buf.c_str());
    // sprintf(msg, "Volt: %fV", ff);  // 이거는 안됨 --> 아두이노의 sprintf는 float 지원하지 않음.

    myLCD.setCursor(0, 0);
    // myLCD.print(buf.c_str());
    myLCD.print(msg);

    buf = "D.value: "; // buf = "D.value: "+ digital_val; --> 에러
    buf = buf + digital_val;

    // sprintf(msg, "%-16s", buf.c_str());
    sprintf(msg, "D.value: %4d", digital_val);

    myLCD.setCursor(0, 1);
    // myLCD.print(buf.c_str());
    myLCD.print(msg);
}

void setup()
{
    Serial.begin(9600);
    myLCD.begin();
    timer.setInterval(100, check);
}

void loop()
{
    timer.run();
}