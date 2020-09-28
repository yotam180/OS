#include "arch/io/Keyboard.hpp"

#include "TextMode/TextMode.hpp"
#include "arch/Interrupts.hpp"
#include "arch/io/Ports.hpp"

namespace Arch::Io::Keyboard
{
static void OnKeyboardInterrupt(const Arch::INTERRUPT_STATE *const state);

static KEYPRESS_HANDLER _KeypressHandler;
} // namespace Arch::Io::Keyboard

void Arch::Io::Keyboard::Setup(KEYPRESS_HANDLER handler)
{
    constexpr static SIZE_T KEYBOARD_INTERRUPT = 33;
    _KeypressHandler = handler;
    RegisterInterruptHandler(KEYBOARD_INTERRUPT, OnKeyboardInterrupt);
}

void Arch::Io::Keyboard::OnKeyboardInterrupt(const Arch::INTERRUPT_STATE *const state)
{
    UNUSED(state);

    constexpr static UINT16 SCANCODE_QUERY_PORT = 0x60;
    const UINT8 scanCode = PortByteIn(SCANCODE_QUERY_PORT);

    if (_KeypressHandler)
    {
        _KeypressHandler(scanCode);
    }
}
