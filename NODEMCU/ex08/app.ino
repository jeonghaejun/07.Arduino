// ex07 JSON처리

#include <MqttCom.h>
#include <DHT.h>
#include <PWMLed.h>
#include <ArduinoJson.h>

const char *ssid = "HaeJun";
const char *password = "wjd661947";
const char *server = "192.168.0.4";
const char *sub_topic = "test/led"; //<-- 아두이노 토픽 하나밖에 지정 못한다.
                                    //      test/#, test/+ 지원안됨

MqttCom com(ssid, password);
DHT dht11(D5, DHT11);
PWMLed led(D6);

// 제어하기 위해서
// LED PWM 제어
void subscribe(char *topic, uint8_t *payload, unsigned int length)
{
    char buf[128];
    memcpy(buf, payload, length);
    buf[length] = '\0';

    // JSON 문자열 -> 객체로 변환
    StaticJsonDocument<128> doc;
    auto error = deserializeJson(doc, buf);
    if (error)
    {
        Serial.println("deserializeJson() error");
        Serial.println(error.c_str());
        return;
    }

    const char *device = doc["divice"];
    int value = doc["value"].as<int>(); // 정수로 변환

    Serial.println(topic);
    Serial.println(buf);

    // int value=atoi(buf);  // 문자열을 정수로 변환
    // 참고 : atof() --> 문자열을 double로 변환
    led.setValue(value);
}

// 센서 데이터를 서버로 전송
void publish()
{
    double temp = dht11.readTemperature();
    double humi = dht11.readHumidity();
    com.print_d(0, "Temp. :", temp);
    com.print_d(1, "Humi. :", humi);

    String value = "";
    value += temp;
    com.publish("user1/home/livingroom/temp", value.c_str());
    value = "";
    value += humi;
    com.publish("user1/home/livingroom/humi", value.c_str());
}

void setup()
{
    // com.init(server); // publish만 하는 경우
    com.init(server, sub_topic, subscribe); // subscribe하는 경우
    com.setInterval(2000, publish);
    dht11.begin();
}

void loop()
{
    com.run();
}