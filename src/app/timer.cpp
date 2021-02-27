#include "include/app/timer.hpp"

CWMidori::Timer::Timer() {
}

CWMidori::Timer::~Timer() {
}

void CWMidori::Timer::init() {
    fetchDeviceTime();
    initTickCounter();
    delta = 0;
}

void CWMidori::Timer::initTickCounter() {
    tickCounter = 0;
    updatePreviousTick();
}

void CWMidori::Timer::fetchDeviceTime() {
    sceRtcGetCurrentClock(&deviceTime, 0);
    sceRtcGetCurrentTick(&deviceTick);
}

void CWMidori::Timer::updatePreviousTick() {
    previousTick = deviceTick;
}

void CWMidori::Timer::increase(int speed) {
    if (isTimePassed(0.5)) {
        switch (speed) {
            case 2:
                delta += 10;
                break;
            case 3:
                delta += 60;
                break;
            default:
                ++delta;
                break;
        }
    }
}

void CWMidori::Timer::decrease() {
    if (isTimePassed(1)) {
        if (delta > 0) {
            --delta;
        }
    }
}

u64 CWMidori::Timer::currentTick() {
    return deviceTick;
}

int CWMidori::Timer::currentSeconds() {
    return deviceTime.seconds;
}

long CWMidori::Timer::currentTimeLeft() {
    return delta;
}

bool CWMidori::Timer::isTimePassed(double sec) {
    tickCounter += deviceTick - previousTick;
    updatePreviousTick();
    if (tickCounter > (sec * CLOCKS_PER_SEC)) {
        tickCounter -= (sec * CLOCKS_PER_SEC);
        return true;
    } else {
        return false;
    }
}