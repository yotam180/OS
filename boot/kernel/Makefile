CC=g++
CFLAGS=-ffreestanding -std=c++17 -m32 -fno-pie -O2 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -Werror
FILES=Kernel.cpp
BIN_DIR=bin

# all:
# 	gcc -fno-pic -O2 -fno-exceptions -ffreestanding -c a.c -o a.o
# 	ld -o a.bin -Ttext 0x1000 a.o --oformat=binary

all: $(BIN_DIR)/Kernel.bin

$(BIN_DIR)/Kernel.bin: $(BIN_DIR)/KernelEntry.o $(BIN_DIR)/Kernel.o
	ld -T linker.ld -m elf_i386 -o $@ $^ --oformat binary

$(BIN_DIR)/KernelEntry.o: KernelEntry.S
	mkdir -p $(BIN_DIR)
	nasm $< -f elf -o $@

$(BIN_DIR)/Kernel.o: $(FILES)
	mkdir -p $(BIN_DIR)
	$(CC) -c $(CFLAGS) $(FILES) -o $@

clean:
	rm -rf ./bin/