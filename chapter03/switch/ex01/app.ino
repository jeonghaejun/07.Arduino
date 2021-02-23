#include <Led.h>

Led led1(9);
Led led2(8);

int sw1 = 3; // 풀업
int sw2 = 4; // 풀다운

void setup()
{
    pinMode(sw1, INPUT);
    pinMode(sw2, INPUT);
}

void loop()
{
    int v1, v2;
    // 풀업 : 평시에 H, 누르면 L
    v1 = digitalRead(sw1);
    led1.setValue(!v1);

    // 풀다운 : 평시에 L, 누르면 H
    v2 = digitalRead(sw2);
    led2.setValue(v2);
}