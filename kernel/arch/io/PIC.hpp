#pragma once

#include "Ktype.hpp"

namespace Io
{
void RemapPIC(const UINT16 masterOffset, const UINT16 slaveOffset);

static constexpr UINT16 DEFAULT_MASTER_INT_START = 32; // Map master IR0 to 'int $32'
static constexpr UINT16 DEFAULT_SLAVE_INT_START = 40;
} // namespace Io
