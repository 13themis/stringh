#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    while (*str != (char)c) {
        if (*str == '\0') {
            str = s21_NULL;
            break;
        }
        str++;
    }
    return (char *)str;
}
