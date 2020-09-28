#include "arch/Timer.hpp"

#include "TextMode/TextMode.hpp"
#include "arch/internal/IDT.hpp"
#include "arch/io/Ports.hpp"

static constexpr UINT16 TIMER_INTERRUPT = 32; // IRQ0
static constexpr UINT16 TIMER_COMMAND = 0x43;
static constexpr UINT16 TIMER_INIT_COMMAND = 0x35;
static constexpr UINT16 TIMER_CHANNEL_0 = 0x40;

// namespace Arch::Timer
// {
// static void OnTick(const INTERRUPT_STATE *const state);
// } // namespace Arch::Timer

void Arch::Timer::Init()
{
    // Arch::RegisterInterruptHandler(TIMER_INTERRUPT, &OnTick);

    // // static constexpr UINT16 clock_freq = 1193180 / 50; // Must be in the uint16 bounds

    // port_byte_out(TIMER_COMMAND, TIMER_INIT_COMMAND);
    // port_byte_out(TIMER_CHANNEL_0, 1);
    // port_byte_out(TIMER_CHANNEL_0, 1);

    /* Get the PIT value: hardware clock at 1193180 Hz */
    UINT32 divisor = 1193180 / 50;
    UINT8 low = (UINT8)(divisor & 0xFF);
    UINT8 high = (UINT8)((divisor >> 8) & 0xFF);
    /* Send the command */
    port_byte_out(0x43, 0x36); /* Command port */
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);

    auto x = port_byte_in(0x40);
    auto y = port_byte_in(0x40);
    OS::TextDisplay::GetDefault().PrintHex(x);
    OS::TextDisplay::GetDefault().PrintHex(y);
}

void Arch::Timer::Stop()
{
}

// static void Arch::Timer::OnTick(const INTERRUPT_STATE *const state)
// {
//     UNUSED(state);
//     OS::TextDisplay::GetDefault().Print("Timer tick");
// }
