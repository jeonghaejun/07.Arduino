// 처음에는 연주 중지 상태
// 버튼을 누르면 연주 시작
// 버튼을 다시 누르면 연주 중지
// 1. 다시 연주할 때는 처음부터 연주..
// 2. 다시 연주할 때는 정지된 시점 이후부터 연주..

#include <MiniCom.h>
#include <Melody.h>
#include <Button.h>
#include <Led.h>

#include "pitches.h"
#include "pirates.h"

MiniCom com;
int length = sizeof(notes) / sizeof(int);
Melody melody(2, notes, durations, length);

Button btn(3);
Led leds[]{
    Led(8),
    Led(9),
    Led(10),
    Led(11),
};

void onClick()
{
    if (!btn.debounce())
        return;
    int state = melody.toggle(true);
}

// count: 켜야할 Led 개수
void turnLed(int count)
{
    for (int i = 0; i < 4; i++)
    {
        if (count == 0)
        {
            leds[i].off();
            continue;
        }
        if (i < count)
        {
            leds[i].on();
        }
        else
        {
            leds[i].off();
        }
    }
}

void led_level()
{
    int note = melody.getNote();
    int count = 0;
    if (note != 0) //켜야할 Led 개수 결정
    {
        count = map(note, 220, 440, 1, 4);
    }
    turnLed(count);
}

void setup()
{
    com.init();
    com.setInterval(100, led_level);
    btn.attachInterrupt(onClick, FALLING);
}

void loop()
{
    com.run();
    melody.run();
}