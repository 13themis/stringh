#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    int flag = 0;
    char *res = s21_NULL;
    while (*str1 != '\0' && !flag) {
        for (int i = 0; i < (int)s21_strlen(str2); i++) {
            if (*str1 == *(str2 + i)) {
                flag = 1;
                res = (char *)str1;
            }
        }
        str1++;
    }
    return res;
}
