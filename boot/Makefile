all:
	nasm sector0/sector0.S -o sector0.bin
	nasm post_bios/boot.S -o post_bios.bin
	cat sector0.bin post_bios.bin > disk.bin

clean:
	rm *.bin
