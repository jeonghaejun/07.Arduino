// Switch 눌려질 때마다 LED on/off 점멸(외부 인터럽트 사용)
const int sw_pin = 2;           // 스위치 연결핀(INT1 핀)
const int led_pin = 8;          // LED 연결핀
volatile boolean led_st = HIGH; // LED 초기 상태(OFF)
volatile unsigned long t1, t2;
// 외부 인터럽트1 처리 함수
void flash(void)
{
    // 채터링 체크 : 200ms 이내에 스위치가 또 눌려진 상태이면 무시
    t2 = millis(); // 현재 시간 저장
    // 인터럽트 시간 간격 체크
    if ((t2 - t1) < 200)
        return; // 200ms 보다 작으면 무시
    else
        t1 = t2; // 인터럽트 발생 시간 갱신

    led_st = !led_st;              // LED 상태 반전
    digitalWrite(led_pin, led_st); // LED 상태 반전 출력
}
void setup()
{
    pinMode(sw_pin, INPUT_PULLUP);
    // 외부 인터럽트 설정
    // attachInterrupt(1, flash, FALLING);
    attachInterrupt(digitalPinToInterrupt(sw_pin), flash, FALLING);
    pinMode(led_pin, OUTPUT);      // LED 연결핀 출력 설정
    digitalWrite(led_pin, led_st); // LED 초기상태 출력

    t1 = millis(); // 프로그램 시작 시간 저장
}
void loop() {}