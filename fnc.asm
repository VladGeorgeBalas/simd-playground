format ELF64

public my_func

section '.text' executable

my_func:
    ; argumentele sunt in rdi, rsi, rdx, rcx, r8 si r9
    ; in aceasta ordine
    ; preluate din: https://cs61.seas.harvard.edu/site/2018/Asm2/

    ; return in rax
    mov rax, 12     ; exeplu
    ret

section '.note.GNU-stack'
