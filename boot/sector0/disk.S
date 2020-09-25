; Loads the rest of the sectors from the current(?) disk to the given memory address
; ax    - Sector # to read
; es:bx - Memory address to load to should be loaded into
; 
; Return:
; al    - the number of sectors read
load_firmware:
    push    bp
    mov     bp, sp
    push    ax
    mov     ah, 02h
    mov     ch, 0       ; Cylinder
    mov     dh, 0       ; Head
    mov     cl, 2       ; Sector

    int     13h
    jc     _disk_load_fail

    pop     dx
    cmp     al, dl
    jne     _disk_load_fail_2

    mov     sp, bp
    pop     bp
    ret
    

_disk_load_fail:
    ; Print error and die
    mov     bx, _error_str
    call    puts
    jmp     $

_disk_load_fail_2:
    mov     bx, _error_str_2
    call    puts
    jmp     $

_error_str:
    db      "Could not read disk", 0

_error_str_2:
    db      "Did not read the correct amount of sectors", 0