; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

org     0x7c00
bits    16

    mov     bx, 0e713h
    call    putxw
    jmp     $

; TODO: Find a way to not write sector0/ here
%include "sector0/puts.S"

    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0xaa55
