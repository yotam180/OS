#include "Keyboard.hpp"

#include "TextMode/TextMode.hpp" // TODO: Remove
#include "arch/io/Keyboard.hpp"

// This conforms to the US English keyboard layout.
// TODO: Support more layouts? Or at least make the layout not hard coded.
static const char _Scancodes[] = {
    '\0',   // 0x0, Unknown
    '\x11', // 0x1, Escape
    '1',    // 0x2
    '2',    // 0x3
    '3',    // 0x4
    '4',    // 0x5
    '5',    // 0x6
    '6',    // 0x7
    '7',    // 0x8
    '8',    // 0x9
    '9',    // 0xa
    '0',    // 0xb
    '-',    // 0xc
    '=',    // 0xd
    '\x7f', // 0xe, Delete
    '\x09', // 0xf, Tab
    'q',    // 0x10
    'w',    // 0x11
    'e',    // 0x12
    'r',    // 0x13
    't',    // 0x14
    'y',    // 0x15
    'u',    // 0x16
    'i',    // 0x17
    'o',    // 0x18
    'p',    // 0x19
    '[',    // 0x1a
    ']',    // 0x1b
    '\0',   // 0x1c, Unknown
    '\0',   // 0x1d, Unknown
    'a',    // 0x1e
    's',    // 0x1f
    'd',    // 0x20
    'f',    // 0x21
    'g',    // 0x22
    'h',    // 0x23
    'j',    // 0x24
    'k',    // 0x25
    'l',    // 0x26
    ';',    // 0x27
    '\'',   // 0x28
};

Io::Keyboard::Keyboard()
{
    Arch::Io::Keyboard::Setup(ArchKeypressHandler); // TODO: Complete with function
}

Io::Keyboard &Io::Keyboard::GetDefault()
{
    static Keyboard k;
    return k;
}

void Io::Keyboard::ArchKeypressHandler(const UINT8 scanCode)
{
    constexpr static UINT8 KEY_UP = 0x80;
    if (scanCode & KEY_UP)
        return;

    if (!GetDefault()._Handler) // TODO: Log error here
        return;

    const UINT8 charCode = scanCode & static_cast<UINT8>(~KEY_UP);
    if (charCode > sizeof(_Scancodes) / sizeof(*_Scancodes)) // TODO: Log error here
        return;

    GetDefault()._Handler(_Scancodes[charCode]); // TODO: Handle special characters, keyboard modifiers
}
