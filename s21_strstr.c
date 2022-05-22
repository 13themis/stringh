#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t lens1;
    s21_size_t lens2;
    lens2 = s21_strlen(needle);
    if (!lens2) {
        return (char *)haystack;
    }
    lens1 = s21_strlen(haystack);
    while (lens1 >= lens2) {
        lens1--;
        if (!s21_memcmp(haystack, needle, lens2)) {
            return (char *)haystack;
        }
        haystack++;
    }
    return s21_NULL;
}
