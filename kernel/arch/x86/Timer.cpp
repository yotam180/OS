#include "arch/Timer.hpp"

#include "TextMode/TextMode.hpp"
#include "arch/internal/IDT.hpp"
#include "arch/io/Ports.hpp"

static constexpr UINT16 TIMER_INTERRUPT = 32; // IRQ0
static constexpr UINT16 TIMER_COMMAND = 0x43;
static constexpr UINT16 TIMER_INIT_COMMAND = 0x36;
static constexpr UINT16 TIMER_DATA = 0x40;

namespace Arch::Timer
{
static void OnTick(const INTERRUPT_STATE *const state);
} // namespace Arch::Timer

void Arch::Timer::Init()
{
    Arch::RegisterInterruptHandler(TIMER_INTERRUPT, &OnTick);

    static constexpr UINT16 clock_freq = 1193180 / 50; // Must be in the uint16 bounds

    Io::PortByteOut(TIMER_COMMAND, TIMER_INIT_COMMAND);
    Io::PortByteOut(TIMER_DATA, (UINT8)(clock_freq & 0xff));
    Io::PortByteOut(TIMER_DATA, (UINT8)((clock_freq >> 8) & 0xff));
}

void Arch::Timer::Stop()
{
}

static void Arch::Timer::OnTick(const INTERRUPT_STATE *const state)
{
    UNUSED(state);
    OS::TextDisplay::GetDefault().Print("Timer tick");
}
