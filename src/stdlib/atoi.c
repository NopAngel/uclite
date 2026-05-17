#include <stdlib.h>

int atoi(const char *str) {
    if (!str) return 0;

    int res = 0;
    int sign = 1;

    
    while (*str == ' ' || (*str >= 9 && *str <= 13)) {
        str++;
    }

    
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    
    while (*str >= '0' && *str <= '9') {
        
        res = res * 10 + (*str - '0');
        str++;
    }

    return sign * res;
}
