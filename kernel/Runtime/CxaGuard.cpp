#include "Ktype.hpp"

// These are an own implementation for the functions required for local static members.
// TODO: Make these thread-safe
extern "C" int __cxa_guard_acquire(UINT32 *ptr)
{
    if (*ptr & 1)
    {
        return 0;
    }

    *ptr |= 1;
    return 1;
}

extern "C" void __cxa_guard_release(UINT32 *ptr)
{
    UNUSED(ptr);
}