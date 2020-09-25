; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

bits 16

    mov     bx, 0x7c00 + _str
    call    puts
    jmp     $

_str:
    db      "Hello, world!", 0

puts:                                  ; Pointer in bx
    mov     ah, 0eh
_puts_loop:
    mov     al, byte [bx]
    int     10h
    inc     bx
    cmp     byte [bx], 0
    jnz     _puts_loop

    ret

    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0xaa55
