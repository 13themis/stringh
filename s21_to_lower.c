#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *tmp = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t n = s21_strlen(str);
    tmp = (char *)malloc((n + 1) * sizeof(char));
    s21_size_t i = 0;
    if (tmp) {
      while (i <= n) {
        tmp[i] = (str[i] >= 65 && str[i] <= 91) ? str[i] + 32 : str[i];
        i++;
      }
      tmp[n] = '\0';
    }
  }
  return tmp;
}
