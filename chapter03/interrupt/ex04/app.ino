#include <Button.h>
#include <Led.h>

Button btn(2);
Led leds[4]{
    Led(8),
    Led(9),
    Led(10),
    Led(11)};

int current = 0;
//버튼이 누를 때마다 led순차 점멸

void flash()
{
    if (!btn.debounce())
        return;

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
    current = (current + 1) % 4;
}

void setup()
{
    btn.attachInterrupt(flash, FALLING);
}

void loop()
{
    btn.check(); // polling
}