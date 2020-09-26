#include "Ktype.hpp"
#include "TextMode/TextMode.hpp"
#include "arch/internal/IDT.hpp"

/*
TODO: This kernel is currently embedded into the bootloader. This is not very good, but it
simplifies the kernel loading process (otherwise the bootloader 32 bit code should have had
drivers to read from the disk).

Next, we should really port the kernel to work with the multiboot standard, so it can be loaded
by a pre-made bootloader such as GRUB.
*/

extern "C" void KeStart()
{
    Arch::PopulateIDT(); // TODO: Unify to one function Arch::init or something
    Arch::SetIDT();

    OS::TextDisplay::GetDefault().Print("Hello, world\nThis is a very important message\nFROM THE 32 BIT KERNEL!!!");

    __asm__ __volatile__("int $2");

    while (1)
        ;
}
