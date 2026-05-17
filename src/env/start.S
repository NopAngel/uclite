.global _start
.intel_syntax noprefix

.extern __environ
.extern test_main

_start:
    # [rsp]     = argc
    # [rsp + 8] = argv[0]
    
    mov rdi, [rsp]       
    lea rsi, [rsp + 8]   

    mov rax, rdi
    shl rax, 3           # rax = argc * 8
    lea rdx, [rsi + rax + 8] # rdx = argv + (argc * 8) + 8 

    mov [__environ + rip], rdx

    call test_main

    mov rdi, 0
    mov rax, 60          # sys_exit
    syscall
