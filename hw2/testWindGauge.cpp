#include <iostream>
#include "WindGauge.h"

int main(){
    WindGauge w;
    w.currentWindSpeed(10);
    w.currentWindSpeed(30);
    w.currentWindSpeed(12);
    w.currentWindSpeed(15);
    w.currentWindSpeed(15);
    w.dump();

    w.currentWindSpeed(16);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.dump();

    return 0;
}