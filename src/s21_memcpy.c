#include "s21_string.h"

// func №3
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *destaddr = (char*) dest;
  const char *srcaddr = (char*) src;

  for (s21_size_t i = 0; i < n; i++) {
      destaddr[i] = srcaddr[i];
    }
    return destaddr;
}

