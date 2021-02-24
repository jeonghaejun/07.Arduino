//led1 --> 200ms 간격으로 blink
//led2 --> 400ms 간격으로 blink
//led3 --> 600ms 간격으로 blink
//led4 --> 800ms 간격으로 blink
// 버튼을 눌럿을 때 led1의 blink동작을 on/off하세요.
//-->timer를 제어해서..

#include <SimpleTimer.h>
#include <Led.h>
#include <Button.h>

SimpleTimer timer;

Led led1(8);
Led led2(9);
Led led3(10);
Led led4(11);
int timer1Id;

Button btn(3);

void blink1()
{
    led1.toggle();
}
void blink2()
{
    led2.toggle();
}
void blink3()
{
    led3.toggle();
}
void blink4()
{
    led4.toggle();
}

// 버튼이 눌러졌을 때 호출할 함수
void onClick()
{
    if (!btn.debounce())
        return;
    timer.toggle(timer1Id);
}

void setup()
{
    timer1Id = timer.setInterval(200, blink1);
    timer.setInterval(400, []() { led2.toggle(); });
    timer.setInterval(600, []() { led3.toggle(); });
    timer.setInterval(800, []() { led4.toggle(); });
    // btn.attachInterrupt(onClick, FALLING);
    // btn.attachInterrupt([]() {if(!btn.debounce())return; //<--인터럽트 방식
    //     timer.toggle(timer1Id); }, FALLING);
    btn.setCallback([]() { led1.off(); timer.toggle(timer1Id); }); //<--polling 방식
}

void loop()
{
    timer.run();
    btn.check(); //polling방식
}