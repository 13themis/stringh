#include "s21_string.h"

int g_or_bg_to_string(parsing flags, int *len_buf, char *str, long double number) {
    int len_e = 0;
    char str_e[256];
    if (flags.type == 'g') {
        flags.type = 'e';
    } else {
        flags.type = 'E';
    }
    if (!flags.point || flags.precision < 0)
        flags.precision = 6;
    if (!flags.precision)
        flags.precision = 1;
    flags.precision -= 1;
    int power = e_or_be_to_string(flags, &len_e, str_e, number, flags.sharp + 1);
    if (power < -4 || (power > 0 && flags.precision + 1 <= power + 1)) {
        *len_buf = len_e;
        s21_strcat(str, str_e);
    } else {
        flags.precision -= power;
        f_to_string(flags, &len_e, str_e, number, flags.sharp + 1);
        *len_buf = len_e;
        s21_strcat(str, str_e);
    }
    return 1;
}

char sign_func_whole(long int *number, int *plus, int *space) {
    char c;
    if (*number < 0) {
        *number = *number * (-1);
        c = '-';
        *plus = 1;
        *space = 0;
    } else {
        c = '+';
    }
    return c;
}

char sign_func_subst(long double *number, int *plus, int *space) {
    char c;
    if (*number < 0) {
        *number = *number * (-1);
        c = '-';
        *plus = 1;
        *space = 0;
    } else {
        c = '+';
    }
    return c;
}

int whole_part(long double number, int *buff) {
    long double buf;
    modfl(number, &buf);
    long int buf1 = (long int)buf;
    int buff1[100], i = 0;
    if (buf1) {
        while (buf1) {
            buff1[i] = buf1 % 10;
            buf1 = buf1 / 10;
            i++;
        }
    } else {
        buff1[i] = 0;
        i++;
    }
    for (int j = 0; j < i; j++) {
        buff[j] = buff1[i - j - 1];
    }
    return i;
}

int fraction_part(int shortage, long double number, int *buff, int whole) {
    long double buf, ost = modfl(number, &buf);
    for (int j = 0; j <= shortage; j++) {
        ost = ost * 10.0;
        ost = modfl(ost, &buf);
        buff[whole + j] = (int)buf;
    }
    return 1;
}

int round_number(int *buff, int len, int *buff1, int *whole) {
    int i = len;
    if (buff[len] >= 5) {
        int flag = 1;
        while (flag) {
            i--;
            if (i == -1)
                flag = 0;
            buff[i]++;
            if (buff[i] > 9 && i != 0) {
                buff[i] = 0;
                continue;
            } else {
                flag = 0;
            }
        }
    }
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        for (int j = 1; j < len; j++)
            buff1[j + 1] = buff[j];
        *whole+=1;
    } else {
        for (int j = 0; j < len; j++)
            buff1[j] = buff[j];
    }
    return 1;
}

int str_form(parsing flags, int *buff1, int whole, char c, char *str, int *len_str) {
    for (int j = 0; j < whole; j++) str[j] = buff1[j] + 48;
    if (flags.precision == 0 && flags.sharp == 0) {
        str[whole] = '\0';
        *len_str = whole;
    } else {
        str[whole] = '.';
        for (int j = 0; j < flags.precision; j++) {
            str[whole + 1 + j] = buff1[whole + j] + 48;
        }
        str[whole + flags.precision  + 1] = '\0';
        *len_str = whole + flags.precision + 1;
    }
    int len = *len_str;
    if (flags.plus) {
        s21_memmove(str + 1, str, *len_str);
        str[0] = c;
        str[*len_str + 1] = '\0';
        *len_str += 1;
    } else {
        if (flags.space) {
            s21_memmove(str + 1, str, *len_str);
            str[0] = ' ';
            str[*len_str+ 1] = '\0';
            *len_str += 1;
        }
    }
    return len;
}

int consider_g(char *str, int *len_str, int *len, int from_g_gird) {
    if (from_g_gird == 1) {
        while (str[*len_str - 1] == 48) {
            str[*len_str - 1] = '\0';
            *len_str -= 1;
            *len -= 1;
        }
        if (str[*len_str - 1] == '.') {
            str[*len_str - 1] = '\0';
            *len_str -= 1;
            *len -= 1;
        }
    }
    return 1;
}

