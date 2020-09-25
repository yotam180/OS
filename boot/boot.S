; Boot Sector
%include "sector0/sector0.S"

; More Sectors
times 256 dw 1337h
times 256 dw 2020h
