#include <Led.h>

Led leds[4]{
    Led(4),
    Led(5),
    Led(6),
    Led(7)};

int current = 0;

void setup()
{
}

void loop()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == current)
        {
            leds[i].on();
        }
        else
        {
            leds[i].off();
        }
    }
    delay(500);
    current = (current + 1) % 4; // 나머지 연산자: 0, 1, 2, 3
}