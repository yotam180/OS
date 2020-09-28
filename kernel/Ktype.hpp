#pragma once

typedef unsigned char BYTE;
typedef signed char INT8;
typedef unsigned char UINT8;
typedef signed short INT16;
typedef unsigned short UINT16;
typedef signed int INT32;
typedef unsigned int UINT32;

// Access UINT16 low and high bytes. Basically type punning but it's legal (TODO: ?)
union UINT16HL {
    UINT16 U16;
    struct
    {
        UINT8 Low;
        UINT8 High;
    } U8;

public:
    explicit UINT16HL(const UINT16 u)
        : U16(u)
    {
    }

    explicit UINT16HL(const UINT8 high, const UINT8 low)
        : U8{low, high}
    {
    }
};

typedef void *PVOID;

using SIZE_T = unsigned int; // TODO: Hack. Figure if 32 or 64 bit

#define UNUSED(x) (void)(x)
