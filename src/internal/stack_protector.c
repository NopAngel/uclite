void _exit(int status);

void __stack_chk_fail(void) {
    _exit(139); 
}