int format_f(parsing flags, int len1, int len, char c, char *str, int *len_buf) {
    if (flags.width > len) {
        if (!flags.minus) {
            s21_memmove(str + flags.width - len1, str, len1);
            if (flags.zero) {
                for (int j = 0; j < flags.width - len; j++)
                    str[j] = '0';
                if (flags.plus) {
                    str[0] = c;
                } else if (flags.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < flags.width - len; j++)
                    str[j] = ' ';


                if (flags.plus) {
                    str[flags.width - len - 1] = c;
                }
            }
        } else {
            for (int j = len1; j < flags.width; j++) {
                str[j] = ' ';
            }
        }
        *len_buf = flags.width;
        str[flags.width] = '\0';
    } else {
        *len_buf = len1;
    }
    return 1;
}

int form_power(int power, char e, char *str, int *len_buf) {
    char sign;
    if (power >= 0) {
        sign = '+';
    } else {
        power = power * (-1);
        sign = '-';
    }
    int pow[2];
    if (power >= 10) {
        int i = 0;
        while (i != 2) {
            pow[1 - i] = power % 10;
            power = power / 10;
            i++;
        }
    } else {
        pow[0] = 0;
        pow[1] = power;
    }
    str[*len_buf] = e;
    str[*len_buf + 1] = sign;
    str[*len_buf + 2] = pow[0] + 48;
    str[*len_buf + 3] = pow[1] + 48;
    str[*len_buf + 4] = '\0';
    *len_buf = *len_buf + 4;
    return *len_buf;
}

int e_or_be_to_string(parsing flags, int *len_buf, char *str, long double number, int from_g_gird) {
    long double const_zero = pow(10, -50);
    *len_buf = 0;
    char e = flags.type, sign = sign_func_subst(&number, &flags.plus, &flags.space);
    if (!flags.point || flags.precision < 0)
        flags.precision = 6;
    int power = 0, whole, len;
    long double buf_number = number;
    int buff_1[128];
    int buff_2[128];
    if (number < const_zero) {
        power = 0;
        whole = 1;
        for (int i = 0; i < whole + flags.precision; i++) {
            buff_2[i] = 0;
        }
    } else {
        while (buf_number > 10) {
        buf_number = buf_number / 10;
        power++;
        }
        while (buf_number < 1) {
            buf_number = buf_number * 10;
            power--;
        }
        number = buf_number;
        whole = whole_part(number, buff_2);
        fraction_part(flags.precision, number, buff_2, whole);
        round_number(buff_2, whole + flags.precision, buff_1, &whole);
        if (whole == 2) {
            number = number / 10;
            power++;
        }
        whole = whole_part(number, buff_2);
        fraction_part(flags.precision, number, buff_2, whole);
    }
    len = str_form(flags, buff_1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_gird);
    int len1 = form_power(power, e, str, len_buf);
    len += 4;
    format_f(flags, len1, len, sign, str, len_buf);
    return power;
}

int consider_precision_x(parsing flags, int i, int *precision, char *str) {
    if (flags.precision < 0)
        flags.precision = i;
    if (flags.precision > i) {
        s21_memmove(str + flags.precision - i, str, i);
        for (int j = 0; j < flags.precision - i; j++) {
            str[j] = '0';
        }
    } else if (flags.precision == 0) {
        flags.precision = i;
    } else {
        flags.precision = i;
    }
    int len;
    if (flags.sharp) {
        len = flags.precision + 2;
    } else {
        len = flags.precision;
    }
    if (flags.sharp) {
        s21_memmove(str + 2, str, flags.precision);
        str[0] = '0';
        str[1] = flags.type;
        str[flags.precision + 2] = '\0';
    } else {
        str[flags.precision] = '\0';
    }
    *precision = flags.precision;
    return len;
}

