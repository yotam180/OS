#include "arch/io/Keyboard.hpp"

#include "TextMode/TextMode.hpp"
#include "arch/Interrupts.hpp"
#include "arch/io/Ports.hpp"

namespace Arch::Io::Keyboard
{
static void OnKeyboardInterrupt(const Arch::INTERRUPT_STATE *const state);
}

void Arch::Io::Keyboard::Setup()
{
    constexpr static SIZE_T KEYBOARD_INTERRUPT = 33;
    RegisterInterruptHandler(KEYBOARD_INTERRUPT, OnKeyboardInterrupt);
}

void Arch::Io::Keyboard::OnKeyboardInterrupt(const Arch::INTERRUPT_STATE *const state)
{
    UNUSED(state);
    
    constexpr static UINT16 SCANCODE_QUERY_PORT = 0x60;
    const UINT8 scanCode = PortByteIn(SCANCODE_QUERY_PORT);

    OS::TextDisplay::GetDefault().Print("Keyboard event ");
    OS::TextDisplay::GetDefault().PrintHex(scanCode);
    OS::TextDisplay::GetDefault().Print("\n");
}