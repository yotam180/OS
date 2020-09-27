#pragma once

#include "Ktype.hpp"

/*
This file initializes the interrupt descriptor table.
*/

// Note: Personal opinion: what a weird struct. A custom type for the uint8_t field might be beneficial?
// TODO: Check if the fields in the Present, DPL, StorageSegment, Type are in the right order.
namespace Arch
{

typedef struct
{
    UINT16 OffsetLow;
    UINT16 Selector;
    UINT8 Reserved;
    UINT8 Flags;
    UINT16 OffsetHigh;
} __attribute__((packed)) IDT_ENTRY, *PIDT_ENTRY;

typedef struct
{
    UINT16 Size;
    PVOID Address;
} __attribute__((packed)) IDTR, *PIDTR;

typedef struct
{
    UINT32 DS;
    UINT32 Edi;
    UINT32 Esi;
    UINT32 Ebp;
    UINT32 Esp;
    UINT32 Ebx;
    UINT32 Edx;
    UINT32 Ecx;
    UINT32 Eax;
    UINT32 Eflags;
    UINT32 InterruptNumber;
} __attribute__((packed)) INTERRUPT_STATE, *PINTERRUPT_STATE;

using PINTERRUPT_HANDLER = void (*)(const INTERRUPT_STATE *const state);

constexpr SIZE_T IDT_SIZE = 256;
extern IDT_ENTRY _IDT[IDT_SIZE];
extern PINTERRUPT_HANDLER _InterruptHandlers[IDT_SIZE];
extern IDTR _IDTR;

void RegisterInterruptHandler(const SIZE_T interruptNumber, const PINTERRUPT_HANDLER handler);

void SetIDTGate(const SIZE_T index, const PVOID gate);
void SetIDT();
void PopulateIDT();

extern "C" void KeIsrHandler(const INTERRUPT_STATE *const state);
extern "C" void KeIrqHandler(const INTERRUPT_STATE *const state);

} // namespace Arch
