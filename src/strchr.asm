bits 64
section .text

global strchr

strchr:

loop:
    cmp byte [rdi], sil
    je  end
    cmp byte [rdi], 0
    je  end_null
    inc rdi
    jmp loop

end_null:
    mov rax, 0
    ret

end:
    mov rax, rdi
    ret