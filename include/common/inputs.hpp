#ifndef COMMON_INPUTS_H
#define COMMON_INPUTS_H

#include <pspctrl.h>

class Inputs {
    private:
        static SceCtrlData inputData;

    public:
        Inputs();
        ~Inputs();
        void peekBuffer(int count);
        int button();
        char axisX();
        char axisY();
};

#endif