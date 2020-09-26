#pragma once
#include "../Ktype.hpp"

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

    inline void Print(const char *const text);
    inline void PrintChar(const COLORED_CHAR c);

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
OS::PVCOLORED_CHAR OS::TextDisplay::GetVideoBuffer() const
{
    return reinterpret_cast<PVCOLORED_CHAR>(reinterpret_cast<volatile void *>(0xb8000));
}

void OS::TextDisplay::SetChar(const SIZE_T index, const COLORED_CHAR c)
{
    GetVideoBuffer()[index].Char = c.Char; // TODO: Hack to not define vol-nonvol assignment operator. C++ sucks on this one :(
    GetVideoBuffer()[index].Color = c.Color;
}

void OS::TextDisplay::Print(const char *const text)
{
    for (const char *ptr = text; *ptr != '\0'; ++ptr)
    {
        PrintChar({*ptr, 0x02}); // Black on White
    }
}

void OS::TextDisplay::PrintChar(const COLORED_CHAR c)
{
    if (c.Char == '\n')
    {
        PrintNewLine();
        return;
    }

    if (_Cursor == _Width - 1)
    {
        PrintNewLine();
    }

    GetVideoBuffer()[(_Height - 1) * _Width + _Cursor].Char = c.Char; // Note: Ugly
    GetVideoBuffer()[(_Height - 1) * _Width + _Cursor].Color = c.Color;
    _Cursor++;
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