int f_to_string(parsing flags, int *len_buf, char *str, long double number, int from_g_gird) {
    char sign = sign_func_subst(&number, &flags.plus, &flags.space);
    if (!flags.point || flags.precision < 0) flags.precision = 6;
    int buff_1[128];
    int buff_2[128];
    int whole = whole_part(number, buff_1);

    fraction_part(flags.precision, number, buff_1, whole);
    round_number(buff_1, whole + flags.precision, buff_2, &whole);
    int len = str_form(flags, buff_2, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_gird);
    int len1 = *len_buf;
    format_f(flags, len1, len, sign, str, len_buf);
    return 1;
}

char *wstrcat(char *dest, const wchar_t *src) {
    s21_size_t l = s21_strlen(dest);
    int x = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[l + i] = src[i];
        x++;
    }
    dest[l + x] = '\0';
    return dest;
}

int format_x(parsing flags, int len, char *str, int *len_buf) {
        if (flags.width > len) {
        if (!flags.minus) {
            s21_memmove(str + flags.width - len, str, len);
            if (flags.zero) {
                for (int j = 0; j < flags.width - flags.precision; j++)
                    str[j] = '0';
                if (flags.sharp) {
                    str[0] = '0';
                    str[1] = flags.type;
                }
            } else {
                for (int j = 0; j < flags.width - flags.precision; j++)
                    str[j] = ' ';


                if (flags.sharp) {
                    str[flags.width - flags.precision - 1] = flags.type;
                    str[flags.width - flags.precision - 2] = '0';
                }
            }
        } else {
            for (int j = len; j < flags.width; j++) {
                str[j] = ' ';
            }
            str[flags.width] = '\0';
        }
        *len_buf = flags.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int x_or_bx_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args, long unsigned);
    if (flags.leng == 0) {
        number = (unsigned int)number;
    } else if (flags.leng == 'h') {
        number = (short unsigned int)number;
    }
    char data[256];
    int index = convert(flags, number, 16, data, flags.type);
    for (int i = index; i >= 0; i--) str[index - i] = data[i];
    str[index + 1] = '\0';
    int i = index + 1;
    if (flags.point != 0 && flags.precision >= 0) {
        flags.zero = 0;
    }
    if (number == 0) {
        if (flags.point == 0) {
            str[0] = '0';
            str[1] = '\0';
            i = 1;
        }
        flags.sharp = 0;
    }
    int len = consider_precision_x(flags, i, &flags.precision, str);
    format_x(flags, len, str, len_buf);
    return *len_buf;
}

