#include <Led.h>
#include <TimerOne.h>

Led led(8);

void flash()
{
    led.toggle();
}
void setup()
{
}
void loop()
{
    Timer1.initialize(200000);
    Timer1.attachInterrupt(flash);
}
