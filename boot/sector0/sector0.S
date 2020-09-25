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

    mov     bx, NEXT_CODE_EXEC            ; Dst address
    mov     al, 1                       ; Sectors
    call    BrLoadFirmwareSectors

    mov     bx, [NEXT_CODE_EXEC]
    call    BrPutHexWord

    jmp     NEXT_CODE_EXEC

; Includes
; TODO: Find a way to not write sector0/ here
%include "sector0/puts.S"
%include "sector0/disk.S"

; Globals
_BootDrive:
    db    0

; Padding
    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0aa55h
