    bits 32
    org 9000h

    VIDEO_MEMORY    equ 0b8000h
    WHITE_ON_BLACK  equ 0fh

; Bp - Boot protected (32 bit mode)
BpMain:
    mov     edi, _HelloFromProtected
    call    BpPutString
    jmp     $                       ; Guard loop


_HelloFromProtected:
    db      "Hello from protected mode!           ", 0


; Prints a string to the beginning of the text-mode VGA memory
; original string at edi
BpPutString:
    mov     edx, VIDEO_MEMORY
_BpPutString_Loop:
    mov     cl, byte [edi]
    cmp     cl, 0
    jz      _BpPutString_End
    mov     byte [edx], cl
    inc     edx
    mov     byte [edx], WHITE_ON_BLACK
    inc     edx
    inc     edi
    jmp     _BpPutString_Loop
_BpPutString_End:
    ret


times 1000 db 0 ; Just to make sure we have some sectors to load?