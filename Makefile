all:
	make -C kernel
	make -C boot

clean:
	make -C boot clean
	make -C kernel clean
