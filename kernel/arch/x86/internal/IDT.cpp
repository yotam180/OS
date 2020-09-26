#include "arch/internal/IDT.hpp"

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
