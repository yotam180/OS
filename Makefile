.PHONY: debug

all:
	make -C kernel
	make -C boot

debug:
	make -C kernel debug
	make -C boot
	qemu-system-i386 -s -S boot/disk.bin &
	gdb -ex "target remote localhost:1234" -ex "symbol-file kernel/bin/Kernel.elf"

clean:
	make -C kernel clean
	make -C boot clean
