register:
    mov ax, 0x10        ; l'adresse est copiée dans le registre ax
    mov ds, ax          ; le registre ds est copié dans ax
    mov es, ax          ; meme chose que ci-dessus avec es
    mov ss, ax          ; meme chose.... Bref, vous avez compris :)
    mov fs, ax
    mov gs, ax
    
hatogdtload:
    ;lgdt 0    
    
    mov rsp, rax        ; le registre rsp copié dans rax
    push 0x10           ; empile à l'adresse 0x10
    push rax            ; empile dans le registre rax
    pushf               ; flags
    push 0x08           ; empile à l'adresse 0x08
    push register       ; empile dans register
    iretq               ; retour 64-bits précédement provoqué par une interruption






