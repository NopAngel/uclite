#ifndef UCLITE_TIME_H
#define UCLITE_TIME_H

#include <stddef.h>

// IDs de los relojes del sistema en Linux
#define CLOCK_REALTIME           0  // El reloj de pared del sistema (hora real del mundo)
#define CLOCK_MONOTONIC          1  // Reloj que nunca retrocede (perfecto para medir cuánto tarda un código)

// Tipo de datos estándar para almacenar el tiempo Unix
typedef long time_t;

// Estructura que exige el Kernel de Linux para escupir el tiempo de alta precisión
struct timespec {
    time_t tv_sec;   // Segundos transcurridos desde el 01-Ene-1970
    long   tv_nsec;  // Nanosegundos adicionales dentro de este segundo
};

// Prototipo de la función estándar de uclite
int clock_gettime(int clock_id, struct timespec *tp);

#endif
