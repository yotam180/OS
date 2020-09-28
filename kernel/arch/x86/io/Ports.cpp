#include "arch/io/Ports.hpp"

// TODO: Find a way to inline these functions for performance enhancement
BYTE Io::PortByteIn(const UINT16 port)
{
    unsigned char result;
    __asm__ __volatile__(
        "in %%dx, %%al"
        : "=a"(result)
        : "d"(port));

    return result;
}

void Io::PortByteOut(const UINT16 port, const BYTE value)
{
    __asm__ __volatile__(
        "out %%al, %%dx" ::"a"(value), "d"(port));
}

UINT16 Io::PortWordIn(const UINT16 port)
{
    UINT16 result;
    __asm__ __volatile__(
        "in %%dx, %%ax"
        : "=a"(result)
        : "d"(port));
    return result;
}

void Io::PortWordOut(const UINT16 port, const UINT16 value)
{
    __asm__ __volatile__(
        "out %%ax, %%dx" ::"a"(value), "d"(port));
}

unsigned char port_byte_in(unsigned short port)
{
    unsigned char result;
    /* Inline assembler syntax
     * !! Notice how the source and destination registers are switched from NASM !!
     *
     * '"=a" (result)'; set '=' the C variable '(result)' to the value of register e'a'x
     * '"d" (port)': map the C variable '(port)' into e'd'x register
     *
     * Inputs and outputs are separated by colons
     */
    __asm__("in %%dx, %%al"
            : "=a"(result)
            : "d"(port));
    return result;
}

void port_byte_out(unsigned short port, unsigned char data)
{
    /* Notice how here both registers are mapped to C variables and
     * nothing is returned, thus, no equals '=' in the asm syntax 
     * However we see a comma since there are two variables in the input area
     * and none in the 'return' area
     */
    __asm__("out %%al, %%dx"
            :
            : "a"(data), "d"(port));
}

unsigned short port_word_in(unsigned short port)
{
    unsigned short result;
    __asm__("in %%dx, %%ax"
            : "=a"(result)
            : "d"(port));
    return result;
}

void port_word_out(unsigned short port, unsigned short data)
{
    __asm__("out %%ax, %%dx"
            :
            : "a"(data), "d"(port));
}