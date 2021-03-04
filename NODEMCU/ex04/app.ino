#include <ESP8266WiFi.h>
#include <MiniCom.h>

// 5G는 연결 안됨...
const char *ssid = "HaeJun";
const char *password = "wjd661947";

MiniCom com(115200);
WiFiServer server(80); // 서버 소켓에 해당. 번호는 포트번호

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
    WiFi.mode(WIFI_STA); // STAND ALONE 모드
    wifi_connect();
    server.begin();
}

void loop()
{
    WiFiClient client = server.available(); // accept() 작업
    if (!client)                            // 접속이 없으면 바로 리턴
    {
        return;
    }

    // Wait until the client sends some data
    Serial.println("new client");
    while (!client.available())
    {
        delay(1);
    }

    //Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("content-Type: text/html"); // 응답 헤더
    client.println("");                        // do not forget this one  빈 줄 --> 헤더와 body를 구분한다.
    client.println("<!DOCTYPE HTML>");         // 응답 body
    client.println("<html>");
    client.print("HELLO WORLD!");
    client.println("</html>");
    delay(1);
    Serial.println("Client disonnected");
    Serial.println("");
}