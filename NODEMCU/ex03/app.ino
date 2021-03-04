#include <ESP8266WiFi.h>
#include <MiniCom.h>

// 5G는 연결 안됨...
const char *ssid = "HaeJun";
const char *password = "wjd661947";

MiniCom com(115200);

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
    com.init();
    wifi_connect();
}

void loop()
{
}