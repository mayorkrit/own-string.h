#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    char *qwe = str;
    for (s21_size_t i = 0; i < n && *qwe != '\0'; i++) {
        *qwe = (unsigned char)c;
        qwe += 1;
    }
    return str;
}
