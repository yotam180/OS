; Boot Sector in 16 bit mode
%include "sector0/sector0.S"

; Additional sectors use 32 bit
    bits 32

    VIDEO_MEMORY    equ 0b8000h
    WHITE_ON_BLACK  equ 0fh


_main32:
    jmp     $                   ; Guard loop


; original string at eax
puts32:
    mov     edx, VIDEO_MEMORY
_puts32_loop:
    mov     cl, byte [eax]
    cmp     cl, 0
    jz      _puts32_end
    mov     byte [edx], cl
    inc     eax
_puts32_end:
    ret
