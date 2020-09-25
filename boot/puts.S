; Given a pointer to a NULL terminated string, prints that string
; to the screen.
;
; Arguments:
;   BX - pointer to the string
puts:
    mov     ah, 0eh
_puts_loop:
    mov     al, byte [bx]
    int     10h
    inc     bx
    cmp     byte [bx], 0
    jnz     _puts_loop

    ret