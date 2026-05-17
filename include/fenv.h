#ifndef UCLITE_FENV_H
#define UCLITE_FENV_H

// Standard CPU rounding modes
#define FE_TONEAREST  0x0000
#define FE_DOWNWARD   0x0400
#define FE_UPWARD     0x0800
#define FE_TOWARDZERO 0x0C00

// Define the type for the FPU control register
typedef unsigned int fenv_t;

// Change the hot CPU rounding mode
int fesetround(int round);

#endif
