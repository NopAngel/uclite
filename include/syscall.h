#ifndef UCLITE_SYSCALL_H
#define UCLITE_SYSCALL_H

long __syscall6(long num, long a1, long a2, long a3, long a4, long a5, long a6);

#define __syscall0(num) \
    __syscall6((num), 0, 0, 0, 0, 0, 0)

#define __syscall1(num, a1) \
    __syscall6((num), (long)(a1), 0, 0, 0, 0, 0)

#define __syscall2(num, a1, a2) \
    __syscall6((num), (long)(a1), (long)(a2), 0, 0, 0, 0)

#define __syscall3(num, a1, a2, a3) \
    __syscall6((num), (long)(a1), (long)(a2), (long)(a3), 0, 0, 0)

#define __syscall4(num, a1, a2, a3, a4) \
    __syscall6((num), (long)(a1), (long)(a2), (long)(a3), (long)(a4), 0, 0)

#define __syscall5(num, a1, a2, a3, a4, a5) \
    __syscall6((num), (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5), 0)

#endif
