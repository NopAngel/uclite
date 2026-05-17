#include <fenv.h>

int fesetround(int round) {
    unsigned int mxcsr;
    
    
    __asm__ __volatile__("stmxcsr %0" : "=m"(mxcsr));
    
    
    mxcsr &= ~0x6000;
    
    
    mxcsr |= (round << 3); 
    
    
    __asm__ __volatile__("ldmxcsr %0" : : "m"(mxcsr));
    
    return 0;
}
