export GCC_PREFIX ?= /usr/bin/arm-none-eabi-
export CC=@printf "\033[34m   CC   $$@\033[0m\n" && $(GCC_PREFIX)gcc
export LD=printf "\033[31m   LD   $$@\033[0m\n" && $(GCC_PREFIX)ld
export AS=@printf "\033[34m   AS   $$@\033[0m\n" && $(GCC_PREFIX)as
export OBJCOPY=$(GCC_PREFIX)objcopy

all: kernel.elf
SUBDIRS = kernel
kernel.elf: force_look
	@for i in $(SUBDIRS); do \
		printf "\033[1m>>> [$$i]\033[0m\n"; \
		$(MAKE) -s -C $$i; \
		if [ $$? = 0 ]; then printf "\033[1m<<< [$$i] [OK]\033[0m\n"; else printf "\033[31m\033[1m<<< [$$i] [FAIL]\033[0m\n"; exit 1; fi; \
	done
	@$(LD) -T linker.ld -o kernel.elf kernel/*.o kernel/klibc/*.o kernel/gcc/*.o 

force_look:
	@true

%.elf : $(OBJECTS)
	@echo "   LD   $@"
	@$(LD) $(OBJECTS) -o $@ -T linker.ld

%.bin : %.elf
	@echo "   OBJCOPY   $@"
	@$(OBJCOPY) $< -O binary $@

%.hex : %.elf
	@echo "   OBJCOPY   $@"
	@$(OBJCOPY) $< -O ihex $@

clean:
	@for i in $(SUBDIRS); do \
		printf "\033[1m>>> [$$i]\033[0m\n"; \
		$(MAKE) -s -C $$i clean; \
		printf "\033[1m<<< [$$i]\033[0m\n"; \
	done
	@rm -f *.o *.bin *.img
	@rm -f lib/*
	@rm -f bin/*
	@find . -name "*.o" -exec rm {} \;

.PRECIOUS: %.elf

runqemugdb: all
	~/local/qemu-rpi/bin/qemu-system-arm -kernel kernel.elf -cpu arm1176 -m 256 -M raspi -serial stdio -s -S

runqemu: all
	~/local/qemu-rpi/bin/qemu-system-arm -kernel kernel.elf -cpu arm1176 -m 256 -M raspi -serial stdio
