#include <pspkernel.h>
#include "include/common/kernel_callback.hpp"
#include "include/app/lifecycle.hpp"

/* Define the module info section */
PSP_MODULE_INFO("ClockworkMidori", 0, 1, 0);
/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_MAX();

extern "C" int main(int argc, char* args[]) {
	setupExitCallback();
	pspDebugScreenInit();

	LifecycleManager lifecycleManager;
	lifecycleManager.init();

	while(isRunning()) {
        // lifecycleManager.callAwake();
        lifecycleManager.callStart();
        lifecycleManager.callInput();
        lifecycleManager.callUpdate();
        lifecycleManager.callRender();
        lifecycleManager.callGUI();
        // lifecycleManager.callPause();
        // lifecycleManager.callDisable();
        // lifecycleManager.callDestroy();
	}

	sceKernelExitGame();	
	return 0;
}