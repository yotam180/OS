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
    UINT16HL divisor{1193180 / 50};
    UINT8 low = divisor.U8.Low;
    UINT8 high = divisor.U8.High;
    /* Send the command */
    Io::PortByteOut(0x43, 0x36); /* Command port */
    Io::PortByteOut(0x40, low);
    Io::PortByteOut(0x40, high);

    OS::TextDisplay::GetDefault().PrintHex(low);
    OS::TextDisplay::GetDefault().PrintHex(high);

    // auto x = Io::PortByteIn(0x40);
    // auto y = Io::PortByteIn(0x40);
    // OS::TextDisplay::GetDefault().PrintHex(x);
    // OS::TextDisplay::GetDefault().PrintHex(y);

    // x = Io::PortByteIn(0x40);
    // y = Io::PortByteIn(0x40);
    // OS::TextDisplay::GetDefault().PrintHex(x);
    // OS::TextDisplay::GetDefault().PrintHex(y);
}

void Arch::Timer::Stop()
{
}

// static void Arch::Timer::OnTick(const INTERRUPT_STATE *const state)
// {
//     UNUSED(state);
//     OS::TextDisplay::GetDefault().Print("Timer tick");
// }
