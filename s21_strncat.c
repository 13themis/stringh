#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t c = s21_strlen(dest);
  s21_size_t i = 0;
  while (i < n && src[i]) {
    dest[c++] = src[i++];
  }
  dest[c] = '\0';
  return dest;
}
