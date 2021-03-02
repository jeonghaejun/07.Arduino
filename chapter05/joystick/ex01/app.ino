// 조이스틱의  x,y값을 읽어 LCD에 출력

#include <MiniCom.h>
#include <Led.h>
#include <Button.h>

MiniCom com;
Led led(8);
Button btn(A2);

void check()
{
    // 평상시 0, 최대 -255,+255 사이의 값을 가지도록 해석
    int x = analogRead(A1);
    int y = analogRead(A0);
    x = map(x, 0, 1023, -255, 255);
    y = map(y, 0, 1023, -255, 255);
    com.print_i(0, "x: ", x, "Y: ", y);
}

void blink()
{
    // if (!btn.debounce())
    //     return;
    led.toggle();
}

void setup()
{
    com.init();
    com.setInterval(100, check);
    btn.setCallback(blink); // 하드웨어에 지원 필요.. 우노: D2, D3만 attachInterrupt 사용가능
}

void loop()
{
    com.run();
    btn.check();
}