.global __uclite_clone
.type __uclite_clone, @function

# __uclite_clone(fn, stack_top, flags, arg)
# args for x86_64: rdi=fn, rsi=stack_top, rdx=flags, rcx=arg
__uclite_clone:

    subq $16, %rsi
    movq %rcx, 8(%rsi)   # save 'arg' in threads
    movq %rdi, 0(%rsi)   # save 'fn' in threads

    # sys_clone args: rdi=flags, rsi=new_stack
    movq %rdx, %rdi     
                         
    movq $56, %rax       
    syscall


    testq %rax, %rax
    jnz .father_return   

    popq %rax            
    popq %rdi          
    
    call *%rax           

    movq %rax, %rdi     
    movq $60, %rax       # sys_exit
    syscall

.father_return:
    ret
