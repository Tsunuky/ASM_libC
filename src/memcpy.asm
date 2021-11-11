bits 64
section .text

global memcpy

memcpy:
    mov rax, rdi
    mov rcx, rdx
    rep movsb

    ret