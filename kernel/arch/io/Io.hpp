#pragma once

#include "Ktype.hpp"

BYTE IoPortByteIn(const UINT16 port);
void IoPortByteOut(const UINT16 port, const BYTE value);
UINT16 IoPortWordIn(const UINT16 port);
void IoPortWordOut(const UINT16 port, const UINT16 value);
