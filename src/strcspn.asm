bits 64
section .text

GLOBAL strcspn 

strcspn:
    mov r10, rsi
    xor r11, r11

cond_a:
    cmp byte [rdi+r11], 0
    je exit

cond_b:
    cmp byte [r10], 0
    je aug
    mov r14b, [rdi+r11]
    cmp [r10], r14b
    je exit
    inc r10
    jmp cond_b

aug:
    mov r10, rsi
    inc r11
    jmp cond_a

exit:
    mov rax, r11
    ret