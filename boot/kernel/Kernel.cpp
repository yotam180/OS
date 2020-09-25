#include "Ktype.hpp"

typedef struct
{
    char Char;
    byte Color;
} VCHAR;

extern "C" void KeStart()
{
    volatile VCHAR *videoMemory = reinterpret_cast<VCHAR *>(0xb8000);
    videoMemory[0].Char = 'A';
    videoMemory[0].Color = 0xf;
}
