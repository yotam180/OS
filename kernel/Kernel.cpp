#include "Io/Keyboard.hpp"
#include "Ktype.hpp"
#include "TextMode/TextMode.hpp"
#include "arch/Arch.hpp"

/*
TODO: This kernel is currently embedded into the bootloader. This is not very good, but it
simplifies the kernel loading process (otherwise the bootloader 32 bit code should have had
drivers to read from the disk).

Next, we should really port the kernel to work with the multiboot standard, so it can be loaded
by a pre-made bootloader such as GRUB.
*/

static void KeInput(char character);

extern "C" void KeStart()
{
    Arch::Setup();
    Io::Keyboard::GetDefault().SetHandler(KeInput);

    while (1)
        ;
}

static void KeInput(char character)
{
    OS::TextDisplay::GetDefault().PrintChar(character);
}