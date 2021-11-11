bits 64
section .text

global strcasecmp

strcasecmp:
    xor rdx, rdx

loop:
    mov r9b, byte [rdi + rdx]
    mov r10b, byte [rsi + rdx]
    jmp min_src

min_src:
    cmp r9b, 'A'
    jl  min_dest
    cmp r9b, 'Z'
    jg min_dest
    add r9b, 32

min_dest:
    cmp r10b, 'A'
    jl endl
    cmp r10b, 'Z'
    jg endl
    add r10b, 32

endl:
    cmp r9b, r10b
    jne nega
    cmp r9b, 0
    je egg
    inc rdx
    jmp loop

nega:
    sub r9b, r10b
    movsx rax, r9b
    jmp end

egg:
    mov rax, 0
    jmp end

end:
    ret