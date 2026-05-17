#ifndef UCLITE_LOCALE_H
#define UCLITE_LOCALE_H

#define LC_ALL      6

struct lconv {
    char *decimal_point;
    char *thousands_sep;
};

char *setlocale(int category, const char *locale);

#endif
