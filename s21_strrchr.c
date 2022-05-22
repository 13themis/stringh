#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    char *find_char = s21_NULL;
    do {
        if (*str == (char)c) {
            find_char = (char *)str;
        }
    } while (*str++);
    return find_char;
}
