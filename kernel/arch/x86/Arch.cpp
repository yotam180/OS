#include "arch/Arch.hpp"

#include "arch/Interrupts.hpp"
#include "arch/Timer.hpp"
#include "arch/io/PIC.hpp"
#include "arch/io/Ports.hpp"

void Arch::Setup()
{
    PopulateIDT();
    SetIDT();
    Io::RemapPIC(Io::DEFAULT_MASTER_INT_START, Io::DEFAULT_SLAVE_INT_START);
    Timer::Init(); // TODO: Fill frequency as parameter

    __asm__ __volatile__("sti"); // Enable interrupts
}
