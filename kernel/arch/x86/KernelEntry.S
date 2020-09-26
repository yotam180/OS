    bits 32
    extern KeStart

    mov     esp, 0x6000             ; Init the stack
    mov     ebp, esp
    call    KeStart                 ; Just call KeStart function
    jmp     $ 