#include <Led.h>

Led led(3);

    void setup()
{
    pinMode(8, INPUT);
}

void loop()
{
    int value = digitalRead(8);
    led.setValue(value);
}