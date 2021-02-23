// Switch 눌려질 때마다 LED on/off 점멸(외부 인터럽트 사용)
const int sw_pin = 2;           // 스위치 연결핀(INT1 핀)
const int led_pin = 8;          // LED 연결핀
volatile boolean led_st = HIGH; // LED 초기 상태(OFF)
// 외부 인터럽트1 처리 함수
void flash(void)
{
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
}
void loop() {}