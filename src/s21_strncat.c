#include "s21_string.h"

char * s21_strncat(char *dest, const char *src, s21_size_t n) {
    int str_main_len = s21_strlen(dest);
    for (s21_size_t counter = 0; counter < n; counter += 1) {
    dest[str_main_len + counter] = src[counter];
    dest[str_main_len + counter + 1] = '\0';
    }
return dest;
}
