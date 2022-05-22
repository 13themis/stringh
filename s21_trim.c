#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  static char *tmp;
  void *res = s21_NULL;
  s21_size_t n = s21_strlen(src);
  tmp = (char *)malloc((n + 1) * sizeof(char));
  if (tmp) {
    s21_strcpy(tmp, src);
    for (int i = (int)s21_strlen(tmp) - 1;
         i >= 0 && s21_strchr(trim_chars, tmp[i]) != s21_NULL; i--) {
      tmp[i] = '\0';
    }
    while (tmp[0] != '\0' && s21_strchr(trim_chars, tmp[0]) != s21_NULL) {
      s21_memmove(&tmp[0], &tmp[1], s21_strlen(tmp));
    }
    res = tmp;
  }
  return res;
}
