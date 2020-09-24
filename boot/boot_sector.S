; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

    mov     ah, 0eh
    mov     al, 'X'
    int     10h

    jmp     $

    ; TODO: Rewrite this but with understanding of the $ and $$ signs
    times   510-($-$$) db 0
    dw      0xaa55
