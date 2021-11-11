bits 64
section .txt

global strlen

strlen:
    xor rcx, rcx

loop:
    cmp byte [rdi], 0
    je end
    inc rcx
    inc rdi
    jmp loop
end:
    mov rax, rcx
    ret