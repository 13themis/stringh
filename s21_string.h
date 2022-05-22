#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <wchar.h>
#include <math.h>

#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

#if defined(__APPLE__)
#define MAX_NUMBER 107
extern char *_error[107];
#elif defined(__linux__)
#define MAX_NUMBER 134
extern char *_error[134];
#endif
extern char undefiend_error[100];

s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strerror(int errnum);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memset(void *dest, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *src);
char *s21_strtok(char *str, const char *delim);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
int s21_sprintf(char *buff_str, const char *format, ...);

typedef struct {
    int plus;
    int sharp;
    int minus;
    int zero;
    int space;
    int leng;
    int width;
    int point;
    int precision;
    int type;
    int star;
} parsing;

int s21_ia_sprintf(char *output_str, const char *input_str, va_list args);
int calling_function(parsing flags, va_list args, int *buff_len, char *buff_str, int length);
int c_or_pct_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
int d_or_i_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
int e_or_be_to_string(parsing flags, int *buff_len, char *buff_str, long double number, int from_g_gird);
int f_to_string(parsing flags, int *buff_len, char *buff_str, long double number, int from_g_gird);
int g_or_bg_to_string(parsing flags, int *buff_len, char *buff_str, long double number);
int o_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
int p_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
int n_to_string(va_list args, int length);
int s_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
int u_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
int x_or_bx_to_string(parsing flags, va_list args, int *buff_len, char *buff_str);
char sign_func_whole(long int *number, int *plus, int *space);
char sign_func_subst(long double *number, int *plus, int *space);
int whole_part(long double number, int *buff);
int fraction_part(int shortage, long double number, int *buff, int whole);
int round_number(int *buff, int len, int *buff1, int *whole);
int str_form(parsing flags, int *buff1, int whole, char c, char *buff_str, int *len_str);
int consider_g(char *buff_str, int *len_str, int *len, int from_g_gird);
int format_d(parsing flags, int len, char *buff_str, char sign, int *buff_len);
int format_f(parsing flags, int len1, int len, char c, char *buff_str, int *buff_len);
int format_x(parsing flags, int len, char *buff_str, int *buff_len);
int form_power(int power, char e, char *buff_str, int *buff_len);
int form_number_d(parsing flags, long int number, char *buff_str);
int consider_precision_x(parsing flags, int i, int *precision, char *buff_str);
int consider_precision_d(parsing flags, int i, char sign, char *buff_str, int *precision);
int convert(parsing flags, long unsigned num, long unsigned divider, char *data, char spec);
long double subst_input(parsing flags, va_list args);
int spec(char c);
int leng(char c);
int form_number(const char *buff_str, int *len);
int def_number(char c);
char *wstrcat(char *dest, const wchar_t *src);
char convert_to_bx(int value);
char convert_to_x(int value);


#endif  // SRC_S21_STRING_H_
