#include "s21_string.h"

void * s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *PTR = (unsigned char*) str;
    unsigned char *Find = NULL;

    while ((str != NULL) && (n--)) {
        if (*PTR != (unsigned char) c) {
            PTR++;
        } else {
            Find = PTR;
            break;
        }
    }
    return Find;
}
