#pragma once
#include "../Ktype.hpp"

struct ColoredChar
{
    char Char;
    byte Color;
};

namespace OS
{
class TextDisplay final
{
public:
    inline void set_char(const size_t index, const ColoredChar c);

private:
    static volatile ColoredChar *const TEXT_BUFFER_ADDR; // TODO: Make sure this doesn't cause double de-reference
};
} // namespace OS

// Inlines
inline void OS::TextDisplay::set_char(const size_t index, const ColoredChar c)
{
    TEXT_BUFFER_ADDR[index].Char = c.Char; // TODO: Hack to not define vol-nonvol assignment operator. C++ sucks on this one :(
    TEXT_BUFFER_ADDR[index].Color = c.Color;
}