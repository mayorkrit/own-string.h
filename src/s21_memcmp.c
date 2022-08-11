#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *p = (unsigned char *)str1;
    unsigned char *q = (unsigned char *)str2;

    while (n > 0) {
        if (*p != *q)
            return (*p - *q);
        n--;
        p++;
        q++;
    }
    return 0;
}

