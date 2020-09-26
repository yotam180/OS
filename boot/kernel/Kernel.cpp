#include "Ktype.hpp"

/*
TODO: This kernel is currently embedded into the bootloader. This is not very good, but it
simplifies the kernel loading process (otherwise the bootloader 32 bit code should have had
drivers to read from the disk).

Next, we should really port the kernel to work with the multiboot standard, so it can be loaded
by a pre-made bootloader such as GRUB.
*/

extern "C" void KeStart()
{
    volatile VCHAR *videoMemory = reinterpret_cast<VCHAR *>(0xb8000);
    videoMemory[0].Char = 'A';
    videoMemory[0].Color = 0xf;
}
