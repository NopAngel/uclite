.global __syscall6          # 🚀 DOS guiones bajos para que C la encuentre
.intel_syntax noprefix

__syscall6:                 # 🚀 DOS guiones bajos aquí también
    mov rax, rdi    
    mov rdi, rsi    
    mov rsi, rdx    
    mov rdx, rcx    
    mov r10, r8     
    mov r8, r9      
    mov r9, [rsp+8] 
    
    syscall         
    ret
