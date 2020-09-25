; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

org     0x7c00
bits    16

    mov     bx, 5dh
    call    putx
    jmp     $

_str:
    db      "Hello, world!", 0

%include "puts.S"

    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0xaa55
