all:
	make -C kernel
	nasm disk.S -o disk.bin

clean:
	make -C kernel clean
	rm -f *.bin
