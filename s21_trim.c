#include "s21_string.h"

int begin(const char *tmp, const char *z, s21_size_t len_src,
          s21_size_t len_trim) {
  int begin_position = 0;
  int flag = 0;
  s21_size_t i = 0;
  while (i < len_src && !flag) {
    s21_size_t j = 0;
    for (; j < len_trim && tmp[i] != z[j]; j++) {
    }
    if (tmp[i] == z[j]) {
      i++;
      begin_position++;
    } else {
      flag = 1;
    }
  }
  return begin_position;
}

int end(const char *tmp, const char *z, s21_size_t len_src,
        s21_size_t len_trim) {
  int end_position = len_src;
  int flag = 0;
  int i = len_src - 1;
  while (i >= 0 && !flag) {
    s21_size_t j = 0;
    for (; j < len_trim && tmp[i] != z[j]; j++) {
    }
    if (tmp[i] == z[j]) {
      i--;
      end_position--;
    } else {
      flag = 1;
    }
  }
  return end_position;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *tmp = (char *)src;
  char *z = (char *)trim_chars;
  char *res = s21_NULL;
  if (z == s21_NULL) {
    trim_chars = " ";
    z = (char *)trim_chars;
  }
  if (tmp != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_trim = s21_strlen(trim_chars);
    res = (char *)malloc((len_src + 1) * sizeof(char));
    if (res != s21_NULL) {
      res[len_src] = '\0';
      int b = begin(tmp, z, len_src, len_trim);
      int e = end(tmp, z, len_src, len_trim);
      int i = 0;
      while (b < e) {
        res[i++] = src[b++];
      }
      res[i] = '\0';
    }
  }
  return res;
}
