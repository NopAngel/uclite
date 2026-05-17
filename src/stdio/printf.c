#include <stdio.h>
#include <string.h>
#include <stdarg.h>

long write(int fd, const void *buf, unsigned long count);


static int print_number(long num, int is_signed) {
    char buffer[32];
    int i = 0;
    int written = 0;
    unsigned long n;

    
    memset(buffer, 0, sizeof(buffer));

    
    if (is_signed && num < 0) {
        write(1, "-", 1);
        written++;
        n = -num;
    } else {
        n = (unsigned long)num;
    }

    
    if (n == 0) {
        write(1, "0", 1);
        return written + 1;
    }

    
    while (n > 0) {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    
    for (int j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
        written++;
    }

    return written;
}

int printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int written = 0;
    
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == '\0') break;
            
            if (*format == 'c') {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
                written++;
            } 
            else if (*format == 's') {
                char *s = va_arg(args, char *);
                if (!s) s = "(null)";
                int len = strlen(s);
                write(1, s, len);
                written += len;
            } 
            
            else if (*format == 'd' || *format == 'i') {
                int val = va_arg(args, int);
                written += print_number(val, 1);
            }
            
            else if (*format == 'u') {
                unsigned int val = va_arg(args, unsigned int);
                written += print_number(val, 0);
            }
            else if (*format == '%') {
                write(1, "%", 1);
                written++;
            }
        } else {
            write(1, format, 1);
            written++;
        }
        format++;
    }
    
    va_end(args);
    return written;
}
