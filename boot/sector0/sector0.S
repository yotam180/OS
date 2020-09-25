; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

org     0x7c00
bits    16

    mov     bx, 0xa000
    mov     es, bx
    mov     bx, 0                       ; Dst address
    mov     al, 1                       ; Sector
    call    load_firmware

    jmp     $

; TODO: Find a way to not write sector0/ here
%include "sector0/puts.S"
%include "sector0/disk.S"

    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0xaa55
