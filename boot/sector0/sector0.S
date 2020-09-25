; TODO: Rewrite this file in AT&T syntax
; TODO: Support UEFI boot

    org     7c00h
    bits    16

; Main Code
    mov [g_boot_drive], dl

    mov     bp, 8000h                   ; Initialize Stack
    mov     sp, bp

    mov     bx, 9000h                   ; Dst address
    mov     al, 1                       ; Sectors
    call    load_firmware

    mov     bx, [9000h]
    call    putxw

    jmp     $

; Includes
; TODO: Find a way to not write sector0/ here
%include "sector0/puts.S"
%include "sector0/disk.S"

; Globals
g_boot_drive:
    db    0

; Padding
    times   510-($-$$) db 0             ; TODO: Rewrite this but with understanding of the $ and $$ signs
    dw      0aa55h
