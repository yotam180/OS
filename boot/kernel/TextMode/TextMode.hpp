#pragma once
#include "../Ktype.hpp"

#define TEXT_BUFFER_ADDR (0xb8000)

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
private:
};
} // namespace OS
