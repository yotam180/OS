; Br = Boot Real (real mode)

; Given a pointer to a NULL terminated string, prints that string
; to the screen.
;
; Arguments:
;   BX - pointer to the string
BrPutString:
    mov     ah, 0eh
_BrPutString_loop:
    mov     al, byte [bx]
    int     10h
    inc     bx
    cmp     byte [bx], 0
    jnz     _BrPutString_loop

    ret

BrPutHexWord:
    xchg    bh, bl
    call    BrPutHexByte
    xchg    bh, bl
    call    BrPutHexByte
    ret

; Prints a byte in hex characters from the BL register
BrPutHexByte:
    mov     ah, 0eh
    mov     cl, bl
    shr     cl, 4
    call    BrPutHexNibble
    int     10h
    mov     cl, bl
    call    BrPutHexNibble
    int     10h
    ret


BrPutHexNibble: ; Nible in CL, ret in AL
    mov     al, cl
    and     al, 0fh
    cmp     al, 0ah
    jae     _BrPutHexNibble_Above
    add     al, '0'
    jmp     _BrPutHexNibble_End
_BrPutHexNibble_Above:
    add     al, 'a' - 0ah
_BrPutHexNibble_End:
    ret
