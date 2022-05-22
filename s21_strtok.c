#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *res = s21_NULL;
  s21_size_t i = 0;
  while (str[i] != '\0') {
    for (s21_size_t j = 0; j < s21_strlen(delim); j++) {
      if (str[i] == delim[j]) {
        str[i] = '\0';
      }
    }
    i++;
  }
  if (*str != '\0') {
    res = str;
  }
  return res;
}

