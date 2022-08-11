#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t i = 0;
    int key = 0;
    while (i < n && (str1[i] != '\0' || str2[i] != '\0') && key == 0) {
        key = str1[i] - str2[i];
        i++;
    }
    return key;
}
