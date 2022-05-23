#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *full_stack;
  static char *del;
  static s21_size_t ind;
  static nt_null;
  static chr;
  if (str) {
    chr = 1;
    ind = 0;
    nt_null = 0;
    full_stack = str + s21_strlen(str);
    del = str +s21_strspn(str, delim);
  }
  char *res = s21_NULL;

  if (!(del >= full_stack || '\0')) {
    int i = 0;
    int nol_d = 1;
    for (i; del[i]; i++) {
      s21_size_t tap = s21_strspn(del + i, delim);
      if (tap) {
        nol_d = 0;
        for (s21_size_t j = i; j < i + tap; j++) {
          del[j] = '\0';
          ind = tap + i;
          break;
        }
      }
      if (chr == 1 && nol_d) nt_null = 1;
      res = del;
      del += ind;
    }
  }
  
  ++chr;
  return res;
}



// while (str[i] != '\0') {
  //   for (s21_size_t j = 0; j < s21_strlen(delim); j++) {
  //     if (str[i] == delim[j]) {
  //       str[i] = '\0';
  //     }
  //   }
  //   i++;
  // }
  // if (*str != '\0') {
  //   res = str;
  // }