int u_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    if (flags.point && flags.precision >=0) {
        flags.zero = 0;
    }
    long unsigned int number = va_arg(args, long unsigned int);
    if (flags.leng == 0) {
        number = (unsigned int)number;
    } else if (flags.leng == 'h') {
        number = (short unsigned int)number;
    }
    long unsigned int buf = number;
    int i = 0;
    int buff[100];
    if (buf) {
        while (buf) {
            buff[i] = buf % 10;
            buf = buf / 10;
            i++;
        }
    } else {
        if (flags.precision != 0 || flags.point == 0) {
            buff[i] = 0;
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';
    if (flags.precision > i) {
        s21_memmove(str + flags.precision - i, str, i);
        for (int j = 0; j < flags.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        flags.precision = i;
    }
    int len = flags.precision;
    str[flags.precision] = '\0';
    if (flags.width > len) {
        if (!flags.minus) {
            s21_memmove(str + flags.width - len, str, len);
            if (flags.zero) {
                for (int j = 0; j < flags.width - flags.precision; j++)
                    str[j] = '0';
            } else {
                for (int j = 0; j < flags.width - flags.precision; j++)
                    str[j] = ' ';
            }
        } else {
            for (int j = len; j < flags.width; j++) {
                str[j] = ' ';
            }
            str[flags.width] = '\0';
        }
        *len_buf = flags.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int form_number_d(parsing flags, long int number, char *str) {
    int i = 0;
    int buff[100];
    if (number) {
        while (number) {
            buff[i] = number % 10;
            number = number / 10;
            i++;
        }
    } else {
        if (flags.precision < 0 || flags.point == 0) {
            buff[i] = 0;
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';
    return i;
}

int consider_precision_d(parsing flags, int i, char sign, char *str, int *precision) {
    if (flags.precision > i) {
        s21_memmove(str + flags.precision - i, str, i);
        for (int j = 0; j < flags.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        *precision = i;
        flags.precision = i;
    }
    int len;
    if (flags.plus || flags.space) {
        len = flags.precision + 1;
    } else {
        len = flags.precision;
    }
    if (flags.plus) {
        s21_memmove(str + 1, str, flags.precision);
        str[0] = sign;
        str[flags.precision + 1] = '\0';
    } else {
        if (flags.space) {
            s21_memmove(str + 1, str, flags.precision);
            str[0] = ' ';
            str[flags.precision + 1] = '\0';
        } else {
            str[flags.precision] = '\0';
        }
    }
    return len;
}

int format_d(parsing flags, int len, char *str, char sign, int *len_buf) {
    if (flags.width > len) {
        if (!flags.minus) {
            s21_memmove(str + flags.width - len, str, len);
            if (flags.zero) {
                for (int j = 0; j < flags.width - flags.precision; j++)
                    str[j] = '0';
                if (flags.plus) {
                    str[0] = sign;
                } else if (flags.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < flags.width - flags.precision; j++)
                    str[j] = ' ';

                if (flags.plus) {
                    str[flags.width - flags.precision - 1] = sign;
                }
            }
        } else {
            for (int j = len; j < flags.width; j++) {
                str[j] = ' ';
            }
            str[flags.width] = '\0';
        }
        *len_buf = flags.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int d_or_i_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    if (flags.point && flags.precision >= 0)
        flags.zero = 0;
    long int number = va_arg(args, long int);
    if (flags.leng == 0) {
        number = (int)number;
    } else if (flags.leng == 'h') {
        number = (short int)number;
    }
    char sign = sign_func_whole(&number, &flags.plus, &flags.space);
    int i = form_number_d(flags, number, str);
    int len = consider_precision_d(flags, i, sign, str, &flags.precision);
    format_d(flags, len, str, sign, len_buf);
    return 1;
}

int o_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args, long unsigned);
    if (flags.leng == 0) {
        number = (unsigned int)number;
    } else if (flags.leng == 'h') {
        number = (short unsigned int)number;
    }
    char data[256];
    int index = convert(flags, number, 8, data, flags.type);
    for (int i = index; i >= 0; i--)
        str[index - i] = data[i];
    str[index + 1] = '\0';
    int i = index + 1;
    if (flags.point)
        flags.zero = 0;
    if (flags.precision < 0)
        flags.precision = i;
    if (flags.sharp && number != 0) {
        s21_memmove(str + 1, str, i);
        str[0] = '0';
        i++;
        str[i] = '\0';
    } else {
        str[i] = '\0';
    }
    if (flags.precision > i) {
        s21_memmove(str + flags.precision - i, str, i);
        for (int j = 0; j < flags.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        flags.precision = i;
    }
    flags.plus = 0;
    flags.space = 0;
    format_d(flags, flags.precision, str, '+', len_buf);
    return *len_buf;
}

int p_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    int size = 0;
    unsigned long num = va_arg(args, unsigned long);
    char data[256];
    char reverse[256];
    char src[256];
    char tmp[256];
    int index = convert(flags, num, 16, data, 'x');
    for (int i = index; i >= 0; i--) reverse[index - i] = data[i];
    reverse[index + 1] = '\0';
    src[0] = '0';
    src[1] = 'x';
    src[2] = '\0';
    if ((void *)num == s21_NULL) {
        if (flags.point != 0) {
            src[2] = '\0';
        } else {
            src[2] = '0';
            src[3] = '\0';
        }
        }
    s21_strcat(src, reverse);
    if (flags.width) {
        if (flags.width > (int)s21_strlen(src)) {
            size = flags.width - (int)s21_strlen(src);
        }
        if (flags.minus) {
            for (int i = 0; i < (int)s21_strlen(src); i++) {
                str[i] = src[i];
            }
            for (int j = (int)s21_strlen(src); j < flags.width; j++) {
                str[j] = ' ';
            }
        } else {
            for (int i = 0; i < (int)s21_strlen(src); i++) {
                tmp[i] = src[i];
            }
            for (int i = 0; i < size; i++) {
                str[i] = ' ';
            }
            int index = 0;
            for (int i = size; i< size + (int)s21_strlen(tmp); i++) {
                str[i] =  tmp[index];
                index++;
            }
        }
    } else {
        for (int i = 0; i < (int)s21_strlen(src); i++) {
            str[i] = src[i];
        }
    }
        *len_buf = (int)s21_strlen(str);
    return 0;
}

int s_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    if (flags.leng == 0) {
        char *src;
        src = va_arg(args, char *);
        s21_strcat(str, src);
    } else {
        wchar_t *src;
        src = (wchar_t *)va_arg(args, wchar_t *);
        wstrcat(str, src);
        }
        if (flags.precision >= (int)s21_strlen(str) || (flags.precision == 0 && flags.point == 0)
            || flags.precision < 0)
            flags.precision = (int) s21_strlen(str);
        str[flags.precision] = '\0';

        if (flags.width > flags.precision) {
            if (!flags.minus) {
                s21_memmove(str + flags.width - flags.precision, str, flags.precision);
                if (flags.zero) {
                    for (int i = 0; i < flags.width - flags.precision; i++)
                        str[i] = '0';
                } else {
                    for (int i = 0; i < flags.width - flags.precision; i++)
                        str[i] = ' ';
                }
            } else {
                    for (int i = flags.precision; i < flags.width; i++)
                        str[i] = ' ';
            }
            str[flags.width] = '\0';
            *len_buf = flags.width;
        } else {
            *len_buf = flags.precision;
        }
    return 1;
}

char convert_to_bx(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 55;
    }
    return ch;
}

char convert_to_x(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 87;
    }
    return ch;
}

int convert(parsing flags, long unsigned num, long unsigned divider, char *data, char spec) {
    long unsigned rem = num;
    char ch;
    int i = 0;
    if (num) {
        while (num) {
            rem = num % divider;
            num = num / divider;
            if ((spec == 'x') || (spec == 'o')) ch = convert_to_x(rem);
            if  (spec == 'X') ch = convert_to_bx(rem);
            data[i] = ch;
            i++;
        }
    } else {
        if (flags.precision < 0) {
            data[i] = '0';
            i++;
        }
    }
    return i - 1;
}

int n_to_string(va_list args, int length) {
    int *number = va_arg(args, int*);
    *number = length;
    return 1;
}

long double subst_input(parsing flags, va_list args) {
    long double number;
    if (flags.leng == 0) {
        number = (long double) va_arg(args, double);
    } else {
        number = va_arg(args, long double);
    }
    return number;
}

int c_or_pct_to_string(parsing flags, va_list args, int *len_buf, char *str) {
    char c;
    if (flags.type == '%') {
        c = '%';
    } else {
        c = va_arg(args, int);
    }
    if (flags.width == 0)
        flags.width = 1;
    if (flags.minus) {
        str[0] = c;
        for (int i = 1; i < flags.width; i++) {
            str[i] = ' ';
        }
        str[flags.width] = '\0';
    } else {
        if (flags.zero) {
            for (int i = 0; i < flags.width - 1 ; i++)
                str[i] = '0';
        } else {
            for (int i = 0; i < flags.width - 1 ; i++)
                str[i] = ' ';
        }
        str[flags.width - 1] = c;
        str[flags.width] = '\0';
    }

    if (flags.width) {
        *len_buf = flags.width;
    } else {
        *len_buf = 1;
    }
    return 1;
}

int calling_function(parsing flags, va_list args, int *buff_len, char *buff_str, int length) {
    long double number = 0.0;
    int from_g_grid = 0;
    switch (flags.type) {
        case 'c':
            c_or_pct_to_string(flags, args, buff_len, buff_str);
            break;
        case '%':
            c_or_pct_to_string(flags, args, buff_len, buff_str);
            break;
        case 'f':
            number = subst_input(flags, args);
            f_to_string(flags, buff_len, buff_str, number, from_g_grid);
            break;
        case 'd':
            d_or_i_to_string(flags, args, buff_len, buff_str);
            break;
        case 'i':
            d_or_i_to_string(flags, args, buff_len, buff_str);
            break;
        case 'u':
            u_to_string(flags, args, buff_len, buff_str);
            break;
        case 'n':
            n_to_string(args, length);
            break;
        case 'o':
            o_to_string(flags, args, buff_len, buff_str);
            break;
        case 'x':
            x_or_bx_to_string(flags, args, buff_len, buff_str);
            break;
        case 'X':
            x_or_bx_to_string(flags, args, buff_len, buff_str);
            break;
        case 'e':
            number = subst_input(flags, args);
            e_or_be_to_string(flags, buff_len, buff_str, number, from_g_grid);
            break;
        case 'E':
            number = subst_input(flags, args);
            e_or_be_to_string(flags, buff_len, buff_str, number, from_g_grid);
            break;
        case 'g':
            number = subst_input(flags, args);
            g_or_bg_to_string(flags, buff_len, buff_str, number);
            break;
        case 'G':
            number = subst_input(flags, args);
            g_or_bg_to_string(flags, buff_len, buff_str, number);
            break;
        case 'p':
            p_to_string(flags, args, buff_len, buff_str);
            break;
        case 's':
            s_to_string(flags, args, buff_len, buff_str);
            break;
    }
    return 1;
}

int spec(char c) {
    int result = 0;
    int code[16] = {99, 100, 101, 102, 105, 69, 71, 103, 111, 115, 117, 88, 120, 110, 112, 37};
    for (int i = 0; i < 16; i++) {
        if (c == code[i]) {
            result = code[i];
        }
    }
    return result;
}

int leng(char c) {
    int result = 0;
    if (c == 'L' || c == 'l' || c == 'h') {
        result = 1;
    }
    return result;
}

int form_number(const char *str, int *len) {
    int factor = 0;
    int len1 = 0;
    while (def_number(*str)) {
        factor = (factor * 10) + (*str) - 48;
        str++;
        len1++;
    }
    *len = len1;
    return factor;
}

int def_number(char c) {
    int result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
    }
    return result;
}

int s21_ia_sprintf(char *output_str, const char *input_str, va_list args) {
    char buff_str[256];
    int buff_len;
    int length = 0;

    while (*input_str) {
        if (*input_str != '%') {
            *(output_str + length) = *input_str;
            length++;
            input_str++;
            continue;
        }

        parsing flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        input_str++;
        int flag = 1;
        buff_len = 0;
        for (int i = 0; i < 256; i++) buff_str[i] = '\0';

        while (flag) {
            if (*input_str == ' ' && flags.plus == 0) flags.space = 1;
            if (*input_str == '0' && flags.width == 0 && flags.point == 0) flags.zero = 1;
            if (*input_str == '+') {
                flags.plus = 1;
                flags.space = 0;
            }
            if (*input_str == '#') flags.sharp = 1;
            if (*input_str == '.') {
                flags.point = 1;
                input_str++;
                if (*input_str == '*') {
                    flags.precision = va_arg(args, int);
                    input_str++;
                } else {
                    int len = 0;
                    flags.precision = form_number(input_str, &len);
                    input_str = input_str + len;
                }
                continue;
            }
            if (*input_str == '*') {
                flags.star = 1;
                flags.width = va_arg(args, int);
                if (flags.width < 0) {
                    flags.width = -flags.width;
                    flags.minus = 1;
                    flags.zero = 0;
                    }
            }
            if (def_number(*input_str)) {
                if (flags.star == 1) {
                    flags.width = 0;
                } else {
                    int len = 0;
                    flags.width = form_number(input_str, &len);
                    input_str = input_str + len;
                }
                continue;
            }
            if (leng(*input_str)) flags.leng = *input_str;
            if (*input_str == '-') {
                flags.minus = 1;
                flags.zero = 0;
            }
            if (spec(*input_str)) {
                flags.type = *input_str;
                flag = 0;
            }
            input_str++;
        }
        calling_function(flags, args, &buff_len, buff_str, length);
        s21_memmove(output_str + length, buff_str, buff_len);
        length += buff_len;
    }
    *(output_str + length) = '\0';
    return length;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list(input_args);
    va_start(input_args, format);
    int i = s21_ia_sprintf(str, format, input_args);
    va_end(input_args);
    return i;
}
