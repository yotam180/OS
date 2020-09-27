#include "arch/internal/IDT.hpp"

#include "TextMode/TextMode.hpp"

Arch::IDT_ENTRY Arch::_IDT[IDT_SIZE];
Arch::IDTR Arch::_IDTR;

void Arch::SetIDTGate(const SIZE_T index, const PVOID gate)
{
    OS::TextDisplay::GetDefault().PrintHex(reinterpret_cast<UINT32>(gate));
    OS::TextDisplay::GetDefault().Print("\n");
    _IDT[index].OffsetLow = reinterpret_cast<SIZE_T>(gate) & 0xffff; // TODO: Macros for these once we need it
    _IDT[index].Selector = 0x8;                                      // Kernel code segment
    _IDT[index].Reserved = 0;
    // _IDT[index].Present = 1;
    // _IDT[index].DPL = 3; // TODO: This is an unsafe setting... I think... We might want to set it to 0
    // _IDT[index].StorageSegment = 0;
    // _IDT[index].Type = 0xe; // TODO: What exactly does this mean?
    _IDT[index].Flags = 0x8e; // Why?
    _IDT[index].OffsetHigh = (reinterpret_cast<SIZE_T>(gate) >> 16) & 0xffff;
}

void Arch::SetIDT()
{
    _IDTR.Address = &_IDT;
    _IDTR.Size = IDT_SIZE * sizeof(IDT_ENTRY) - 1;

    __asm__ __volatile__("lidt (%0)" ::"r"(&_IDTR));
}

extern "C" void Arch::KeIsrHandler(const Arch::INTERRUPT_STATE *const state)
{
    UNUSED(state);
    OS::TextDisplay::GetDefault().Print("An interrupt handler was called ");
    OS::TextDisplay::GetDefault().PrintHex(state->InterruptNumber);
    OS::TextDisplay::GetDefault().Print("\n");
}

extern "C" void Arch::KeIrqHandler(const Arch::INTERRUPT_STATE *const state)
{
    UNUSED(state);
    OS::TextDisplay::GetDefault().Print("A hardware interrupt handler was called ");
    OS::TextDisplay::GetDefault().PrintHex(state->InterruptNumber);
    OS::TextDisplay::GetDefault().Print("\n");
}

extern "C" void KeIsr0();
extern "C" void KeIsr1();
extern "C" void KeIsr2();
extern "C" void KeIsr3();
extern "C" void KeIsr4();
extern "C" void KeIsr5();
extern "C" void KeIsr6();
extern "C" void KeIsr7();
extern "C" void KeIsr8();
extern "C" void KeIsr9();
extern "C" void KeIsr10();
extern "C" void KeIsr11();
extern "C" void KeIsr12();
extern "C" void KeIsr13();
extern "C" void KeIsr14();
extern "C" void KeIsr15();
extern "C" void KeIsr16();
extern "C" void KeIsr17();
extern "C" void KeIsr18();
extern "C" void KeIsr19();
extern "C" void KeIsr20();
extern "C" void KeIsr21();
extern "C" void KeIsr22();
extern "C" void KeIsr23();
extern "C" void KeIsr24();
extern "C" void KeIsr25();
extern "C" void KeIsr26();
extern "C" void KeIsr27();
extern "C" void KeIsr28();
extern "C" void KeIsr29();
extern "C" void KeIsr30();
extern "C" void KeIsr31();

extern "C" void KeIrq0();
extern "C" void KeIrq1();
extern "C" void KeIrq2();
extern "C" void KeIrq3();
extern "C" void KeIrq4();
extern "C" void KeIrq5();
extern "C" void KeIrq6();
extern "C" void KeIrq7();
extern "C" void KeIrq8();
extern "C" void KeIrq9();
extern "C" void KeIrq10();
extern "C" void KeIrq11();
extern "C" void KeIrq12();
extern "C" void KeIrq13();
extern "C" void KeIrq14();
extern "C" void KeIrq15();

