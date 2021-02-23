#include <Led.h>
#include <Button.h>

Led led(8);
Button btn(4);

void work()
{
    led.toggle();
}

void setup()
{
    btn.setCallback(work);
}

void loop()
{
    btn.check();
}