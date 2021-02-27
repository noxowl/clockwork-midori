#ifndef CWMIDORI_COMMON_KERNEL_CALLBACK_H_
#define CWMIDORI_COMMON_KERNEL_CALLBACK_H_

#include <pspkernel.h>

extern "C" { 
    int isRunning();
    int setupExitCallback();
}

#endif