void Arch::PopulateIDT()
{
    // REM OS::TextDisplay::GetDefault().Print("PopulateIDT called\n");
    // REM OS::TextDisplay::GetDefault().PrintHex(reinterpret_cast<UINT32>(KeIsr0));
    // REM OS::TextDisplay::GetDefault().Print("\n");
    SetIDTGate(0, reinterpret_cast<PVOID>(KeIsr0));
    SetIDTGate(1, reinterpret_cast<PVOID>(KeIsr1));
    SetIDTGate(2, reinterpret_cast<PVOID>(KeIsr2));
    SetIDTGate(3, reinterpret_cast<PVOID>(KeIsr3));
    SetIDTGate(4, reinterpret_cast<PVOID>(KeIsr4));
    SetIDTGate(5, reinterpret_cast<PVOID>(KeIsr5));
    SetIDTGate(6, reinterpret_cast<PVOID>(KeIsr6));
    SetIDTGate(7, reinterpret_cast<PVOID>(KeIsr7));
    SetIDTGate(8, reinterpret_cast<PVOID>(KeIsr8));
    SetIDTGate(9, reinterpret_cast<PVOID>(KeIsr9));
    SetIDTGate(10, reinterpret_cast<PVOID>(KeIsr10));
    SetIDTGate(11, reinterpret_cast<PVOID>(KeIsr11));
    SetIDTGate(12, reinterpret_cast<PVOID>(KeIsr12));
    SetIDTGate(13, reinterpret_cast<PVOID>(KeIsr13));
    SetIDTGate(14, reinterpret_cast<PVOID>(KeIsr14));
    SetIDTGate(15, reinterpret_cast<PVOID>(KeIsr15));
    SetIDTGate(16, reinterpret_cast<PVOID>(KeIsr16));
    SetIDTGate(17, reinterpret_cast<PVOID>(KeIsr17));
    SetIDTGate(18, reinterpret_cast<PVOID>(KeIsr18));
    SetIDTGate(19, reinterpret_cast<PVOID>(KeIsr19));
    SetIDTGate(20, reinterpret_cast<PVOID>(KeIsr20));
    SetIDTGate(21, reinterpret_cast<PVOID>(KeIsr21));
    SetIDTGate(22, reinterpret_cast<PVOID>(KeIsr22));
    SetIDTGate(23, reinterpret_cast<PVOID>(KeIsr23));
    SetIDTGate(24, reinterpret_cast<PVOID>(KeIsr24));
    SetIDTGate(25, reinterpret_cast<PVOID>(KeIsr25));
    SetIDTGate(26, reinterpret_cast<PVOID>(KeIsr26));
    SetIDTGate(27, reinterpret_cast<PVOID>(KeIsr27));
    SetIDTGate(28, reinterpret_cast<PVOID>(KeIsr28));
    SetIDTGate(29, reinterpret_cast<PVOID>(KeIsr29));
    SetIDTGate(30, reinterpret_cast<PVOID>(KeIsr30));
    SetIDTGate(31, reinterpret_cast<PVOID>(KeIsr31));

    SetIDTGate(32, reinterpret_cast<PVOID>(KeIrq0));
    SetIDTGate(33, reinterpret_cast<PVOID>(KeIrq1));
    SetIDTGate(34, reinterpret_cast<PVOID>(KeIrq2));
    SetIDTGate(35, reinterpret_cast<PVOID>(KeIrq3));
    SetIDTGate(36, reinterpret_cast<PVOID>(KeIrq4));
    SetIDTGate(37, reinterpret_cast<PVOID>(KeIrq5));
    SetIDTGate(38, reinterpret_cast<PVOID>(KeIrq6));
    SetIDTGate(39, reinterpret_cast<PVOID>(KeIrq7));
    SetIDTGate(40, reinterpret_cast<PVOID>(KeIrq8));
    SetIDTGate(41, reinterpret_cast<PVOID>(KeIrq9));
    SetIDTGate(42, reinterpret_cast<PVOID>(KeIrq10));
    SetIDTGate(43, reinterpret_cast<PVOID>(KeIrq11));
    SetIDTGate(44, reinterpret_cast<PVOID>(KeIrq12));
    SetIDTGate(45, reinterpret_cast<PVOID>(KeIrq13));
    SetIDTGate(46, reinterpret_cast<PVOID>(KeIrq14));
    SetIDTGate(47, reinterpret_cast<PVOID>(KeIrq15));
}