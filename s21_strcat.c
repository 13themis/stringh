#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    char *temp = dest;
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) != '\0') {
    }
    return temp;
}
