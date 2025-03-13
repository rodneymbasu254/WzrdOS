# Makefile for ARM bare-metal OS

CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-Wall -O0 -nostdlib -nostartfiles -ffreestanding
LDFLAGS=-T linker.ld

all: kernel.img

boot.o: boot.s
	$(AS) -o $@ $<

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c -o $@ $<

kernel.elf: boot.o kernel.o linker.ld
	$(LD) $(LDFLAGS) -o $@ boot.o kernel.o

kernel.img: kernel.elf
	$(OBJCOPY) -O binary $< $@

run: kernel.img
	qemu-system-arm -M versatilepb -nographic -kernel kernel.img

clean:
	rm -f *.o *.elf *.img
