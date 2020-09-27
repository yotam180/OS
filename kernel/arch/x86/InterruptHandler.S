bits 32

extern KeIsrHandler

; This should handle interrupts
KeIsrPreHandle:
    cli
    pushf
    pushad                  ; EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI (reverse order, EDI is first in the struct)
    mov     ax, ds
    push    eax
    mov     ax, 10h         ; Kernel data segment
    mov     ds, eax
    mov     es, eax
    mov     fs, eax
    mov     gs, eax

    push    esp             ; Pushing a "pointer" to our struct
    call    KeIsrHandler
    add     esp, 4

    pop     eax
    mov     ds, eax
    mov     es, eax
    mov     fs, eax
    mov     gs, eax
    popad
    popf
    
    add     esp, 4          ; Clean up pushed interrupt number, TODO: This might be 8
    sti
    iret

global KeIsr0
KeIsr0:
    push    dword 0
    jmp     KeIsrPreHandle
global KeIsr1
KeIsr1:
    push    dword 1
    jmp     KeIsrPreHandle
global KeIsr2
KeIsr2:
    push    dword 2
    jmp     KeIsrPreHandle
global KeIsr3
KeIsr3:
    push    dword 3
    jmp     KeIsrPreHandle
global KeIsr4
KeIsr4:
    push    dword 4
    jmp     KeIsrPreHandle
global KeIsr5
KeIsr5:
    push    dword 5
    jmp     KeIsrPreHandle
global KeIsr6
KeIsr6:
    push    dword 6
    jmp     KeIsrPreHandle
global KeIsr7
KeIsr7:
    push    dword 7
    jmp     KeIsrPreHandle
global KeIsr8
KeIsr8:
    push    dword 8
    jmp     KeIsrPreHandle
global KeIsr9
KeIsr9:
    push    dword 9
    jmp     KeIsrPreHandle
global KeIsr10
KeIsr10:
    push    dword 10
    jmp     KeIsrPreHandle
global KeIsr11
KeIsr11:
    push    dword 11
    jmp     KeIsrPreHandle
global KeIsr12
KeIsr12:
    push    dword 12
    jmp     KeIsrPreHandle
global KeIsr13
KeIsr13:
    push    dword 13
    jmp     KeIsrPreHandle
global KeIsr14
KeIsr14:
    push    dword 14
    jmp     KeIsrPreHandle
global KeIsr15
KeIsr15:
    push    dword 15
    jmp     KeIsrPreHandle
global KeIsr16
KeIsr16:
    push    dword 16
    jmp     KeIsrPreHandle
global KeIsr17
KeIsr17:
    push    dword 17
    jmp     KeIsrPreHandle
global KeIsr18
KeIsr18:
    push    dword 18
    jmp     KeIsrPreHandle
global KeIsr19
KeIsr19:
    push    dword 19
    jmp     KeIsrPreHandle
global KeIsr20
KeIsr20:
    push    dword 20
    jmp     KeIsrPreHandle
global KeIsr21
KeIsr21:
    push    dword 21
    jmp     KeIsrPreHandle
global KeIsr22
KeIsr22:
    push    dword 22
    jmp     KeIsrPreHandle
global KeIsr23
KeIsr23:
    push    dword 23
    jmp     KeIsrPreHandle
global KeIsr24
KeIsr24:
    push    dword 24
    jmp     KeIsrPreHandle
global KeIsr25
KeIsr25:
    push    dword 25
    jmp     KeIsrPreHandle
global KeIsr26
KeIsr26:
    push    dword 26
    jmp     KeIsrPreHandle
global KeIsr27
KeIsr27:
    push    dword 27
    jmp     KeIsrPreHandle
global KeIsr28
KeIsr28:
    push    dword 28
    jmp     KeIsrPreHandle
global KeIsr29
KeIsr29:
    push    dword 29
    jmp     KeIsrPreHandle
global KeIsr30
KeIsr30:
    push    dword 30
    jmp     KeIsrPreHandle
global KeIsr31
KeIsr31:
    push    dword 31
    jmp     KeIsrPreHandle