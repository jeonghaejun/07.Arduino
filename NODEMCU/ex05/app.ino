#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <MiniCom.h>

// 5G는 연결 안됨...
const char *ssid = "HaeJun";
const char *password = "wjd661947";
const char *mqtt_server = "192.168.0.4"; // Mosquitto 브로커가 실행되는 PC 주소

MiniCom com(115200);
WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[50];
int value = 0;

void wifi_connect()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    com.print(0, "WiFi connected", true);
    IPAddress ip = WiFi.localIP();
    String ipstr = ip.toString();
    com.print(1, ipstr.c_str(), true);
}

void setup()
{
    pinMode(BUILTIN_LED, OUTPUT);
    Serial.begin(115200);
    wifi_connect();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback); // 토픽 수신 시 호출할 함수 등록
}

void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();

    if ((char)payload[0] == '1')
    {
        digitalWrite(BUILTIN_LED, LOW);
    }
    else
    {
        digitalWrite(BUILTIN_LED, HIGH);
    }
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP8266Client")) // 클라이언트 ID 중복 주의(여러개의 장치사용시 이름 중복 안된다.)
        {
            Serial.println("connected");
            // Once connected, publish an announcement...
            client.publish("outTopic", "hello world");
            // ... and resubscribe
            client.subscribe("inTopic");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void loop()
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();

    long now = millis();
    if (now - lastMsg > 2000)
    { // 2초 간격으로 publish
        lastMsg = now;
        ++value;
        snprintf(msg, 75, "hello world #%ld", value);
        Serial.print("Publish message: ");
        Serial.println(msg);
        client.publish("outTopic", msg);
    }
}