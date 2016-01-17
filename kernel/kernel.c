#include "uart.h"
#include "klog.h"
const char version[] = "Tacos-RPi 0.1 - "__DATE__" - "__TIME__;


int cmain() {
	uart_init();
	klog("%s", version);
	klog("Test!");
	kerr("Test error!");
	while(1) {

	}

	return 0;
}
