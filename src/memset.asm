bits 64
section .text

global memset

memset:
    mov r8, rdi
    mov rax, rsi
    mov rcx, rdx
    rep stosb
    mov rax, r8
    ret