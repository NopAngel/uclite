
#include "../../arch/x86_64/syscall.h"

void _exit(int status) {
    __syscall1(60, status); 
    while(1); 
}
