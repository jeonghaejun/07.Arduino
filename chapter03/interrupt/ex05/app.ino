// 연습문제
// 자동 점멸 이동
// 버튼을 누를 때마다 지연 시간에 변경을 줌
// 200ms -> 400ms -> 600ms -> 800ms -> 200ms ....

#include <Led.h>
#include <Button.h>

Button btn(2);
Led leds[4]{
    Led(8),
    Led(9),
    Led(10),
    Led(11)};
int current = 0; //현재 켜져야 할 Led 인덱스

int intervals[4]{200, 400, 600, 800}; //조종할 interval 값 배열
int intervalIx = 0;                   //현재 운영할 interval의 인덱스

void blink()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == current)
        {
            leds[i].on();
        }
        else
        {
            leds[i].off();
        }
    }
    current = (current + 1) % 4;
}

void flash()
{
    if (!btn.debounce())
        return;
    intervalIx = (intervalIx + 1) % 4;
}

void setup()
{
    btn.attachInterrupt(flash, FALLING);
}

void loop()
{
    blink();
    delay(intervals[intervalIx]);
}
