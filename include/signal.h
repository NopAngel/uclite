#ifndef UCLITE_SIGNAL_H
#define UCLITE_SIGNAL_H

#include <stddef.h>

#define SIGHUP    1
#define SIGINT    2   // Ctrl+C
#define SIGQUIT   3
#define SIGILL    4
#define SIGTRAP   5
#define SIGABRT   6
#define SIGFPE    8   // Mathematical error (e.g., division by zero)
#define SIGKILL   9   
#define SIGSEGV   11  
#define SIGTERM   15  
typedef void (*__sighandler_t)(int);
#define SIG_DFL ((__sighandler_t)0)  
#define SIG_IGN ((__sighandler_t)1)  

struct sigaction {
    __sighandler_t sa_handler;
    unsigned long sa_flags;
    void (*sa_restorer)(void); 
    unsigned long sa_mask;     
};


int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

#endif
