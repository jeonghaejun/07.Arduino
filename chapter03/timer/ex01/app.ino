#include <Led.h>

Led led(8);

void setup()
{
}

void loop()
{
    delay(500);
    led.toggle();
}

// 시간이 걸리는 다른 작업하면...