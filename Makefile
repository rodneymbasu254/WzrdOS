ARCH=arm-none-eabi
CFLAGS=-ffreestanding -nostdlib -Wall -Wextra

all: kernel.bin

boot.o: boot.s
	$(ARCH)-as boot.s -o boot.o

kernel.o: kernel.c
	$(ARCH)-gcc -c kernel.c -o kernel.o $(CFLAGS)

kernel.elf: boot.o kernel.o linker.ld
	$(ARCH)-ld -T linker.ld boot.o kernel.o -o kernel.elf

kernel.bin: kernel.elf
	$(ARCH)-objcopy -O binary kernel.elf kernel.bin

run: kernel.bin
	qemu-system-arm -M raspi2b -kernel kernel.bin -serial stdio

clean:
	rm -f *.o *.elf *.bin
