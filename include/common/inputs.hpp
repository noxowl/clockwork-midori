#ifndef CWMIDORI_COMMON_INPUTS_H_
#define CWMIDORI_COMMON_INPUTS_H_

#include <pspctrl.h>

class Inputs {
    public:
        Inputs();
        ~Inputs();
        
        void peekBuffer(const int count);
        void readLatch();

        bool isHold(const int button);
        bool isUp(const int button);
        bool isDown(const int button);

        int rawPressedButton();
        int button();
        char axisX();
        char axisY();
    
    private:
        static SceCtrlData inputData;
        static SceCtrlLatch inputLatch;
};

#endif