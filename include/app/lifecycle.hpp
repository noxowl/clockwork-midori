#ifndef COMMON_LIFECYCLE_H
#define COMMON_LIFECYCLE_H
#include "include/common/inputs.hpp"
#include "include/app/timer.hpp"

class ILifecycle {
    public:
        virtual void awake() = 0;
        virtual void onEnable() = 0;
        virtual void start() = 0;
        virtual void onInput() = 0;
        virtual void update() = 0;
        virtual void onRender() = 0;
        virtual void onGUI() = 0;
        virtual void onPause() = 0;
        virtual void onDisable() = 0;
        virtual void onDestroy() = 0;
    protected:
        virtual ~ILifecycle() {}
};

class LifecycleManager {
    private:
        static bool initialized;
        static Inputs inputs;

        static CWMidori::Timer midori_timer;

    public:
        LifecycleManager();
        ~LifecycleManager();
        void init();
        void callAwake();
        void callStart();
        void callInput();
        void callUpdate();
        void callRender();
        void callGUI();
        void callPause();
        void callDisable();
        void callDestroy();
};

#endif