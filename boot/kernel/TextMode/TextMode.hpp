#pragma once
#include "../Ktype.hpp"

namespace OS
{

struct ColoredChar
{
    char Char;
    byte Color;
};

class TextDisplay final
{
public:
    explicit TextDisplay(const size_t width, const size_t height)
        : _Width(width), _Height(height), _Cursor(0)
    {
    }

    inline void Print(const char *const text);
    inline void PrintChar(const ColoredChar c);

private:
    inline void PrintNewLine();
    inline void SetChar(const size_t index, const ColoredChar c);
    inline volatile ColoredChar *GetVideoBuffer() const;

private:
    size_t _Width;
    size_t _Height;

    size_t _Cursor;
};

} // namespace OS

// Inlines
volatile OS::ColoredChar *OS::TextDisplay::GetVideoBuffer() const
{
    return reinterpret_cast<volatile ColoredChar *>(reinterpret_cast<volatile void *>(0xb8000));
}

void OS::TextDisplay::SetChar(const size_t index, const ColoredChar c)
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

void OS::TextDisplay::PrintChar(const ColoredChar c)
{
    if (c.Char == '\n' || _Cursor == _Width - 1)
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

    for (size_t i = 0; i < _Height - 1; i++)
    {
        for (size_t j = 0; j < _Width; j++)
        {
            GetVideoBuffer()[i * _Width + j].Char = GetVideoBuffer()[(i + 1) * _Width + j].Char;
            GetVideoBuffer()[i * _Width + j].Color = GetVideoBuffer()[(i + 1) * _Width + j].Color;
        }
    }

    for (size_t j = 0; j < _Width; j++)
    {
        GetVideoBuffer()[(_Height - 1) * _Width + j].Char = ' ';
    }
}