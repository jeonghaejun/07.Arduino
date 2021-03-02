#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Led.h>

// RFID 태그 값 하나를 EEPROM에 기록

#define RST_PIN 9 // reset핀은 9번으로 설정
#define SS_PIN 10 // SS핀은 10번으로 설정
// SS핀은 데이터를 주고받는 역할의 핀( SS = Slave Selector )

byte uid[4];
MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522 객체 생성
Led led(4);

void read_uid()
{
    for (int i = 0; i < 4; i++)
    {
        uid[i] = EEPROM.read(100 + i);
        Serial.print(uid[i]);
        Serial.print(" ");
    }
    Serial.println();
}

bool check_uid(byte *target)
{
    for (int i = 0; i < 4; i++)
    {
        if (uid[i] != target[i])
        {
            return false;
        }
    }
    return true;
}

void setup()
{
    Serial.begin(9600);
    SPI.begin();
    mfrc.PCD_Init();
    read_uid();
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

    // 이번에 읽은 RFID태그가 EEPROM에 저장된 값과 일치하는지 조사
    // 일치하면 서보모터로 문을 열어주고,
    // 일치하지 않으면 긴 beep경고음 출력
    if (check_uid(mfrc.uid.uidByte)) // 일치하는 경우
    {
        Serial.println("ID matched!");
    }
    else // 일치하지 않는 경우
    {
        led.on();
        delay(1000);
        led.off();
        Serial.println("ID Missmatched!");
    }
    Serial.println();
}