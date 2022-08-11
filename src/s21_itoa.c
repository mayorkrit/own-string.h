#include "s21_string.h"

void s21_itoa(long int value, char *result, int base) {
    char* ptr = result, *ptr1 = result, tmp_char;
    long int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        // zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + \
        (tmp_value - value * base)];
    } while ( value );

    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return;
}
