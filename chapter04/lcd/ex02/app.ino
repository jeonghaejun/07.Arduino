#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C myLCD(0x27, 16, 2); // myLCD 객체 생성
void setup()
{
    // put your setup code here, to run once:
    myLCD.begin(); // LCD 초기화

    myLCD.setCursor(0, 0);        // 커서 홈(0,0)
    myLCD.print("I2C LCD Test!"); // 문자열 표시

    myLCD.setCursor(0, 1);          // 커서 2행 1열(0, 1)
    myLCD.print("Hello, Arduino!"); // 문자열 표시
}
void loop()
{
    // 반복 실행 내용 없음
}