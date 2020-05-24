#include "include/app/timer.hpp"

CWMidori::Timer::Timer() {
}

CWMidori::Timer::~Timer() {
}

void CWMidori::Timer::init(long targetTime) {
    time = targetTime;
}

long CWMidori::Timer::currentTimeLeft() {
    return time;
}

void CWMidori::Timer::increaseTime(int speed) {
    if (speed == 1) {
        ++time;
    } else {
        time += pow(10, speed);
    }
}

void CWMidori::Timer::reduceTime() {
    if (time > 0) {
        --time;
    }
}