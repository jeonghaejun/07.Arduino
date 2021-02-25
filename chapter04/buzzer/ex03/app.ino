// 수동 부저로 멜로디 연주하기
// 곰세마리

#define NOTE_C4 262 // 4옥타브 도
#define NOTE_D4 294 // 4옥타브 레
#define NOTE_E4 330 // 4옥타브 미
#define NOTE_G4 392 // 4옥타브 솔
#define NOTE_A4 440 // 4옥타브 라
#define NOTE_C5 523 // 5옥타브 레
#define NUM 49

int melody[NUM] = {                                       // 곰 세마리
    NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,          // 도도도도도
    NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,          // 미솔솔미도
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, // 솔솔미솔솔미
    NOTE_C4, NOTE_C4, NOTE_C4,                            // 도도도
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,                   // 솔솔미도
    NOTE_G4, NOTE_G4, NOTE_G4,                            // 솔솔솔
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,                   // 솔솔미도
    NOTE_G4, NOTE_G4, NOTE_G4,                            // 솔솔솔
    NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,                   // 솔솔미도
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4,          // 솔솔솔라솔
    NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4,                   // 도솔도솔
    NOTE_E4, NOTE_D4, NOTE_C4};                           // 미레도

// 음표 길이
int noteDuration[NUM] = {
    4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 8, 8, 8, 8, 2, 4, 4, 4, 4, 4, 4, 2};

const int speaker_pin = 2;

void setup()
{
    pinMode(speaker_pin, OUTPUT);
}

void loop()
{
    int m, d, dd;
    for (m = 0; m < NUM; m++)
    {
        d = 1000 / noteDuration[m];
        dd = d * 1.3; // 음 출력 시간(4분 음표 325ms)

        tone(speaker_pin, melody[m], d); // 비동기 함수
        delay(dd);                       // 딜레이에 의존하기 때문에 다른일을 못한다.
    }
    delay(1000);
}