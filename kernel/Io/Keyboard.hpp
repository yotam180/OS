#pragma once

#include "Ktype.hpp"

namespace Io
{
using KEYPRESS_HANDLER = void (*)(char key);

class Keyboard final
{
public:
    static Keyboard &GetDefault();
    inline void SetHandler(KEYPRESS_HANDLER handler);

private:
    // Will only be triggered for key *down* events
    KEYPRESS_HANDLER _Handler;

private:
    explicit Keyboard();
    static void ArchKeypressHandler(const UINT8 scanCode);
};
} // namespace Io

void Io::Keyboard::SetHandler(Io::KEYPRESS_HANDLER handler)
{
    _Handler = handler;
}