#pragma once

#include "Ktype.hpp"

byte IoPortByteIn(const uint16_t port);
void IoPortByteOut(const uint16_t port, const byte value);
uint16_t IoPortWordIn(const uint16_t port);
void IoPortWordOut(const uint16_t port, const uint16_t value);
