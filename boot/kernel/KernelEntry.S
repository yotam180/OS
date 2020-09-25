    bits 32
    extern KeStart

    ; Just call KeStart function
    call    KeStart 
    jmp     $ 