#include <EEPROM.h>

String password = "";

void setup()
{
    Serial.begin(9600);
    //EEPROM에서 읽어서 PASSWORD복원
    int addr = 0;
    for (int i = 0; i < 20; i++)
    {
        char ch = EEPROM.read(i);
        if (ch == '\0') // 문자열의 끝이면 중지
        {
            break;
        }
        password += ch;
    }
    Serial.println("password: " + password);
}

void loop()
{
}