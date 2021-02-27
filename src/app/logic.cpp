#include "include/app/logic.hpp"

bool CWMidori::Logic::holding = false;
bool CWMidori::Logic::pulling = false;
bool CWMidori::Logic::handling = false;
int CWMidori::Logic::holdingHands = 0;

CWMidori::Logic::Logic() {}

CWMidori::Logic::~Logic() {}

bool CWMidori::Logic::isSquareUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_SQUARE);
}

bool CWMidori::Logic::isSquareDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_SQUARE);
}

bool CWMidori::Logic::isCrossUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_CROSS);
}

bool CWMidori::Logic::isCrossDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_SQUARE);
}

bool CWMidori::Logic::isLTriggerUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_LTRIGGER);
}

bool CWMidori::Logic::isLTriggerDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_LTRIGGER);
}

bool CWMidori::Logic::isRTriggerUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_RTRIGGER);
}

bool CWMidori::Logic::isRTriggerDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_RTRIGGER);
}

bool CWMidori::Logic::isYAxisUp(Inputs& inputs) {
    return (inputs.axisY() > 0) || (inputs.axisY() < (-128 + 50));
}

bool CWMidori::Logic::isYAxisDown(Inputs& inputs) {
    return (0 > inputs.axisY()) & (inputs.axisY() > (-128 + 50));
}

void  CWMidori::Logic::setHold(const bool state) {
    holding = state;
}

void CWMidori::Logic::setPull(const bool state) {
    pulling = state;
}

void CWMidori::Logic::setHandling(const bool state) {
    handling = state;
}

void CWMidori::Logic::addHands() {
    ++holdingHands;
}

void CWMidori::Logic::removeHands() {
    --holdingHands;
}

void CWMidori::Logic::onProcessing(CWMidori::Timer& timer) {
    if (isHolding() & isPulling()) {
        timer.increase(holdingHands);
    } else if (!holding) {
        timer.decrease();
    }
}

void CWMidori::Logic::onHold(Inputs& inputs, CWMidori::Timer& timer) {
    if (isSquareDown(inputs)) {
        setHandling(true);
        setHold(true);
        addHands();
    }
    if (isHandling()) {
        if (isLTriggerDown(inputs)) {
            addHands();
        }
        if (isRTriggerDown(inputs)) {
            addHands();
        }
    }
}

void CWMidori::Logic::onPull(Inputs& inputs, CWMidori::Timer& timer) {
    if (isHolding() & isYAxisDown(inputs)) {
        setPull(true);
    }
}

void CWMidori::Logic::onRelease(Inputs& inputs, CWMidori::Timer& timer) {
    if (isHolding()) {
        if (isSquareUp(inputs)) {
            removeHands();
            setHandling(false);
            setHold(false);
            setPull(false);
            timer.initTickCounter();
        }
        if (isHandling()) {
            if (isLTriggerUp(inputs)) {
                removeHands();
            }
            if (isRTriggerUp(inputs)) {
                removeHands();
            }
        }
    }
    if (isPulling()) {
        if (isYAxisUp(inputs)) {
            setPull(false);
        }
    }
    if (!isHolding() & !isPulling() & !isHandling()) {
        if (isCrossUp(inputs)) {
            timer.init();
        }
    }
}

int CWMidori::Logic::currentHands() {
    return holdingHands;
}

bool CWMidori::Logic::isHolding() {
    return holding;
}

bool CWMidori::Logic::isPulling() {
    return pulling;
}

bool CWMidori::Logic::isHandling() {
    return handling;
}