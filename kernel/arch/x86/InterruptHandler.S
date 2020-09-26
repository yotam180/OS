
extern KeIsrHandler

; This should handle interrupts
KeIsrPreHandle:
    cli
    pushf
    pushad                  ; EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI (reverse order, EDI is first in the struct)
    mov     ax, ds
    push    ax
    mov     ax, 10h        ; Kernel data segment
    mov     ds, eax
    mov     es, eax
    mov     fs, eax
    mov     gs, eax

    call    KeIsrHandler

    pop     eax
    mov     ds, eax
    mov     es, eax
    mov     fs, eax
    mov     gs, eax
    popad
    popf

    sti
    iret

KeIsr0:
    push    dword 0
    jmp     KeIsrPreHandle
