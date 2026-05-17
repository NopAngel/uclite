#include <errno.h>

static int __local_errno = 0;

int *__errno_location(void) {
    return &__local_errno;
}
