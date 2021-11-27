#ifndef ZOMBIEWITHCLASSES_CLOCK_H
#define ZOMBIEWITHCLASSES_CLOCK_H

#include <time.h>

class Clock {
private:
    clock_t last;
    clock_t current;
    double dt;
    bool pause;

public:

    Clock();
    ~Clock();
    double getTime();
    void resetClock();
    void pauseClock();
};


#endif //ZOMBIEWITHCLASSES_CLOCK_H
