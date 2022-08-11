#include "s21_string.h"

char* s21_strchr(const char *str, int c) {
    char *str2 = (char*) str;
    while (1) {
        if (*str2 == c) {
            break;
        } else if (*str2 == '\0') {
            str2 = s21_NULL;
            break;
        }
        str2++;
    }
    return str2;
}
