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
    UINT8 Reserved; // Set to 0

    UINT8 Present : 1;
    UINT8 DPL : 2;
    UINT8 StorageSegment : 1;
    UINT8 Type : 4;

    UINT16 OffsetHigh;
} __attribute__((packed)) IDT_ENTRY, *PIDT_ENTRY;

typedef struct
{
    UINT16 Size;
    PVOID Address;
} IDTR, *PIDTR;

constexpr SIZE_T IDT_SIZE = 256;

IDT_ENTRY _IDT[IDT_SIZE]; // TODO: Maybe define this in a CPP file and not a HPP file
IDTR _IDTR;

typedef struct
{
    UINT32 Edi;
    UINT32 Esi;
    UINT32 Ebp;
    UINT32 Esp;
    UINT32 Ebx;
    UINT32 Edx;
    UINT32 Ecx;
    UINT32 Eax;
    UINT32 InterruptNumber;
} INTERRUPT_STATE, *PINTERRUPT_STATE;

void SetIDTGate(const SIZE_T index, const PVOID gate);
void SetIDT();
void PopulateIDT();

// This function is called from the assembly code
extern "C" void KeIsrHandler(INTERRUPT_STATE state);

} // namespace Arch
