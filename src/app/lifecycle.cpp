#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include "include/app/lifecycle.hpp"

bool LifecycleManager::initialized;
Inputs LifecycleManager::inputs;

CWMidori::Timer LifecycleManager::timer;
CWMidori::Logic LifecycleManager::logic;

LifecycleManager::LifecycleManager() {
    LifecycleManager::initialized = false;
}

LifecycleManager::~LifecycleManager() {
}

void LifecycleManager::init() {
    if (!LifecycleManager::initialized) {
        LifecycleManager::initialized = true;
        LifecycleManager::timer.init();
        pspDebugScreenPrintf("clockwork midori\n");
    }
}

void LifecycleManager::callStart() {
}

void LifecycleManager::callInput() {
    inputs.peekBuffer(1);
    inputs.readLatch();
}

void LifecycleManager::callUpdate() {
    timer.fetchDeviceTime();
    logic.onRelease(inputs, timer);
    logic.onPull(inputs, timer);
    logic.onHold(inputs, timer);
    logic.onProcessing(timer);
}

void LifecycleManager::callRender() {
    sceDisplayWaitVblankStart(); // wait for vblank
    pspDebugScreenSetXY(0, 1); // reset where we draw
}

void LifecycleManager::callGUI() {
    pspDebugScreenPrintf("FreeMem in KiB: %dKiB\n", sceKernelTotalFreeMemSize()/1024);
    pspDebugScreenPrintf("FreeMem in MiB: %dMiB\n", sceKernelTotalFreeMemSize()/(1024*1024));
    pspDebugScreenPrintf("Analog X = %d\n", inputs.axisX()); 
    pspDebugScreenPrintf("Analog Y = %d\n", inputs.axisY());
    pspDebugScreenPrintf("button = %d\n", inputs.unsafePressedButton());
    pspDebugScreenPrintf("holding = %d\n", logic.isHolding());
    pspDebugScreenPrintf("pulling = %d\n", logic.isPulling());
    pspDebugScreenPrintf("hands = %d\n", logic.currentHands());
    pspDebugScreenPrintf("timer = %ld\n", timer.currentTimeLeft());
}