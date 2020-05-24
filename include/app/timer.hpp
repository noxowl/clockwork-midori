#ifndef CWMIDORI_APP_TIMER_H
#define CWMIDORI_APP_TIMER_H

#include <cmath>
// #include "include/common/lifecycle.hpp"

namespace CWMidori {
    // class Timer : public ILifecycle {
    //     virtual void awake();
    //     virtual void onEnable();
    //     virtual void start();
    //     virtual void onInput();
    //     virtual void update();
    //     virtual void onRender();
    //     virtual void onGUI();
    //     virtual void onPause();
    //     virtual void onDisable();
    //     virtual void onDestroy();

    //     long time;
    // };
    class Timer {
        public:
            Timer();
            ~Timer();
            void init(long targetTime);
            void increaseTime(int speed);
            void reduceTime();
            long currentTimeLeft();
        
        private:
            long time;
    };
}

#endif