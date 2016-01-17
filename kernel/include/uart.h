#ifndef _UART_H
#define _UART_H

#define UART0_BASE 	0x20201000

/* Data registers */
#define UART0_DR 		(UART0_BASE + 0x0)
#define UART0_RSRECR (UART0_BASE + 0x4)

/* Configuration registers */ 
#define UART0_FR 		(UART0_BASE + 0x18)
#define UART0_ILPR 	(UART0_BASE + 0x20)
#define UART0_IBRD 	(UART0_BASE + 0x24)
#define UART0_FBRD 	(UART0_BASE + 0x28)
#define UART0_LCRH 	(UART0_BASE + 0x2c)
#define UART0_CR 		(UART0_BASE + 0x30)

/* Interrupt registers */
#define UART0_IFLS 	(UART0_BASE + 0x34)
#define UART0_IMSC 	(UART0_BASE + 0x38)
#define UART0_RIS 	(UART0_BASE + 0x3c)
#define UART0_MIS 	(UART0_BASE + 0x40)
#define UART0_ICR 	(UART0_BASE + 0x44)

/* DMA register */
#define UART0_DMACR 	(UART0_BASE + 0x48)

/* Test register */
#define UART0_ITCR 	(UART0_BASE + 0x80)
#define UART0_ITIP 	(UART0_BASE + 0x84)
#define UART0_ITOP 	(UART0_BASE + 0x88)
#define UART0_TDR 	(UART0_BASE + 0x8c)

void uart_init();
void uart_putc(const char c);
void uart_puts(const char* s);

#endif /* _UART_H */
