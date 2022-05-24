#include "s21_string.h"

int delim_flag(char c, const char *delim) {
  int res = 0;
  int end =0;

  while (*delim != '\0' && end == 0) {
    if (c == *delim) {
      res = 1;
      end = 1;
    } else {
      delim++;
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *begin_str = s21_NULL;
  char *end_str = (char *) s21_NULL;

  if (str != s21_NULL || begin_str != s21_NULL) {
    if (str == s21_NULL) {
      str = begin_str;
    }
    if (*str != '\0') {
      while (delim_flag(*str, delim) == 1) {
        str++;
      }
      if (*str != '\0') {
        end_str =str;
        int end = 0;
        while (end != 1) {
          if (*str == '\0') {
            begin_str = str;
            end = 1;
          } else if (delim_flag(*str, delim) == 1) {
            *str = '\0';
            begin_str = str + 1;
            end = 1;
          } else {
            str++;
          }
        }
      }
    }
  }
  return end_str;
}
