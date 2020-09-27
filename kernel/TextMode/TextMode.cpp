#include "TextMode.hpp"

OS::TextDisplay &OS::TextDisplay::GetDefault()
{
    static OS::TextDisplay t(80, 25); // TODO: Export to consts
    return t;
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