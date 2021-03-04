// 버튼을 눌럿을 때
// LED가 blink되게 하고..
// 한번 더 눌렀을 때
// LED가 꺼지게 합니다.

#include <MiniCom.h>
#include <Led.h>
#include <Button.h>

//NodeMCU 핀번호 지정시 주의 사항****
Button btn(D5); // 5 : GPIO5를 의미함, D5로 표기해야 함.
Led led(D6);    // 6 : GPIO6를 의미함, D6로 표기해야 함.
MiniCom com;
bool state = false; // true: blink 모드, false: off 모드
int timer_id = -1;

void check()
{
    if (!state)
    {
        timer_id = com.setInterval(500, []() {
            com.print(0, "Blink mode");
            led.toggle();
        });
        state = true;
    }
    else
    {
        led.off();
        state = false;
        com.print(0, "Off mode");
        // timer_id 타이머를 꺼야 함
        SimpleTimer &timer = com.getTimer();
        timer.deleteTimer(timer_id);
    }
}

void setup()
{
    com.init();
    btn.setCallback(check);
    com.print(0, "Off mode");
}

void loop()
{
    btn.check();
    com.run();
}
