#include "arch/io/Ports.hpp"

// TODO: Find a way to inline these functions for performance enhancement
BYTE Arch::Io::PortByteIn(const UINT16 port)
{
    unsigned char result;
    __asm__ __volatile__(
        "in %%dx, %%al"
        : "=a"(result)
        : "d"(port));

    return result;
}

void Arch::Io::PortByteOut(const UINT16 port, const BYTE value)
{
    __asm__ __volatile__(
        "out %%al, %%dx" ::"a"(value), "d"(port));
}

UINT16 Arch::Io::PortWordIn(const UINT16 port)
{
    UINT16 result;
    __asm__ __volatile__(
        "in %%dx, %%ax"
        : "=a"(result)
        : "d"(port));
    return result;
}

void Arch::Io::PortWordOut(const UINT16 port, const UINT16 value)
{
    __asm__ __volatile__(
        "out %%ax, %%dx" ::"a"(value), "d"(port));
}
