PROJECT=kernel


INCLUDE_DIRS = -Iinclude -I../shared/include

TARGET_HEX=$(PROJECT).hex
TARGET_BIN=$(PROJECT).bin

CFLAGS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -Iinclude -g

OBJECTS=vectors.o io.o interrupt_wrapper.o gpio.o uart.o kernel.o kstdio.o klibc/stdlib.o klibc/string.o gcc/__aeabi_uidivmod.o gcc/__aeabi_uidiv.o gcc/__udivmodsi4.o

all:$(OBJECTS)


%.o : %.s
	@$(AS) $< -o $@

%.o : %.c
	@$(CC) $(INCLUDE_DIRS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
