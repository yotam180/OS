SECTIONS
{
    . = 1M;
    .text 0x9000 : ALIGN(1K)
    {
        bin/*(.text)
    }

    .rodata BLOCK(1K) : ALIGN(1K)
    {
        *(.rodata)
    }

    .data BLOCK(1K) : ALIGN(1K)
    {
        *(.data)
    }

    .bss BLOCK(1K) : ALIGN(1K)
    {
        *(COMMON)
        *(.bss)
    }
}
