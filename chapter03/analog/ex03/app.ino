// 버튼을 누른 후 5초 동안만 아날로그 값 측정
// 이 기간 동안 LED는 켜짐
// 5초 후 LED꺼지고, 값은 측정되지 않음
// 5초 이내에 버튼을 다시 누르면 정지.
// 힌트: SimpleTimer 의 setTimeout()
#include <SimpleTimer.h>
#include <Led.h>
#include <Button.h>

const int var_pin = A0;

SimpleTimer timer;
Button btn(3);
Led led(8);
int timerId = -1;

// 버튼의 클릭 핸들러
void start()
{
    if (!btn.debounce())
        return;
    // 작업 시작
    if (timerId == -1) // 타이머가 가동 중인지 여부 검사
    {
        led.on();                                //LED켜기
        timerId = timer.setInterval(100, check); //0.1초 간격 타이머 시작
        timer.setTimeout(5000, stop);            // 5초 후 타임아웃 stop 호춣
    }
    else
    {
        stop();
    }
}

void stop()
{
    led.off();                  // LED끄기
    timer.deleteTimer(timerId); // 측정 타이머 제거
    timerId = -1;
}

void setup()
{
    Serial.begin(9600);
    btn.attachInterrupt(start, FALLING);
}

void loop()
{
    timer.run();
}

void check()
{
    int digital_val;
    float ff;
    digital_val = analogRead(var_pin); // 아날로그 값 디지털 변환

    ff = (float)digital_val / 1023. * 5.0; // 전압값 계산

    Serial.print("Input Voltage(0~5V) = ");
    Serial.println(ff); // 입력 전압값 출력(0~5V)

    Serial.print("Digital Value(0~1023) = ");

    Serial.println(digital_val); // 변환된 디지털 값 출력(0~1023)
    Serial.println("---------------------------------------------");
}