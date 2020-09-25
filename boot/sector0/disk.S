; Loads the rest of the sectors from the current(?) disk to the given memory address
; ax    - Sector # to read
; es:bx - Memory address to load to should be loaded into
; 
; Return:
; al    - the number of sectors read
BrLoadFirmwareSectors:
    push    bp
    mov     bp, sp
    push    ax
    mov     ah, 02h
    mov     ch, 0       ; Cylinder
    mov     dh, 0       ; Head
    mov     cl, 2       ; Sector

    int     13h
    jc     _BrLoadFirmwareSectors_Fail

    pop     dx
    cmp     al, dl
    jne     _BrLoadFirmwareSectors_Fail_2

    mov     sp, bp
    pop     bp
    ret
    

_BrLoadFirmwareSectors_Fail:
    ; Print error and die
    mov     bx, _CouldNotReadDisk
    call    BrPutString
    jmp     $


_BrLoadFirmwareSectors_Fail_2:
    mov     bx, _DidNotReadTheCorrectAmount
    call    BrPutString
    jmp     $


_CouldNotReadDisk:
    db      "Could not read disk", 0

_DidNotReadTheCorrectAmount:
    db      "Did not read the correct amount of sectors", 0