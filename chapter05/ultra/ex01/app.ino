#include <MiniCom.h>

int echoPin = 8;
int triggerPin = 9;

MiniCom com;

void check()
{
    // trigger 핀으로 10us의 펄스를 발생
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // echo 핀 입력으로 부터 거리를 cm 단위로 계산
    int distance = pulseIn(echoPin, HIGH) / 58;
    com.print_i(0, "Dist.(cm): ", distance);
}

void setup()
{
    com.init();
    com.setInterval(1000, check);
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}

void loop()
{
    com.run();
}