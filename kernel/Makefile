CC=g++
CFLAGS=-ffreestanding -std=c++17 -m32 -fno-pie -O2 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic -I./
BIN_DIR=bin
FILES=$(shell find . -name "*.cpp" | tr '\n' ' ')
OBJECTS=$(FILES:%.cpp=$(BIN_DIR)/%.o) # Kernel.cpp -> bin/Kernel.o
ARCH=x86

all: $(BIN_DIR)/Kernel.bin

$(BIN_DIR)/Kernel.bin: bin/KernelEntry.o $(OBJECTS)
	ld -T linker.ld -m elf_i386 -o $@ $^ --oformat binary

$(BIN_DIR)/KernelEntry.o: arch/$(ARCH)/KernelEntry.S
	mkdir -p $(BIN_DIR)
	nasm $< -f elf -o $@

$(BIN_DIR)/%.o: %.cpp
	echo deps: $<
	mkdir -p $(shell dirname $@)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf ./bin/