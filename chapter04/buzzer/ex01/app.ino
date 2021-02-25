// 부저 울리기(능동 부저)
const int buzzer_pin = 2; // 부저 연결핀

void setup()
{
    // put your setup code here, to run once:
    pinMode(buzzer_pin, OUTPUT); // 부저 연결핀 출력 설정
}

void loop()
{
    // put your main code here, to run repeatedly:
    digitalWrite(buzzer_pin, HIGH); // 부저 연결핀 HIGH 출력
    delay(2000);                    // 2초 대기

    digitalWrite(buzzer_pin, LOW); // 부저 연결핀 LOW 출력
    delay(2000);                   // 2초 대기
}