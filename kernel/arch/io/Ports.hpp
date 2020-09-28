#pragma once

#include "Ktype.hpp"

namespace Io
{
BYTE PortByteIn(const UINT16 port);
void PortByteOut(const UINT16 port, const BYTE value);
UINT16 PortWordIn(const UINT16 port);
void PortWordOut(const UINT16 port, const UINT16 value);
} // namespace Io

unsigned char port_byte_in(unsigned short port);
void port_byte_out(unsigned short port, unsigned char data);
unsigned short port_word_in(unsigned short port);
void port_word_out(unsigned short port, unsigned short data);