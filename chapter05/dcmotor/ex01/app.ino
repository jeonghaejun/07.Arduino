// int ENPin = 9;  // enable 핀 설정
// int in1Pin = 8; // in1 핀 설정
// int in2Pin = 7; // in2 핀 설정

int ENPin = 3;  // enable 핀 설정
int in1Pin = 5; // in1 핀 설정
int in2Pin = 4; // in2 핀 설정

void setup()
{
    // 시리얼 통신 설정
    Serial.begin(9600);

    // 핀 입출력 설정
    pinMode(ENPin, OUTPUT);
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
}

void loop()
{
    Serial.println("Forward");
    analogWrite(ENPin, 255); //  PWM제어 ... 0 ~ 255
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    delay(1000);

    Serial.println("Stop");
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    delay(1000);

    Serial.println("Back");
    analogWrite(ENPin, 150); //  PWM제어 ... 0 ~ 255
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    delay(1000);

    Serial.println("Stop");
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    delay(1000);
}