#include "Ktype.hpp"
#include "TextMode/TextMode.hpp"

/*
TODO: This kernel is currently embedded into the bootloader. This is not very good, but it
simplifies the kernel loading process (otherwise the bootloader 32 bit code should have had
drivers to read from the disk).

Next, we should really port the kernel to work with the multiboot standard, so it can be loaded
by a pre-made bootloader such as GRUB.
*/

volatile char g_char = 'A';
volatile char *x;

extern "C" void KeStart()
{
    x = reinterpret_cast<volatile char *>(&KeStart);
    volatile ColoredChar *videoMemory = reinterpret_cast<ColoredChar *>(0xb8000);
    videoMemory[0].Char = g_char;
    videoMemory[0].Color = 0xf;
}
