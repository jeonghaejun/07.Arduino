#include <MiniCom.h>

MiniCom com;

void check()
{
    Serial.println("check calld");
}

void setup()
{
    com.init();
    com.setInterval(100, check);
}

void loop()
{
    com.run();
}