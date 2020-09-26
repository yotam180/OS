#include "TextMode.hpp"

OS::TextDisplay &OS::TextDisplay::GetDefault()
{
    static OS::TextDisplay t(80, 25); // TODO: Export to consts
    return t;
}