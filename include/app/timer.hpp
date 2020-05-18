#ifndef MIDORI_CORE_TIMER_H
#define MIDORI_CORE_TIMER_H
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
        private:
            long time;

        public:
            Timer();
            ~Timer();
            void init(long targetTime);
            void reduceTime();
            long currentTimeLeft();
    };
}

#endif