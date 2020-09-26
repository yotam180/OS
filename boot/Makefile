all:
	nasm sector0/sector0.S -o sector0.bin
	make -C kernel
	cat sector0.bin kernel/bin/Kernel.bin > disk.bin

clean:
	make -C kernel clean
	rm -f *.bin
