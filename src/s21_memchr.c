#include "s21_string.h"
#include <stdio.h>

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char*)str;
    unsigned char *isCharFind = s21_NULL;
    while ((str!= s21_NULL) && (n--)) {
        if ( *p != (unsigned char)c ) {
            p++;
        } else {
            isCharFind = p;
            break;
        }
    }
    return isCharFind;
}
