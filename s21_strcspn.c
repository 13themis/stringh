#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t n = 0;
  while (!s21_strchr(str2, *str1) && *str1++) {
    n++;
  }
  return n;
}
