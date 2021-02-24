#include <MsTimer2.h>
#include <Led.h>
Led led(7);
Led led2(8);

void flash1()
{
    led.toggle();
}
void flash2()
{
    led2.toggle();
}

void setup()
{
    MsTimer2::set(500, flash1);
    MsTimer2::set(1000, flash2);
    MsTimer2::start();
}

void loop()
{
}

// 둘중 하나만 동작
