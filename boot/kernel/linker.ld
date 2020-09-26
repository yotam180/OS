SECTIONS
{
    . = 1M;
    .text BLOCK(4K) : ALIGN(4K)
    {
        bin/KernelEntry.o(.text)
        bin/Kernel.o(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}
