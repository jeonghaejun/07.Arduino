// #include <LiquidCrystal_I2C.h>

// // '정' 패턴
// uint8_t name_j[8] = {B11101, B01011, B10101, B10101, B00110, B01001, B01001, B00110};
// // 'ㅎ' 패턴
// uint8_t name_h[8] = {B00110, B01111, B00000, B00110, B01001, B01001, B00110, B00000};
// // 'ㅐ' 패턴
// uint8_t name_h2[8] = {B00000, B10100, B10100, B11100, B10100, B10100, B10100, B00000};
// // '준' 패턴
// uint8_t name_j2[8] = {B01110, B00100, B01010, B00000, B11111, B00100, B01000, B01110};

// LiquidCrystal_I2C myLCD(0x27, 16, 2); // myLCD 객체 생성

// void setup()
// {
//     // put your setup code here, to run once:
//     myLCD.begin();
//     myLCD.createChar(0, name_j);  // '정' 패턴 코드 0으로 저장
//     myLCD.createChar(1, name_h);  // 'ㅎ' 패턴 코드 1으로 저장
//     myLCD.createChar(2, name_h2); // 'ㅐ' 패턴 코드 1으로 저장
//     myLCD.createChar(3, name_j2); // '준' 패턴 코드 2으로 저장
// }

// void loop()
// {
//     // put your main code here, to run repeatedly:
//     myLCD.setCursor(0, 0);          // 커서 2행 1열(0, 0)
//     myLCD.print("Hello, Arduino!"); // 문자열 표시
//     myLCD.setCursor(0, 1);          // 커서 2행 1열(0, 1)
//     myLCD.print("My name is ");     // 문자열 표시
//     myLCD.write(0);
//     myLCD.write(1);
//     myLCD.write(2);
//     myLCD.write(3);
// }

#include <LiquidCrystal_I2C.h>

// '정' 패턴
uint8_t name_j[8] = {B01110, B10001, B01110, B00000, B11111, B01010, B10000, B11111};
// 'ㅎ' 패턴
uint8_t name_h[8] = {B00100, B11111, B01110, B10001, B01110, B00000, B01010, B11111};
// 'ㅐ' 패턴
uint8_t name_h2[8] = {B11101, B00101, B01001, B10101, B10101, B00000, B10000, B11111};
// '준' 패턴
uint8_t name_j2[8] = {B00000, B01010, B11111, B11111, B01110, B00100, B00000, B00000};

LiquidCrystal_I2C myLCD(0x27, 16, 2); // myLCD 객체 생성

void setup()
{
    // put your setup code here, to run once:
    myLCD.begin();
    myLCD.createChar(0, name_j);  // '정' 패턴 코드 0으로 저장
    myLCD.createChar(1, name_h);  // 'ㅎ' 패턴 코드 1으로 저장
    myLCD.createChar(2, name_h2); // 'ㅐ' 패턴 코드 2으로 저장
    myLCD.createChar(3, name_j2); // 'ㅐ' 패턴 코드 2으로 저장
    myLCD.setCursor(0, 0);
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.setCursor(0, 1); // 커서 2행 1열(0, 1)
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
    myLCD.print("    ");
    myLCD.write(0);
    myLCD.write(1);
    myLCD.write(2);
    myLCD.write(3);
}

void loop()
{
    // put your main code here, to run repeatedly:
    int n;
    for (n = 0; n < 16; n++)
    {
        myLCD.scrollDisplayLeft(); // 왼쪽으로 한 칸씩 이동
        delay(1000);
    }

    for (n = 0; n < 16; n++)
    {
        myLCD.scrollDisplayRight(); // 오른쪽으로 한 칸씩 이동
        delay(1000);
    }
}