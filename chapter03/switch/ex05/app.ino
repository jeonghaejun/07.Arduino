#include <Led.h>
#include <Button.h>

Led leds[4]{
    Led(8),
    Led(9),
    Led(10),
    Led(11)};

Button btn(4);

int current = 0;
//버튼이 누를 때마다 led순차 점멸
void work()
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
    current = (current + 1) % 4;
}

void setup()
{
    btn.setCallback(work);
}

void loop()
{
    btn.check(); // polling
}