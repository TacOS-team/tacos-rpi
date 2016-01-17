/* Safe interfaces for peripheral regs I/O */

.globl store32
store32:
	str r1, [r0]
	bx lr

.globl load32
load32:
	ldr r0, [r0]
	bx lr

