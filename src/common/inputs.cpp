#include "include/common/inputs.hpp"

SceCtrlData Inputs::inputData;
SceCtrlLatch Inputs::inputLatch;

Inputs::Inputs() {
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
}

Inputs::~Inputs() {
}

void Inputs::peekBuffer(const int count) {
    sceCtrlPeekBufferPositive(&inputData, count);
}

void Inputs::readLatch() {
    sceCtrlReadLatch(&inputLatch);
}

bool Inputs::isHold(const int button) {
    return (inputLatch.uiPress & button);
}

bool Inputs::isDown(const int button) {
    return inputLatch.uiMake & button;
}

bool Inputs::isUp(const int button) {
    return inputLatch.uiBreak & button;
}

int Inputs::unsafePressedButton() {
    return inputLatch.uiMake;
}

int Inputs::button() {
    if(inputData.Buttons != 0) {
        switch(inputData.Buttons) {
            case PSP_CTRL_START:
                return PspCtrlButtons::PSP_CTRL_START;
            case PSP_CTRL_SELECT:
                return PspCtrlButtons::PSP_CTRL_SELECT;
            case PSP_CTRL_UP:
                return PspCtrlButtons::PSP_CTRL_UP;
            case PSP_CTRL_DOWN:
                return PspCtrlButtons::PSP_CTRL_DOWN;
            case PSP_CTRL_RIGHT:
                return PspCtrlButtons::PSP_CTRL_RIGHT;
            case PSP_CTRL_LEFT:
                return PspCtrlButtons::PSP_CTRL_LEFT;
            case PSP_CTRL_CROSS:
                return PspCtrlButtons::PSP_CTRL_CROSS;
            case PSP_CTRL_CIRCLE:
                return PspCtrlButtons::PSP_CTRL_CIRCLE;
            case PSP_CTRL_SQUARE:
                return PspCtrlButtons::PSP_CTRL_SQUARE;
            case PSP_CTRL_TRIANGLE:
                return PspCtrlButtons::PSP_CTRL_TRIANGLE;
            case PSP_CTRL_RTRIGGER:
                return PspCtrlButtons::PSP_CTRL_RTRIGGER;
            case PSP_CTRL_LTRIGGER:
                return PspCtrlButtons::PSP_CTRL_LTRIGGER;
            default:
                return this->inputData.Buttons;
        }
    }
    return 0;
}

char Inputs::axisX() {
    return inputData.Lx;
}

char Inputs::axisY() {
    return inputData.Ly;
}