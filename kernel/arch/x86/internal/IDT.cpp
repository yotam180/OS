#include "arch/internal/IDT.hpp"

#include "TextMode/TextMode.hpp"

Arch::IDT_ENTRY Arch::_IDT[IDT_SIZE];
Arch::IDTR Arch::_IDTR;

void Arch::SetIDTGate(const SIZE_T index, const PVOID gate)
{
    _IDT[index].OffsetLow = reinterpret_cast<SIZE_T>(gate) & 0xffff; // TODO: Macros for these once we need it
    _IDT[index].OffsetHigh = (reinterpret_cast<SIZE_T>(gate) >> 16) & 0xffff;
    _IDT[index].Reserved = 0;
    _IDT[index].Present = 1;
    _IDT[index].DPL = 3; // TODO: This is an unsafe setting... I think... We might want to set it to 0
    _IDT[index].StorageSegment = 0;
    _IDT[index].Type = 0xe; // TODO: What exactly does this mean?
}

void Arch::SetIDT()
{
    _IDTR.Address = &_IDT;
    _IDTR.Size = IDT_SIZE * sizeof(IDT_ENTRY) - 1;

    __asm__ __volatile__("lidt (%0)" ::"r"(&_IDTR));
}

extern "C" void Arch::KeIsrHandler(const Arch::INTERRUPT_STATE state)
{
    UNUSED(state);
    OS::TextDisplay::GetDefault().Print("An interrupt handler was called\n");
}

extern PVOID KeIsr0;
extern PVOID KeIsr1;
extern PVOID KeIsr2;
extern PVOID KeIsr3;
extern PVOID KeIsr4;
extern PVOID KeIsr5;
extern PVOID KeIsr6;
extern PVOID KeIsr7;
extern PVOID KeIsr8;
extern PVOID KeIsr9;
extern PVOID KeIsr10;
extern PVOID KeIsr11;
extern PVOID KeIsr12;
extern PVOID KeIsr13;
extern PVOID KeIsr14;
extern PVOID KeIsr15;
extern PVOID KeIsr16;
extern PVOID KeIsr17;
extern PVOID KeIsr18;
extern PVOID KeIsr19;
extern PVOID KeIsr20;
extern PVOID KeIsr21;
extern PVOID KeIsr22;
extern PVOID KeIsr23;
extern PVOID KeIsr24;
extern PVOID KeIsr25;
extern PVOID KeIsr26;
extern PVOID KeIsr27;
extern PVOID KeIsr28;
extern PVOID KeIsr29;
extern PVOID KeIsr30;
extern PVOID KeIsr31;

void Arch::PopulateIDT()
{
    SetIDTGate(0, KeIsr0);
    SetIDTGate(1, KeIsr1);
    SetIDTGate(2, KeIsr2);
    SetIDTGate(3, KeIsr3);
    SetIDTGate(4, KeIsr4);
    SetIDTGate(5, KeIsr5);
    SetIDTGate(6, KeIsr6);
    SetIDTGate(7, KeIsr7);
    SetIDTGate(8, KeIsr8);
    SetIDTGate(9, KeIsr9);
    SetIDTGate(10, KeIsr10);
    SetIDTGate(11, KeIsr11);
    SetIDTGate(12, KeIsr12);
    SetIDTGate(13, KeIsr13);
    SetIDTGate(14, KeIsr14);
    SetIDTGate(15, KeIsr15);
    SetIDTGate(16, KeIsr16);
    SetIDTGate(17, KeIsr17);
    SetIDTGate(18, KeIsr18);
    SetIDTGate(19, KeIsr19);
    SetIDTGate(20, KeIsr20);
    SetIDTGate(21, KeIsr21);
    SetIDTGate(22, KeIsr22);
    SetIDTGate(23, KeIsr23);
    SetIDTGate(24, KeIsr24);
    SetIDTGate(25, KeIsr25);
    SetIDTGate(26, KeIsr26);
    SetIDTGate(27, KeIsr27);
    SetIDTGate(28, KeIsr28);
    SetIDTGate(29, KeIsr29);
    SetIDTGate(30, KeIsr30);
    SetIDTGate(31, KeIsr31);
}