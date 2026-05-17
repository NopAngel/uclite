#include <math.h>

double sqrt(double x) {
    double res;
    
    __asm__ __volatile__("sqrtsd %1, %0" : "=x"(res) : "x"(x));
    return res;
}

double fabs(double x) {
    
    if (x < 0.0) return -x;
    return x;
}

double_complex cadd(double_complex a, double_complex b) {
    double_complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}
