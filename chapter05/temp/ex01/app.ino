#include <MiniCom.h>
#include <Button.h>

MiniCom com;

void check()
{
    int value = analogRead(A0);                // 온도 센서 디지털값
    double ftp1 = (float)value / 1024.0 * 5.0; // 온도 센서 전압값
    ftp1 = ftp1 * 100.0;                       // 온도값 (1도/10mv)

    com.print_d(0, "T: ", ftp1);
}

void setup()
{
    com.init();
    com.setInterval(2000, check);
}

void loop()
{
    com.run();
}