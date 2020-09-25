; Loads the rest of the sectors from the current(?) disk to the given memory address
; ax    - Sector # to read
; es:bx - Memory address to load to should be loaded into
; 
; Return:
; al    - the number of sectors read
load_firmware:  
    mov     ah, 02h
    mov     ch, 0       ; Cylinder
    mov     cl, 1       ; Sector
    mov     dh, 0       ; Track
    mov     dl, 0       ; Drive

    int     13h
    jc     _disk_load_fail
    ret
    

_disk_load_fail:
    ; Print error and die
    mov     bx, _error_str
    call    puts
    jmp     $

_error_str:
    db      "Could not read disk", 0
