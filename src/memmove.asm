bits 64
section .text

global memmove

memmove:
    mov rax, rdi
    cmp rdi, rsi
    je done
    jb fast
    mov rcx, rsi
    add rcx, rdx
    cmp rdi, rcx
    jae fast

slow:
    std
    mov rcx, rdx
    dec rdx
    add rsi, rdx
    add rdi, rdx
    rep movsb
    cld
    ret

fast:
    mov rcx, rdx
    rep movsb

done:
    ret