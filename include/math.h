#ifndef UCLITE_MATH_H
#define UCLITE_MATH_H

double sqrt(double x);

double fabs(double x);

typedef struct {
    double real;
    double imag;
} double_complex;

// Sum of complex numbers: (a + bi) + (c + di)
double_complex cadd(double_complex a, double_complex b);

#endif
