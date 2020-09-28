#pragma once

#include "Ktype.hpp"
#include "arch/io/Ports.hpp"

namespace OS
{

typedef struct
{
    char Char;
    BYTE Color;
} COLORED_CHAR, *PCOLORED_CHAR;

using PVCOLORED_CHAR = volatile COLORED_CHAR *;

class TextDisplay final
{
public:
    explicit TextDisplay(const SIZE_T width, const SIZE_T height)
        : _Width(width), _Height(height), _Cursor(0)
    {
    }

    void Print(const char *const text);
    void PrintChar(const COLORED_CHAR c);

    inline void SetCusror(const UINT16 x, const UINT16 y);

    inline void PrintHex(const UINT32 number);
    static TextDisplay &GetDefault();

private:
    inline void PrintNewLine();
    inline void SetChar(const SIZE_T index, const COLORED_CHAR c);
    inline PVCOLORED_CHAR GetVideoBuffer() const;

private:
    SIZE_T _Width;
    SIZE_T _Height;

    SIZE_T _Cursor;
};

} // namespace OS

// Inlines
void OS::TextDisplay::SetCusror(const UINT16 x, const UINT16 y)
{
    constexpr static UINT16 SCREEN_CONTROL = 0x3d4, SCREEN_DATA = 0x3d5;
    constexpr static UINT8 CURSOR_HIGH_BYTE = 14, CURSOR_LOW_BYTE = 15;

    const UINT16HL cursor(static_cast<UINT16>(y * _Width + x));
    Arch::Io::PortByteOut(SCREEN_CONTROL, CURSOR_HIGH_BYTE);
    Arch::Io::PortByteOut(SCREEN_DATA, cursor.U8.High);
    Arch::Io::PortByteOut(SCREEN_CONTROL, CURSOR_LOW_BYTE);
    Arch::Io::PortByteOut(SCREEN_DATA, cursor.U8.Low);
}

OS::PVCOLORED_CHAR OS::TextDisplay::GetVideoBuffer() const
{
    return reinterpret_cast<PVCOLORED_CHAR>(reinterpret_cast<volatile void *>(0xb8000));
}

void OS::TextDisplay::SetChar(const SIZE_T index, const COLORED_CHAR c)
{
    GetVideoBuffer()[index].Char = c.Char; // TODO: Hack to not define vol-nonvol assignment operator. C++ sucks on this one :(
    GetVideoBuffer()[index].Color = c.Color;
}

void OS::TextDisplay::PrintHex(const UINT32 number)
{
    static const char *const digits = "0123456789abcdef";
    char buffer[] = "00000000";
    buffer[0] = digits[(number >> 28) & 0xf];
    buffer[1] = digits[(number >> 24) & 0xf];
    buffer[2] = digits[(number >> 20) & 0xf];
    buffer[3] = digits[(number >> 16) & 0xf];
    buffer[4] = digits[(number >> 12) & 0xf];
    buffer[5] = digits[(number >> 8) & 0xf];
    buffer[6] = digits[(number >> 4) & 0xf];
    buffer[7] = digits[number & 0xf];
    Print(buffer);
}

void OS::TextDisplay::PrintNewLine()
{
    // TODO: Implement
    _Cursor = 0;

    for (SIZE_T i = 0; i < _Height - 1; i++)
    {
        for (SIZE_T j = 0; j < _Width; j++)
        {
            GetVideoBuffer()[i * _Width + j].Char = GetVideoBuffer()[(i + 1) * _Width + j].Char;
            GetVideoBuffer()[i * _Width + j].Color = GetVideoBuffer()[(i + 1) * _Width + j].Color;
        }
    }

    for (SIZE_T j = 0; j < _Width; j++)
    {
        GetVideoBuffer()[(_Height - 1) * _Width + j].Char = ' ';
    }
}
