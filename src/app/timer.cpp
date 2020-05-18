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

void CWMidori::Timer::reduceTime() {
    if (time > 0) {
        --time;
    }
}