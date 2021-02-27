#ifndef CWMIDORI_APP_TIMER_H
#define CWMIDORI_APP_TIMER_H

#include <psptypes.h>
#include <time.h>
#include <psprtc.h>
#include <cmath>

namespace CWMidori {
    class Timer {
        public:
            Timer();
            ~Timer();
            void init();
            void initTickCounter();
            long currentTimeLeft();
            void fetchDeviceTime();
            void increase(const int speed);
            void decrease();
            u64 currentTick();
            int currentSeconds();
        
        private:
            pspTime deviceTime;
            u64 deviceTick;
            u64 previousTick;
            u64 tickCounter;
            long delta;
            void updatePreviousTick();
            bool isTimePassed(const double sec);
    };
}

#endif