// 기준 거리로 진입하면 문을 열어줌
// 기준 거리를 벋어나면 문을 닫음
// 문 열기/닫기는 Led on/off로 대체
// 진입한 경우 벗어날때까지 거리 변화를 LCD에 출력

#include <MiniCom.h>
#include <Ultra.h>
#include <Led.h>
#include <Buzzer.h>

Ultra ultra(8, 9);
MiniCom com;
Buzzer buzzer(10);

int interval[]{
    100, 200, 400, 700, 1000};

void buzzer_off()
{
    com.print(0, "Dist.(cm): -");
    com.print(1, "interval: -");
    buzzer.stop();
}

void check()
{
    int distance = ultra.run();
    if (distance)
    {
        int ix = map(distance, 1, 15, 0, 4);
        buzzer.setoffTime(interval[ix]);
        com.print_i(0, "Dist.(cm): ", distance);
        com.print_i(1, "interval: ", interval[ix]);
    }
}

void setup()
{
    com.init();
    ultra.setThreshold(15, NULL, buzzer_off);
    com.setInterval(50, check);
    com.print(0, "Dist.(cm): -");
}

void loop()
{
    com.run();
    buzzer.run();
}