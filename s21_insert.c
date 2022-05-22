#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *tmp = s21_NULL;
  if (str != s21_NULL && src != s21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t a = s21_strlen(str);
    s21_size_t b = s21_strlen(src);
    tmp = (char *)malloc((a + b + 1) * sizeof(char));
    if (tmp) {
      s21_size_t i = 0;
      while (*src || *str) {
        if (i == start_index && *str) {
          start_index++;
          tmp[i] = *str++;
        } else {
          tmp[i] = *src++;
        }
        i++;
      }
      tmp[i] = '\0';
    }
  }
  return tmp;
}
