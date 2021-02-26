// 1초 동안에 사운드가 몇번 감지 됬는지...
// LCD,Serial로 출력

#include <MiniCom.h>

MiniCom com;
int count = 0;

void check()
{
    int value = digitalRead(8);
    if (value == HIGH)
    {
        count++;
    }
}

void print()
{
    com.print_i(0, "Detect: ", count, true);
    count = 0;
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    com.setInterval(1000, print);
}

void loop()
{
    com.run();
}