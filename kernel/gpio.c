#include "gpio.h"
#include "io.h"

void gpio_set_function(unsigned int pin, unsigned int function) {
	if(pin <= 53) {
		unsigned int reg_val;
		unsigned int reg_no = pin / 10; /* 10 pins per function register */
		unsigned int offset = (pin % 10) * 3; /* 3 bits per function selector */
		unsigned int reg = GPFSEL0;
		reg += (reg_no*4);
		reg_val = load32(reg);
		reg_val &= ~(7<<offset);
		reg_val |= (function<<offset);
		store32(reg,reg_val);
   }
}


void gpio_set_output(unsigned int pin) {
	unsigned int reg_no = pin / 32; /* 32 pins per register */
	unsigned int offset = pin % 32;
	unsigned int reg = GPSET0;
	reg += (reg_no*4);
	store32(reg ,(1<<offset));
}

void gpio_clear_output(unsigned int pin) {
	unsigned int reg_no = pin / 32; /* 32 pins per register */
	unsigned int offset = pin % 32;
	unsigned int reg = GPCLR0;
	reg += (reg_no*4);
	store32(reg, (1<<offset));
}
