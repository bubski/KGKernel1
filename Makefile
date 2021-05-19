ASM=nasm
CC=gcc
LD=ld

OBJS= \
	boot/boot.o \
	kernel/kernel.o

LIBS= \
	lib/libk.a

all: KGKernel1

KGKernel1: $(OBJS) $(LIBS)
	$(LD) -melf_i386 -Tlink.ld $(OBJS) -o KGKernel1 -Llib -lk

boot/boot.o: boot/boot.asm
	$(ASM) -f elf32 boot/boot.asm -o boot/boot.o

kernel/kernel.o: kernel/kernel.c
	$(CC) -m32 -nostdlib -nostdinc -fno-builtin -c kernel/kernel.c -o kernel/kernel.o -Iinclude

lib/libk.a:
	cd lib; make

clean:
	rm $(OBJS) $(LIBS)
	cd lib; make clean