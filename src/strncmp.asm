bits 64
section .text

global strncmp

strncmp:
    xor	rax, rax
    xor r11, r11

loop:
    cmp r11, rdx
    je end
    inc r11
    cmpsb
    jnz diff
    cmp byte [rdi - 1], 0
    jne loop

end:
    ret

diff:
    movzx rax, byte [rdi - 1]
    movzx r10, byte [rsi - 1]
    sub rax, r10
    jmp end