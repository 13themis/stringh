#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char *p = dest;
    const char *s = src;
    s21_size_t i = 0;
    int null_flag = 0;
    while (null_flag == 0 && (i < n)) {
        p[i] = s[i];
        null_flag = (src[i] == '\0');
        i++;
    }
    return dest;
}
