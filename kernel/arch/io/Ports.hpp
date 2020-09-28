#pragma once

#include "Ktype.hpp"

namespace Io
{
BYTE PortByteIn(const UINT16 port);
void PortByteOut(const UINT16 port, const BYTE value);
UINT16 PortWordIn(const UINT16 port);
void PortWordOut(const UINT16 port, const UINT16 value);
} // namespace Io
