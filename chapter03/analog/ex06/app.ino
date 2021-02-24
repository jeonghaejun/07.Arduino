// LED 4개 구성
// 가변 저항을 돌려서
// LED가 차례대로 켜지도록...

#include <Led.h>

Led leds[] = {
    Led(8),
    Led(9),
    Led(10),
    Led(11),
};

void setup()
{
}

void turn(int count)
{
    for (auto &led : leds)
    {
        led.off();
    }

    if (count == 0)
        return;

    for (int i = 0; i < count; i++)
    {
        leds[i].on();
    }
}

void loop()
{
    int val, count;
    val = analogRead(A0);
    count = map(val, 0, 1023, 4, 0);
    turn(count);
    delay(100);
}