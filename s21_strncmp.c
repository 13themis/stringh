#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    if (n) {
        while (n-- - 1 && *str1 && *str1 == *str2) {
            str1++, str2++;
        }
    }

    return n ? (*str1 - *str2) : 0;
}
