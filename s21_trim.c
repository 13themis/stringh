#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *s = (char *)src;
  char *tc = (char *)trim_chars;
  char *result = s21_NULL;
  if (tc == s21_NULL) {
      trim_chars = " ";
      tc = (char *)trim_chars;
    }
  if (s != s21_NULL) {
      s21_size_t len_src = s21_strlen(src);
      s21_size_t len_trim = s21_strlen(trim_chars);
      int arr_i = 0;

      result = (char *)malloc((len_src + 1) * sizeof(char));
      if (s21_NULL == result) { exit(0); }
      result[len_src] = '\0';

      int start_i = start(s, tc, len_src, len_trim);
      int end_i = end(s, tc, len_src, len_trim);

      for (int i = start_i; i < end_i; i++) {
          result[arr_i] = src[i];
          arr_i++;
        }
      result[arr_i] = '\0';
    }
  return (char *)result;
}

int start(const char *s, const char *tc, s21_size_t len_src,
  s21_size_t len_trim) {
  int start_i = 0, f_end = 0;
  s21_size_t i = 0;
  while (i < len_src && f_end == 0) {
      s21_size_t j = 0;
      while (j < len_trim && s[i] != tc[j]) {
          j++;
      }
      if (s[i] == tc[j]) {
          start_i++;
          i++;
      } else {
          f_end = 1;
      }
  }
  return start_i;
}

int end(const char *s, const char *tc, s21_size_t len_src, s21_size_t len_trim) {
  int end_i = len_src, f_end = 0;
  int i = len_src - 1;
  while (i > -1 && f_end == 0) {
    s21_size_t j = 0;
    while (j < len_trim && s[i] != tc[j]) {
      j++;
    }
    if (s[i] == tc[j]) {
      end_i--;
      i--;
    } else {
      f_end = 1;
    }
  }
  return end_i;
}
