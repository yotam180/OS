CC=g++
CFLAGS=-ffreestanding -m32 -fno-pie -O2
FILES=Kernel.cpp

# all:
# 	gcc -fno-pic -O2 -fno-exceptions -ffreestanding -c a.c -o a.o
# 	ld -o a.bin -Ttext 0x1000 a.o --oformat=binary

all: Kernel.bin

Kernel.bin: KernelEntry.o Kernel.o
	ld -T linker.ld -m elf_i386 -o $@ $^ --oformat binary

KernelEntry.o: KernelEntry.S
	nasm $< -f elf -o $@

Kernel.o: $(FILES)
	$(CC) -c $(CFLAGS) $(FILES) -o $@

clean:
	rm *.o *.bin