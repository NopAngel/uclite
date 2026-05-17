.global __sigrestore
.type __sigrestore, @function

__sigrestore:
    # x86_64 syscall (ASSEMBLY IS THE WORST PROGRAMMAING LANGUAGEJJHAFDHA)
    movq $15, %rax
    syscall
