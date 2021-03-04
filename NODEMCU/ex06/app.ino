#include <MqttCom.h>

const char *ssid = "HaeJun";
const char *password = "wjd661947";
const char *server = "192.168.0.4";
const char *sub_topic = "test/led"; //<-- 아두이노 토픽 하나밖에 지정 못한다.
                                    //      test/#, test/+ 지원안됨

MqttCom com(ssid, password);

// 제어하기 위해서
void subscribe(char *topic, uint8_t *payload, unsigned int length)
{
    char buf[128];
    memcpy(buf, payload, length);
    buf[length] = '\0';

    Serial.println(topic);
    Serial.println(buf);
}

// 센서 데이터를 서버로 전송
void publish()
{
    com.publish("test/greet", "hello world!");
}

void setup()
{
    // com.init(server); // publish만 하는 경우
    com.init(server, sub_topic, subscribe); // subscribe하는 경우
    com.setInterval(2000, publish);
}

void loop()
{
    com.run();
}