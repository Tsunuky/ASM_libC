bits 64
section .text

global strstr

strstr:
    xor rbx, rbx

loop:
    mov r8, rbx
    xor r9, r9
    jmp subloop

incsub:
    inc r8
    inc r9

subloop:
    mov dl, byte [rsi+r9]
    cmp dl, 0
    je non_null
    mov al, byte [rdi+r8]
    cmp al, 0
    je ret_null
    cmp al, dl
    je incsub
    inc rbx
    jmp loop

ret_null:
    mov rax, 0
    ret

non_null:
    mov rax, rdi
    add rax, rbx
    ret
