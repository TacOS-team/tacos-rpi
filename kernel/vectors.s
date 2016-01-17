.section _kernel

.globl _start
_start:
	mov sp,#0x8000
	bl cmain

.globl dummy
dummy:
	bx lr
