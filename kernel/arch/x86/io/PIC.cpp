#include "arch/io/PIC.hpp"

#include "arch/io/Ports.hpp"

namespace Io
{
static constexpr UINT16 MASTER_COMMAND = 0x20;
static constexpr UINT16 MASTER_DATA = 0x21;
static constexpr UINT16 SLAVE_COMMAND = 0xa0;
static constexpr UINT16 SLAVE_DATA = 0xa1;
} // namespace Io

void Io::RemapPIC(const UINT16 masterOffset, const UINT16 slaveOffset)
{
    PortByteOut(MASTER_COMMAND, 0x11); // TODO: What is 0x11?
    PortByteOut(SLAVE_COMMAND, 0x11);

    PortByteOut(MASTER_DATA, masterOffset);
    PortByteOut(SLAVE_DATA, slaveOffset);

    PortByteOut(MASTER_DATA, 4); // ?
    PortByteOut(SLAVE_DATA, 2);
    PortByteOut(MASTER_DATA, 1);
    PortByteOut(SLAVE_DATA, 1);
    PortByteOut(MASTER_DATA, 0);
    PortByteOut(SLAVE_DATA, 0);
}