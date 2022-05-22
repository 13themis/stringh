#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *string_l1 = (char *)str1;
  char *string_l2 = (char *)str2;
  int ptr = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if ((ptr = string_l1[i] - string_l2[i]) != 0) {
      break;
    }
  }
  return ptr;
}
