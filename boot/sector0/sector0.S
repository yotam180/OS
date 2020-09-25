; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

    org     7c00h
    bits    16

    STACK_START     equ 8000h
    NEXT_CODE_EXEC  equ 9000h

; Main Code
    mov     [_BootDrive], dl

    mov     bp, STACK_START             ; Initialize Stack
    mov     sp, bp

    mov     bx, NEXT_CODE_EXEC          ; Dst address
    mov     al, 1                       ; Sectors
    call    BrLoadFirmwareSectors
    mov     bx, [NEXT_CODE_EXEC]
    call    BrPutHexWord

    ; Transferring control to the 32 bit code outside of the sector
    cli                                 ; Clearing interrupts
    lgdt    [_GdtDescriptor]            ; Setting the GDT to our structure
    mov     eax, cr0                    ; Setting the Protected Mode Enable bit in the CR0 register 
    or      eax, 1                      ; TODO: How does this work before we moved to protected mode?
    mov     cr0, eax

    jmp GDT_CODE_SEGMENT:BrCall32BitEntryPoint

BrCall32BitEntryPoint:
    mov     eax, GDT_DATA_SEGMENT   ; Initializing the segment registers
    mov     ds, eax
    mov     ss, eax
    mov     es, eax
    mov     fs, eax
    mov     gs, eax
    jmp     [NEXT_CODE_EXEC]

; Includes
; TODO: Find a way to not write sector0/ here
%include "sector0/puts.S"
%include "sector0/disk.S"
%include "sector0/gdt.S"

; Globals
_BootDrive:
    db    0

; Padding
    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0aa55h
