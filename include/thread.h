#ifndef UCLITE_THREAD_H
#define UCLITE_THREAD_H

#include <stddef.h>

// Banderas críticas de Linux para la syscall clone
#define CLONE_VM       0x00000100  // Compartir el mismo espacio de direcciones virtuales (RAM)
#define CLONE_FS       0x00000200  // Compartir información del sistema de archivos
#define CLONE_FILES    0x00000400  // Compartir descriptores de archivos (open, close, etc.)
#define CLONE_SIGHAND  0x00000800  // Compartir manejadores de señales (como tu Ctrl+C)
#define CLONE_THREAD   0x00010000  // Meter al nuevo proceso en el mismo grupo de hilos

// Tipo de datos para la función que ejecutará el hilo
typedef int (*thread_func_t)(void *);

// Prototipo de nuestra función de creación de hilos estándar de uclite
int thread_create(thread_func_t fn, void *arg);

#endif
