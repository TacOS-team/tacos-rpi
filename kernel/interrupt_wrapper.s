.globl enable_irq
enable_irq:
	mrs r0, cpsr
	bic r0, r0, #0x80
	msr cpsr_c, r0
	bx lr


.globl irq_wrapper
irq_wrapper:
	push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
;@	bl c_irq_wrapper
	pop {r0, r1, r2, r3, r4, r5, r7, r8, r9, r10, r11, r12, lr}
	subs pc, lr, #4
