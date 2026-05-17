#include <signal.h>
#include <syscall.h>
#include <errno.h>


extern void __sigrestore(void);


#define SA_RESTORER 0x04000000

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) {
    struct sigaction kact;

    if (act) {
        
        kact = *act;
        
        
        kact.sa_restorer = __sigrestore; 
        kact.sa_flags |= SA_RESTORER;    
        
        act = &kact;
    }

    
    long ret = __syscall4(13, signum, (long)act, (long)oldact, 8);
    
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    
    return 0;
}
