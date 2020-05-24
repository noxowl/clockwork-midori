#include "include/app/logic.hpp"

bool CWMidori::Logic::holding = false;
bool CWMidori::Logic::pulling = false;
bool CWMidori::Logic::main_hand = false;
int CWMidori::Logic::holding_hands = 0;

CWMidori::Logic::Logic() {}

CWMidori::Logic::~Logic() {}

bool CWMidori::Logic::isSquareDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_SQUARE);
}

bool CWMidori::Logic::isLTriggerDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_LTRIGGER);
}

bool CWMidori::Logic::isRTriggerDown(Inputs& inputs) {
    return inputs.isDown(PspCtrlButtons::PSP_CTRL_RTRIGGER);
}

bool CWMidori::Logic::isSquareUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_SQUARE);
}

bool CWMidori::Logic::isLTriggerUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_LTRIGGER);
}

bool CWMidori::Logic::isRTriggerUp(Inputs& inputs) {
    return inputs.isUp(PspCtrlButtons::PSP_CTRL_RTRIGGER);
}

bool CWMidori::Logic::isYAxisDown(Inputs& inputs) {
    return (0 > inputs.axisY()) & (inputs.axisY() > (-128 + 50));
}

bool CWMidori::Logic::isYAxisUp(Inputs& inputs) {
    return (inputs.axisY() > 0) || (inputs.axisY() < (-128 + 50));
}

void  CWMidori::Logic::setHold(const bool state) {
    holding = state;
}

void CWMidori::Logic::setPull(const bool state) {
    pulling = state;
}

void CWMidori::Logic::setMainHand(const bool state) {
    main_hand = state;
}

void CWMidori::Logic::addHands() {
    ++holding_hands;
}

void CWMidori::Logic::removeHands() {
    --holding_hands;
}

void CWMidori::Logic::onProcessing(CWMidori::Timer& timer) {
    if (holding & pulling) {
        timer.increaseTime(holding_hands);
    } else if (!holding) {
        timer.reduceTime();
    }
}

void CWMidori::Logic::onHold(Inputs& inputs) {
    if (isSquareDown(inputs)) {
        setMainHand(true);
        setHold(true);
        addHands();
    }
    if (main_hand) {
        if (isLTriggerDown(inputs)) {
            addHands();
        }
        if (isRTriggerDown(inputs)) {
            addHands();
        }
    }
}

void CWMidori::Logic::onPull(Inputs& inputs, CWMidori::Timer& timer) {
    if (holding & isYAxisDown(inputs)) {
        setPull(true);
    }
}

void CWMidori::Logic::onRelease(Inputs& inputs) {
    if (holding) {
        if (isSquareUp(inputs)) {
            removeHands();
            setMainHand(false);
            setHold(false);
            setPull(false);
        }
        if (main_hand) {
            if (isLTriggerUp(inputs)) {
                removeHands();
            }
            if (isRTriggerUp(inputs)) {
                removeHands();
            }
        }
    }
    if (pulling) {
        if (isYAxisUp(inputs)) {
            setPull(false);
        }
    }
}

int CWMidori::Logic::currentHands() {
    return holding_hands;
}

bool CWMidori::Logic::isHolding() {
    return holding;
}

bool CWMidori::Logic::isPulling() {
    return pulling;
}