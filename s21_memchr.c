#include "s21_string.h"

void * s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *PTR = (unsigned char*) str;
    unsigned char *Find = s21_NULL;

    while ((str != s21_NULL) && (n--)) {
        if (*PTR != (unsigned char) c) {
            PTR++;
        } else {
            Find = PTR;
            break;
        }
    }
    return Find;
}
