#pragma once

#include "Ktype.hpp"

namespace Arch::Io
{
void RemapPIC(const UINT16 masterOffset, const UINT16 slaveOffset);
void ClearMasterPIC();
void ClearSlavePIC();

// Note: Code is written under the assumption that those two are linear (slave = master + 8)
// Do not break this assumption.
static constexpr UINT16 DEFAULT_MASTER_INT_START = 32; // Map master IR0 to 'int $32'
static constexpr UINT16 DEFAULT_SLAVE_INT_START = 40;
} // namespace Arch::Io
