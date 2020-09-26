CC=g++
CFLAGS=-ffreestanding -std=c++17 -m32 -fno-pie -O2 -fno-exceptions -fno-rtti -Wall -Wextra -pedantic
BIN_DIR=bin
FILES=$(shell find . -name "*.cpp" | tr '\n' ' ')
OBJECTS=$(FILES:%.cpp=$(BIN_DIR)/%.o) # Kernel.cpp -> bin/Kernel.o

# all:
# 	gcc -fno-pic -O2 -fno-exceptions -ffreestanding -c a.c -o a.o
# 	ld -o a.bin -Ttext 0x1000 a.o --oformat=binary

all: $(BIN_DIR)/Kernel.bin

$(BIN_DIR)/Kernel.bin: bin/KernelEntry.o $(OBJECTS)
	ld -T linker.ld -m elf_i386 -o $@ $^ --oformat binary

$(BIN_DIR)/KernelEntry.o: KernelEntry.S
	mkdir -p $(BIN_DIR)
	nasm $< -f elf -o $@

.SECONDEXPANSION:
$(BIN_DIR)/%.o: %.cpp $$(shell grep -oP "(?<=include \")([A-Za-z0-9_\.\/]+)(?=\")" `echo $$@ | sed s/bin\\\///g | sed s/\.o/\.cpp/g` | tr '\n' ' ')
	echo deps: $<
	mkdir -p $(shell dirname $@)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf ./bin/