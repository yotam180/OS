#include "arch/Timer.hpp"

#include "TextMode/TextMode.hpp"
#include "arch/Interrupts.hpp"
#include "arch/io/Ports.hpp"

static constexpr UINT16 TIMER_INTERRUPT = 32;
static constexpr UINT16 TIMER_COMMAND = 0x43;
static constexpr UINT16 TIMER_INIT_COMMAND = 0x35;
static constexpr UINT16 TIMER_CHANNEL_0 = 0x40;

namespace Arch::Timer
{
static void OnTick(const INTERRUPT_STATE *const state);
} // namespace Arch::Timer

void Arch::Timer::Setup(const UINT16 frequency)
{
    Arch::RegisterInterruptHandler(TIMER_INTERRUPT, &OnTick);

    UINT16HL value{static_cast<UINT16>(1193180 / frequency)};

    Io::PortByteOut(TIMER_COMMAND, TIMER_INIT_COMMAND);
    Io::PortByteOut(TIMER_CHANNEL_0, value.U8.Low);
    Io::PortByteOut(TIMER_CHANNEL_0, value.U8.High);
}

static void Arch::Timer::OnTick(const INTERRUPT_STATE *const state)
{
    UNUSED(state);
}
