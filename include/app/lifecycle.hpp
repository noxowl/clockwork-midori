#ifndef CWMIDORI_APP_LIFECYCLE_H_
#define CWMIDORI_APP_LIFECYCLE_H_
#include "include/common/inputs.hpp"
#include "include/app/timer.hpp"
#include "include/app/logic.hpp"

class LifecycleManager {
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

    private:
        static bool initialized;
        static Inputs inputs;

        static CWMidori::Timer timer;
        static CWMidori::Logic logic;
};

#endif