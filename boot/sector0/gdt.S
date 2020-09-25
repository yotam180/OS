_GdtStart:

_Gdt_Null:              ; 8 Bytes of NULL gdt (used for error trapping)
    dd  0
    dd  0

_Gdt_Code:
    ; Base = 0, Limit=0xfffff (will be shifted to 0xfffff000 by the granularity bit)
    dw  0ffffh          ; Limit 0-15
    dw  0               ; Base 0-15
    db  0               ; Base 16-23
    db  10011010b       ; Type 0b1010 - code, readable
                        ; P & S, !DL (TODO: What do these mean?)
    db  11001111b       ; High 4 bits - flags (Granularity, 32 bit)
                        ; Low 4 bits - Limit 16-19
    db  0

_Gdt_Data:
    dw  0ffffh          ; Limit 0-15
    dw  0               ; Base 0-15
    db  0               ; Base 16-23
    db  10010010b       ; Type 0010 - data, writable
    db  11001111b
    db  0

_GdtEnd:


_GdtDescriptor:
    dw _GdtEnd - _GdtStart - 1
    dd _GdtStart


GDT_CODE_SEGMENT    equ _Gdt_Code - _GdtStart
GDT_DATA_SEGMENT    equ _Gdt_Data - _GdtStart
