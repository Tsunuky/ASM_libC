bits 64
section .text

global strcmp

strcmp:
    xor rax, rax

loop:
    cmpsb
    jnz diff
    cmp byte [rdi - 1], 0
    jne loop

end:
    ret

diff:
    movzx rax, byte [rdi - 1]
    movzx rdx, byte [rsi - 1]
    sub rax, rdx
    jmp end