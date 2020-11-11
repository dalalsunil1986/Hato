; Table global de description (GDT)
; Global Description Table (GDT)

gdtr DW 0
     DD 0

setGdt:
    mov rax, [rsp + 4]
    mov [gdtr + 2], rax
    mov ax, [rsp + 8]
    mov [gdtr], ax
    lgdt [gdtr]
    ret

reloadSegments:
    jmp 0x08:reload_CS

.reload_CS:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret
