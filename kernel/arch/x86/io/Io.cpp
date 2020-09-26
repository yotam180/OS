#include "arch/io/Io.hpp"

byte IoPortByteIn(const uint16_t port)
{
    unsigned char result;
    __asm__(
        "in %%dx, %%al"
        : "=a"(result)
        : "d"(port));

    return result;
}

void IoPortByteOut(const uint16_t port, const byte value)
{
    __asm__(
        "out %%al, %%dx" ::"a"(value), "d"(port));
}

uint16_t IoPortWordIn(const uint16_t port)
{
    uint16_t result;
    __asm__(
        "in %%dx, %%ax"
        : "=a"(result)
        : "d"(port));
    return result;
}

void IoPortWordOut(const uint16_t port, const uint16_t value)
{
    __asm__(
        "out %%ax, %%dx" ::"a"(value), "d"(port));
}
