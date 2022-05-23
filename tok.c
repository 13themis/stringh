char *s21_strtok(char *str, const char *delim) {
    static char *start_string = s21_NULL;
    char *ctrl_str = (char *)s21_NULL;

    if (str != s21_NULL || start_string != s21_NULL) {
        if (str == s21_NULL) { str = start_string; }
        if (*str != '\0') {
            while (delim_check(*str, delim) == 1) {
                str++;
            }

            if (*str != '\0') {
                ctrl_str = str;
                int f_end = 0;
                while (f_end != 1) {
                    if (*str == '\0') {
                        start_string = str;
                        f_end = 1;
                    } else if (delim_check(*str, delim) == 1) {
                        *str = '\0';
                        start_string = str + 1;
                        f_end = 1;
                    } else {
                        str++;
                    }
                }
            }
        }
    }
    return ctrl_str;
}

int delim_check(char c, const char *delim) {
    int res = 0, f_end = 0;

    while (*delim != '\0' && f_end == 0) {
        if (c == *delim) {
            res = 1;
            f_end = 1;
        } else {
            delim++;
        }
    }
    return res;
}