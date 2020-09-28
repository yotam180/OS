#pragma once

#include "Ktype.hpp"

namespace Arch::Io::Keyboard
{
using KEYPRESS_HANDLER = void (*)(UINT8 scanCode);

void Setup(KEYPRESS_HANDLER handler);
} // namespace Arch::Io::Keyboard