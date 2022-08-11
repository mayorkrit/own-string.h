#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t needle_len = s21_strlen(needle);
    s21_size_t hay_len = s21_strlen(haystack), flag = 0;
    for (s21_size_t i = 0; (i + needle_len) <= hay_len; i++) {
        for (s21_size_t j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = 0;
                break;
            }
            flag = 1;
        }
        if (flag) {
            return (char *)haystack + i;
        }
    }
    return needle_len == 0 ? (char *)haystack: s21_NULL;
}
