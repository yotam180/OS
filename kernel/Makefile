CC=g++
CFLAGS=-g -ffreestanding -std=c++17 -m32 -fno-pie -O2 -fno-exceptions -fno-rtti -Wall -Wextra -Werror -pedantic -I./
BIN_DIR=bin
FILES=$(shell find . -name "*.cpp" | tr '\n' ' ')
OBJECTS=$(FILES:%.cpp=$(BIN_DIR)/%.o) # Kernel.cpp -> bin/Kernel.o
ASSEMBLY_COMPILED_OBJECTS=bin/KernelEntry.o bin/InterruptHandler.o
ARCH=x86

all: $(BIN_DIR)/Kernel.bin

$(BIN_DIR)/Kernel.bin: $(ASSEMBLY_COMPILED_OBJECTS) $(OBJECTS)
	ld -T linker.ld -m elf_i386 -o $@ $^ --oformat binary

$(BIN_DIR)/Kernel.elf: $(ASSEMBLY_COMPILED_OBJECTS) $(OBJECTS)
	ld -T linker.ld -m elf_i386 -o $@ $^

$(BIN_DIR)/KernelEntry.o: arch/$(ARCH)/KernelEntry.S
	mkdir -p $(BIN_DIR)
	nasm $< -f elf -o $@

$(BIN_DIR)/InterruptHandler.o: arch/$(ARCH)/InterruptHandler.S # TODO: Find a better way to compile all assembly files
	mkdir -p $(BIN_DIR)
	nasm $< -f elf -o $@

$(BIN_DIR)/%.o: %.cpp
	mkdir -p $(shell dirname $@)
	$(CC) -c $(CFLAGS) $< -o $@

debug: $(BIN_DIR)/Kernel.bin $(BIN_DIR)/Kernel.elf

clean:
	rm -rf ./bin/