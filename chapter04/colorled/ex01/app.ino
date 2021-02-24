// led modul 한개씩 켜졌다가 꺼지기
#include <Led.h>

Led red(9), green(10), blue(11);

void setup()
{
}

void loop()
{
    one_color();
    two_color();
    three_color();
}

void led_off()
{
    red.off();
    green.off();
    blue.off();
}

void one_color()
{
    red.on();
    delay(2000);
    red.off();

    green.on();
    delay(2000);
    green.off();

    blue.on();
    delay(2000);
    blue.off();
}

void two_color()
{
    red.on();
    green.on();
    delay(2000);
    led_off();

    green.on();
    blue.on();
    delay(2000);
    led_off();

    blue.on();
    red.on();
    delay(2000);
    led_off();
}

void three_color()
{
    red.on();
    green.on();
    blue.on();
    delay(2000);
    led_off();
}