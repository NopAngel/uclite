.global _start
.intel_syntax noprefix

.extern __environ
.extern test_main

_start:
    # 🧠 Al arrancar:
    # [rsp]     = argc
    # [rsp + 8] = argv[0]
    
    mov rdi, [rsp]       # Primer argumento para C: argc
    lea rsi, [rsp + 8]   # Segundo argumento para C: argv

    # El entorno (envp) está justo después de argv. 
    # Multiplicamos argc por 8 (tamaño de un puntero) y saltamos el NULL final.
    mov rax, rdi
    shl rax, 3           # rax = argc * 8
    lea rdx, [rsi + rax + 8] # rdx = argv + (argc * 8) + 8 -> ¡Aquí empieza envp!

    # 🚀 CORREGIDO: Usamos direccionamiento relativo a RIP para soportar PIE
    mov [__environ + rip], rdx

    # Ahora sí, saltamos seguros a nuestro código en C pasándole argc y argv por registros
    call test_main

    # Si por alguna razón test_main regresa, cortamos el proceso de golpe
    mov rdi, 0
    mov rax, 60          # sys_exit
    syscall
