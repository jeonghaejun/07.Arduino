#include <MiniCom.h>

MiniCom com;
int buzzer = 8;

void check()
{
    int d_value = analogRead(A0);
    int a_value = d_value * 5 / 1024.;
    com.print_i(0, "D: ", d_value);
    com.print_i(1, "A: ", a_value);

    if (d_value > 630)
    {
        digitalWrite(buzzer, HIGH);
        // 통신을 통해 알람 발송..(다음주 통신 배우고 나서)
    }
    else
    {
        digitalWrite(buzzer, LOW);
    }
}

void setup()
{
    com.init();
    com.setInterval(1000, check);
    pinMode(8, OUTPUT);
}

void loop()
{
    com.run();
}