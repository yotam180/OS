#include "arch/Arch.hpp"

#include "arch/Interrupts.hpp"
#include "arch/Timer.hpp"
#include "arch/io/PIC.hpp"
#include "arch/io/Ports.hpp"

// TODO: Move this somewhere else?
static constexpr UINT16 DEFAULT_TIMER_FREQUENCY = 50;

void Arch::Setup()
{
    PopulateIDT();
    SetIDT();
    Io::RemapPIC(Io::DEFAULT_MASTER_INT_START, Io::DEFAULT_SLAVE_INT_START);
    Timer::Init(DEFAULT_TIMER_FREQUENCY);

    __asm__ __volatile__("sti"); // Enable interrupts
}
