; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

bits 16

    call _next
_next:
    pop     bx
    add     bx, (_str-$+1)
    call    print
    jmp     $

_str:
    db      "Hello, world!", 0

print:                                  ; Pointer in bx
    mov     ah, 0eh
_print_loop:
    mov     al, byte [bx]
    int     10h
    inc     bx
    cmp     byte [bx], 0
    jnz     _print_loop

    ret

    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0xaa55
