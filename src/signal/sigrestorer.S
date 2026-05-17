.global __sigrestore
.type __sigrestore, @function

__sigrestore:
    # En x86_64, la syscall para retornar de una señal (rt_sigreturn) es la número 15
    movq $15, %rax
    syscall
