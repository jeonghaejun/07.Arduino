#include <Button.h>
#include <Led.h>

Button btn(2);
Led led(8);

unsigned long t1, t2;

void flash()
{
    if (btn.debounce())
    {
        led.toggle();
    }
}

void setup()
{
    btn.attachInterrupt(flash, FALLING);
}

void loop()
{
}