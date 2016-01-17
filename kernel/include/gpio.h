#ifndef _GPIO_H
#define _GPIO_H

/* GPIO Function Select Registers */
#define GPFSEL0 	0x20200000
#define GPFSEL1 	0x20200004
#define GPFSEL2 	0x20200008
#define GPFSEL3 	0x2020000C
#define GPFSEL4 	0x20200010
#define GPFSEL5 	0x20200014

/* GPIO Pin Output Set Registers */
#define GPSET0 	0x2020001C
#define GPSET1 	0x20200020

/* GPIO Pin Output Clear Registers */
#define GPCLR0 	0x20200028
#define GPCLR1 	0x2020002C

/* GPIO Pin Level Registers */
#define GPLEV0 	0x20200034
#define GPLEV1 	0x20200038

/* GPIO Pin Event Detect Status Registers */
#define GPEDS0 	0x20200040
#define GPEDS1 	0x20200044

/* GPIO Pin Rising Edge Detect Enable Registers */
#define GPREN0 	0x2020004C
#define GPREN1 	0x20200050

/* GPIO Pin Falling Edge Detect Enable Registers */
#define GPFEN0 	0x20200058
#define GPFEN1 	0x2020005C

/* GPIO Pin High Detect Enable Registers */
#define GPHEN0 	0x20200064
#define GPHEN1 	0x20200068

/* GPIO Pin Low Detect Enable Registers */
#define GPLEN0 	0x20200070
#define GPLEN1 	0x20200074

/* GPIO Pin Async Rising Edge Detect Registers */
#define GPAREN0 	0x2020007C
#define GPAREN1 	0x20200080

/* GPIO Pin Async Falling Edge Detect Registers */
#define GPAFEN0 	0x20200088
#define GPAFEN1 	0x2020008C

/* GPIO Pin Pull-up/down Enable Registers */
#define GPPUD 		0x20200094

/* GPIO Pin Pull-up/down Enable Clock Registers */
#define GPPUDCLK0 0x20200098
#define GPPUDCLK1 0x2020009C

/* GPIO Test Register */
#define GPTST 		0x202000B0

/* GPIO Function */
#define GPF_INPUT 	0
#define GPF_OUTPUT 	1
#define GPF_ALT0 		4
#define GPF_ALT1 		5
#define GPF_ALT2 		6
#define GPF_ALT3 		7
#define GPF_ALT4 		3
#define GPF_ALT5 		2

void gpio_set_function(unsigned int pin, unsigned int function);

void gpio_set_output(unsigned int pin);
void gpio_clear_output(unsigned int pin);

#endif /* _GPIO_H */
