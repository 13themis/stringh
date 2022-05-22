#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  char *s = (char *)src;
  unsigned char tmp[n];
  s21_size_t i;
  for (i = 0; i < n; i++) {
    *(tmp + i) = *(s + i);
  }
  for (i = 0; i < n; i++) {
    *(d + i) = *(tmp + i);
  }
  return dest;
}
