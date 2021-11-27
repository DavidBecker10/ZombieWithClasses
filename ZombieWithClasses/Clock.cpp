#include "Clock.h"
#include <iostream>
Clock::Clock() :last(clock()), current(0.0), dt(0.0), pause(false) {

}

Clock::~Clock() {

}

double Clock::getTime() {
    if (pause) {
        resetClock();
        return 0.0;
    }
    current = clock();
    dt = (double)(current - last) / CLOCKS_PER_SEC;
    //std::cout << current / (double)CLOCKS_PER_SEC << std::endl;
    return dt;
}

void Clock::resetClock() {
    pause = false;
    last = clock();
}

void Clock::pauseClock() {
    pause = true;
}
