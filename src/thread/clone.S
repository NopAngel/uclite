.global __uclite_clone
.type __uclite_clone, @function

# __uclite_clone(fn, stack_top, flags, arg)
# Argumentos en x86_64: rdi=fn, rsi=stack_top, rdx=flags, rcx=arg
__uclite_clone:
    # 1. Dejamos espacio en el nuevo stack e inyectamos el argumento (arg) y la función (fn)
    # para que el hilo nuevo los tenga guardados en su propia memoria.
    subq $16, %rsi
    movq %rcx, 8(%rsi)   # Guarda 'arg' en el stack del hilo
    movq %rdi, 0(%rsi)   # Guarda 'fn' en el stack del hilo

    # 2. Acomodamos los registros para la syscall 'sys_clone' (Número 56)
    # Argumentos de sys_clone: rdi=flags, rsi=new_stack
    movq %rdx, %rdi      # Mueve flags a rdi
                         # rsi ya tiene el stack_top alineado
    movq $56, %rax       # Número de syscall para sys_clone
    syscall

    # 3. ¡Bifurcación! El kernel regresa aquí DOS VECES:
    # Si rax == 0, significa que somos el HILO NUEVO (Hijo).
    # Si rax > 0, somos el HILO PRINCIPAL (Padre, regresa el PID del hilo).
    testq %rax, %rax
    jnz .padre_retorna   # El padre salta al final y regresa

    # --- CÓDIGO DEL HILO NUEVO ---
    # Sacamos de nuestro stack los punteros que guardamos en el paso 1
    popq %rax            # rax ahora tiene la función 'fn'
    popq %rdi            # rdi ahora tiene el argumento 'arg'
    
    call *%rax           # ¡Saltamos a ejecutar tu función en C!

    # Si la función en C termina, salimos del hilo usando sys_exit (Syscall 60)
    movq %rax, %rdi      # Pasamos el valor de retorno como status
    movq $60, %rax       # sys_exit
    syscall

.padre_retorna:
    ret
