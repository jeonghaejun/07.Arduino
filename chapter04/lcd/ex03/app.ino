#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C myLCD(0x27, 16, 2);

void setup()
{
    // put your setup code here, to run once:
    myLCD.begin();
    myLCD.setCursor(0, 0);                                   // 커서 홈(0,0)
    myLCD.print("1++++++++23--------45********67########8"); // 40문자 저장
    myLCD.setCursor(0, 1);                                   // 커서 2행 1열(0, 1)
    myLCD.print("1++++++++23--------45********67########8"); // 40문자 저장
}

void loop()
{
    // put your main code here, to run repeatedly:
    int n;
    for (n = 0; n < 80; n++)
    {
        myLCD.scrollDisplayLeft(); // 왼쪽으로 한 칸씩 이동
        delay(500);
    }
    delay(4000); // 4초 대기
    for (n = 0; n < 80; n++)
    {
        myLCD.scrollDisplayRight(); // 오른쪽으로 한 칸씩 이동
        delay(500);
    }
    delay(4000); // 4초 대기
}