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
    inline void SetChar(const size_t index, const ColoredChar c);
    inline volatile ColoredChar *GetVideoBuffer() const;
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
