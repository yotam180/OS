#include "arch/io/Io.hpp"

BYTE IoPortByteIn(const UINT16 port)
{
    unsigned char result;
    __asm__(
        "in %%dx, %%al"
        : "=a"(result)
        : "d"(port));

    return result;
}

void IoPortByteOut(const UINT16 port, const BYTE value)
{
    __asm__(
        "out %%al, %%dx" ::"a"(value), "d"(port));
}

UINT16 IoPortWordIn(const UINT16 port)
{
    UINT16 result;
    __asm__(
        "in %%dx, %%ax"
        : "=a"(result)
        : "d"(port));
    return result;
}

void IoPortWordOut(const UINT16 port, const UINT16 value)
{
    __asm__(
        "out %%ax, %%dx" ::"a"(value), "d"(port));
}
