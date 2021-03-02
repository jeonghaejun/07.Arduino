#include <EEPROM.h>

int randomNumber;

void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(0));
}

void loop()
{
    // EEPROM 데이터 쓰기
    for (int i = 0; i < 100; i++)
    {
        randomNumber = random(256);
        EEPROM.write(i, randomNumber);
        delay(100);
    }

    Serial.println();
    for (int i = 0; i < 100; i++)
    {
        randomNumber = EEPROM.read(i);
        Serial.print("EEPROM Address : ");
        Serial.print(String(i) + "\t");
        Serial.print("Value: ");
        Serial.println(randomNumber);
        delay(100);
    }
    while (true)
        ; // 1회만 시행 후 대기
}