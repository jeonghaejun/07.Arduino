// ex01을 클래스화 시켜서 적용

#include <MiniCom.h>
#include <Ultra.h>

Ultra ultra(8, 9);
MiniCom com;

void check()
{
    int distance = ultra.getDistance();
    com.print_i(0, "Dist.(cm): ", distance);
}

void setup()
{
    com.init();
    com.setInterval(1000, check);
}

void loop()
{
    com.run();
}