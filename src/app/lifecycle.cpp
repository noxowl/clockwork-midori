#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include "include/app/lifecycle.hpp"

bool LifecycleManager::initialized;
Inputs LifecycleManager::inputs;

CWMidori::Timer LifecycleManager::midori_timer;

LifecycleManager::LifecycleManager() {
    LifecycleManager::initialized = false;
}

LifecycleManager::~LifecycleManager() {
}

void LifecycleManager::init() {
    if (!LifecycleManager::initialized) {
        LifecycleManager::initialized = true;
        LifecycleManager::midori_timer.init(500);
        pspDebugScreenPrintf("clockwork midori\n");
    }
    
}

void LifecycleManager::callStart() {
}

void LifecycleManager::callInput() {
    inputs.peekBuffer(1);
}

void LifecycleManager::callUpdate() {
    midori_timer.reduceTime();
}

void LifecycleManager::callRender() {
    sceDisplayWaitVblankStart(); // wait for vblank
    pspDebugScreenSetXY(0, 1); // reset where we draw
}

void LifecycleManager::callGUI() {
    pspDebugScreenPrintf("FreeMem in KiB: %dKiB\n", sceKernelTotalFreeMemSize()/1024);
        // pspDebugScreenPrintf("FreeMem in MiB: %dMiB\n", sceKernelTotalFreeMemSize()/(1024*1024));
    pspDebugScreenPrintf("Analog X = %d\n", inputs.axisX()); 
    pspDebugScreenPrintf("Analog Y = %d\n", inputs.axisY());
    pspDebugScreenPrintf("button = %d\n", inputs.button());
    pspDebugScreenPrintf("timer = %ld\n", midori_timer.currentTimeLeft());
}