#include <SPI.h>
#include <MFRC522.h>
#include <Led.h>
#include <EEPROM.h>

// RFID 태그 값 하나를 EEPROM에 기록

#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SS핀은 10번으로 설정
// SS핀은 데이터를 주고받는 역할의 핀( SS = Slave Selector )

MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522 객체 생성
Led led(4);

void setup()
{
    Serial.begin(9600);
    SPI.begin();
    mfrc.PCD_Init();
}

// EEPROM 100번째에 uid 저장
void write_uid(byte *uid)
{
    for (int i = 0; i < 4; i++)
    {
        EEPROM.write(100 + i, uid[i]);
    }
}

void loop()
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial())
    {
        // 태그 접촉이 되지 않았을때 또는 ID가 읽혀지지 않았을때
        delay(500);
        return;
    }

    led.on();
    delay(100);
    led.off();

    Serial.print("Card UID:"); // 태그의 ID출력
    // 태그의 ID출력하는 반복문.태그의 ID사이즈(4)까지
    for (byte i = 0; i < 4; i++)
    {
        // mfrc.uid.uidByte[0] ~ mfrc.uid.uidByte[3]까지 출력
        Serial.print(mfrc.uid.uidByte[i]);
        Serial.print(" "); // id 사이의 간격 출력
    }
    // EEPROM에 uid 저장
    write_uid(mfrc.uid.uidByte);
    Serial.println();
}