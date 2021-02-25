#include <MiniCom.h>
#include <Buzzer.h>

MiniCom com;
Buzzer buzzer(8);
unsigned long intervals[]{
    100, 200, 400, 700, 1000};

void check()
{
    int value = analogRead(A0);
    int distance = map(value, 0, 1023, 0, 9);
    com.print_i(0, "distance: ", distance);
    if (distance >= 5)
    {
        buzzer.stop();
        com.print(1, "buzzer off");
    }
    else
    {
        unsigned long interval = intervals[distance];
        buzzer.setoffTime(interval);
        com.print_i(1, "off time:", interval);
    }
}

void setup()
{
    com.init();
    com.setInterval(100, check);
}

void loop()
{
    com.run();
    buzzer.run();
}