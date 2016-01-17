#ifndef _INTERRUPTS_H
#define _INTERRUPTS_H

/* ARM Interrupt registers base */
#define INT_BASE 	0x2000B000

/* ARM Interrupt registers offset */
#define IRQ_BASIC_PENDING 	0x0200
#define IRQ_PENDING_1 		0x0204
#define IRQ_PENDING_2 		0x0208
#define FIQ_CONTROL 			0x020C
#define IRQ_ENABLE_1 		0x0210
#define IRQ_ENABLE_2 		0x0214
#define IRQ_BASIC_ENABLE 	0x0218
#define IRQ_DISABLE_1 		0x021C
#define IRQ_DISABLE_2 		0x0220
#define IRQ_BASIC_DISABLE 	0x0224

#endif /* _INTERRUPTS_H */
