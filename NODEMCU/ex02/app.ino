// DHT11 온/습도 센서
// 2초 간격으로 온/습도 읽어서
// LCD에 출력
#include <DHT.h>
#include <MiniCom.h>

DHT dht11(D5, DHT11); // 2초 이상의 시간 간격으로 측정, 더 짧으면 에러 남.
MiniCom com;
// double temp = 0.;
// double humi = 0.;

void check()
{
    double temp = dht11.readTemperature();
    double humi = dht11.readHumidity();

    com.print_d(0, "Temp. :", temp);
    com.print_d(1, "Humi. :", humi);
}

void setup()
{
    com.init();
    dht11.begin();
    com.setInterval(4000, check);
}

void loop()
{
    com.run();
}