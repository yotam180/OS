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

; Prints a byte in hex characters from the BL register
putx:
    mov     ah, 0eh
    mov     cl, bl
    shr     cl, 4
    call    putx_single
    int     10h
    mov     cl, bl
    call    putx_single
    int     10h
    ret


putx_single: ; Nible in CL, ret in AL
    mov     al, cl
    and     al, 0fh
    cmp     cl, 0ah
    jge     _putx_above
    add     al, '0'
    jmp     _putx_end
_putx_above:
    add     al, 'a' - 0ah
_putx_end:
    ret
