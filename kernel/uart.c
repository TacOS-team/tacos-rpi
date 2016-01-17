#include "gpio.h"
#include "uart.h" 
#include "io.h"
#include <stdint.h>

extern void dummy();

void uart_init() {
   uint32_t tmp;
   
	store32(UART0_CR, 0); /* Disables UART0 */

   store32(GPPUD, 0); /* Clear GPIO pins */ 
   for(tmp=0; tmp<150; tmp++) dummy(); /* Wait 150 cycles */

   store32(GPPUDCLK0, (1<<14) | (1<<15));
   for(tmp=0; tmp<150; tmp++) dummy(); /* Wait 150 cycles */

	store32(UART0_ICR, 0x07FF);
	
	/* 115200 Bauds */
   store32(UART0_IBRD, 1);
   store32(UART0_FBRD, 40);

	/* 8bit, stop, no parity */
   store32(UART0_LCRH, (1<<4) | (1<<5) | (1<<6));

	/* Mask interrupts */
	store32(UART0_IMSC, (1<<1) | (1<<4) | (1<<5) | (1<<6) |
							  (1<<7) | (1<<8) | (1<<9) | (1<<10));

	/* Finally enable the UART0 */
   store32(UART0_CR, (1<<0) | (1<<8) | (1<<9));
}

void uart_putc(const char c) {
	while(load32(UART0_FR) & (1<<5)) {}
	store32(UART0_DR, c);
}

void uart_puts(const char* s) {
	char* p = (char*) s;
   while(*p != 0) {
		uart_putc(*p);
		p++;
	}
}
