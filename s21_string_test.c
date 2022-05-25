#include "s21_string.h"
#include <check.h>

// memchr I
START_TEST(s21_memchr_test_1) {
  ck_assert_pstr_eq(s21_memchr("1234567890", '4', 10),
                    memchr("1234567890", '4', 10));
}
END_TEST

// memchr II
START_TEST(s21_memchr_test_2) {
  ck_assert_pstr_eq(s21_memchr("Hello World!", 'W', 13),
                    memchr("Hello World!", 'W', 13));
}
END_TEST

// memchr III
START_TEST(s21_memchr_test_3) {
  ck_assert_pstr_eq(s21_memchr("Hello World!", '!', 13),
                    memchr("Hello World!", '!', 13));
}
END_TEST

// memchr IV
START_TEST(s21_memchr_test_4) {
  ck_assert_pstr_eq(s21_memchr("Hello World!\n\0", 'l', 15),
                    memchr("Hello World!\n\0", 'l', 15));
}
END_TEST

// memchr V
START_TEST(s21_memchr_test_5) {
  ck_assert_pstr_eq(s21_memchr("Hello_World!", ' ', 12),
                    memchr("Hello_World!", ' ', 12));
}
END_TEST

// memchr VI
START_TEST(s21_memchr_test_6) {
  ck_assert_pstr_eq(s21_memchr("Hello World!", ' ', 1),
                    memchr("Hello world!", ' ', 1));
}
END_TEST

// memchr VII
START_TEST(s21_memchr_test_7) {
  ck_assert_pstr_eq(s21_memchr("a\n\0", 'H', 3), memchr("a\n\0", 'H', 3));
}
END_TEST

// memchr VIII
START_TEST(s21_memchr_test_8) {
  char str1[20] = " \n\0";
  ck_assert_pstr_eq(s21_memchr(str1, ' ', 5), memchr(str1, ' ', 5));
}
END_TEST

// memchr IX
START_TEST(s21_memchr_test_9) {
  ck_assert_pstr_eq(s21_memchr("\n\0", '\n', 5), memchr("\n\0", '\n', 5));
}
END_TEST

// memchr X
START_TEST(s21_memchr_test_10) {
  ck_assert_pstr_eq(s21_memchr("\0", '\0', 5), memchr("\0", '\0', 5));
}
END_TEST

// ================================================================================================================

// strchr I
START_TEST(s21_strchr_test_1) {
  ck_assert_pstr_eq(s21_strchr("Hello_World!\n", 'W'),
                    strchr("Hello_World!\n", 'W'));
}
END_TEST

// strchr II
START_TEST(s21_strchr_test_2) {
  ck_assert_pstr_eq(s21_strchr("Hello World!\n\0", '\0'),
                    strchr("Hello World!\n\0", '\0'));
}
END_TEST

// strchr III
START_TEST(s21_strchr_test_3) {
  ck_assert_pstr_eq(s21_strchr("a\n\0", '\n'), strchr("a\n\0", '\n'));
}
END_TEST

// strchr IV
START_TEST(s21_strchr_test_4) {
  ck_assert_pstr_eq(s21_strchr(" \n\0", '\0'), strchr(" \n\0", '\0'));
}
END_TEST

// strchr V
START_TEST(s21_strchr_test_5) {
  ck_assert_pstr_eq(s21_strchr(" \0", ' '), strchr(" \0", ' '));
}
END_TEST

// strchr VI
START_TEST(s21_strchr_test_6) {
  ck_assert_pstr_eq(s21_strchr("\0", ' '), strchr("\0", ' '));
}
END_TEST

// strchr VII
START_TEST(s21_strchr_test_7) {
  ck_assert_pstr_ne(s21_strchr("Hellow World!", 'H'),
                    strchr("Hello World!", 'H'));
}
END_TEST

// strchr VIII
START_TEST(s21_strchr_test_8) {
  char str1[20] = "HELLO_WORLD!\n\0";
  ck_assert_pstr_ne(s21_strchr(str1, '!'), strchr(str1, '\n'));
}
END_TEST

// strchr IX
START_TEST(s21_strchr_test_9) {
  ck_assert_pstr_ne(s21_strchr("Hello World!\n\0", ' '),
                    strchr("Hello World!\n\0", '\0'));
}
END_TEST

// strchr X
START_TEST(s21_strchr_test_10) {
  ck_assert_ptr_eq(s21_strchr("Hello World!\n", 'l'),
                   strchr("Hello World!\n", 'l'));
}
END_TEST
// ================================================================================================================

// strrchr I
START_TEST(s21_strrchr_test_1) {
  ck_assert_pstr_eq(s21_strrchr("123456789\n\0", '9'),
                    strrchr("123456789\n\0", '9'));
}
END_TEST

// strrchr II
START_TEST(s21_strrchr_test_2) {
  ck_assert_pstr_ne(s21_strrchr("123456789\n\0", '7'),
                    strrchr("123456789\n\0", '9'));
}
END_TEST

// strrchr III
START_TEST(s21_strrchr_test_3) {
  ck_assert_pstr_eq(s21_strchr("Hello Hell HELLO!\0", 'E'),
                    strrchr("Hello Hell HELLO!\0", 'E'));
}
END_TEST

// strrchr IV
START_TEST(s21_strrchr_test_4) {
  ck_assert_pstr_ne(s21_strrchr("Hello Hell HELLO!\0", 'L'),
                    strrchr("Hello Hell HELLO!\0", '\0'));
}
END_TEST

// strrchr V
START_TEST(s21_strrchr_test_5) {
  ck_assert_pstr_eq(s21_strrchr("Hello_World!\0", '\0'),
                    strrchr("Hello_World!\0", '\0'));
}
END_TEST

// strrchr VI
START_TEST(s21_strrchr_test_6) {
  ck_assert_pstr_eq(s21_strrchr("Hello World!", '\0'),
                    strrchr("Hello World!", '\0'));
}
END_TEST

// strrchr VII
START_TEST(s21_strrchr_test_7) {
  ck_assert_pstr_eq(s21_strrchr("\n\0", '\n'), strrchr("\n\0", '\n'));
}
END_TEST

// strrchr VIII
START_TEST(s21_strrchr_test_8) {
  ck_assert_pstr_ne(s21_strrchr("\n\0", '\n'), strrchr("\n\0", ' '));
}
END_TEST

// strrchr IX
START_TEST(s21_strrchr_test_9) {
  ck_assert_pstr_eq(s21_strrchr("\n B \n E \n E \n P\0", 'P'),
                    strrchr("\n B \n E \n E \n P\0", 'P'));
}
END_TEST

// strrchr X
START_TEST(s21_strrchr_test_10) {
  ck_assert_pstr_ne(s21_strrchr("\n\0B\n E\n\0E\n\0 P\0", '\n'),
                    strrchr("\n\0B\n E\n\0E\n\0 P\0", 'P'));
}
END_TEST

// strrchr XII
START_TEST(s21_strrchr_test_11) {
  ck_assert_pstr_eq(s21_strrchr("\n\0\nH0\n\0\n\0", 'H'),
                    strrchr("\n\0\nH0\n\0\n\0", 'H'));
}
END_TEST
// ================================================================================================================

// strpbrk I
START_TEST(s21_strpbrk_test_1) {
  ck_assert_pstr_eq(s21_strpbrk("H0RH1_B1Tch", "T01B"),
                    strpbrk("H0RH1_B1Tch", "T01B"));
}
END_TEST

// strpbrk II
START_TEST(s21_strpbrk_test_2) {
  ck_assert_pstr_ne(s21_strpbrk("Hello W0rld!\n\0", "!\n"),
                    strpbrk("Hello W0rld!\n\0", "0!\n\0"));
}
END_TEST

// strpbrk III
START_TEST(s21_strpbrk_test_3) {
  ck_assert_pstr_eq(s21_strpbrk("Hell0\nW0rld!\0", "\n0!"),
                    strpbrk("Hell0\nW0rld!\0", "\n0!"));
}
END_TEST

// strpbrk IV
START_TEST(s21_strpbrk_test_4) {
  ck_assert_pstr_ne(s21_strpbrk("Hello World!\n\0", "W"),
                    strpbrk("Hello World!\n\0", ""));
}
END_TEST

// strpbrk V
START_TEST(s21_strpbrk_test_5) {
  ck_assert_pstr_eq(s21_strpbrk("\n\0", "1234\n4321"),
                    strpbrk("\n\0", "1234\n4321"));
}
END_TEST

// strpbrk VI
START_TEST(s21_strpbrk_test_6) {
  ck_assert_pstr_ne(s21_strpbrk("\n\0\n", "\n21"),
                    strpbrk("\n\0\n", "23\0\n21"));
}
END_TEST

// strpbrk VII
START_TEST(s21_strpbrk_test_7) {
  ck_assert_pstr_eq(s21_strpbrk("Hello!\0", "0lleH"),
                    strpbrk("Hello!\0", "0lleH"));
}
END_TEST

// strpbrk VIII
START_TEST(s21_strpbrk_test_8) {
  ck_assert_pstr_eq(s21_strpbrk(" 1\n 2\n 3\n 4\0", "987654321"),
                    strpbrk(" 1\n 2\n 3\n 4\0", "987654321"));
}
END_TEST

// strpbrk IX
START_TEST(s21_strpbrk_test_9) {
  ck_assert_pstr_ne(s21_strpbrk(" 1\n 2\n 3\n 4\0", "34"),
                    strpbrk(" 1\n 2\n 3\n 4\0", "12345"));
}
END_TEST
// ================================================================================================================

// strstr I
START_TEST(s21_strstr_test_1) {
  ck_assert_pstr_eq(s21_strstr("a\n\0", "\n"), strstr("a\n\0", "\n"));
}
END_TEST

// strstr II
START_TEST(s21_strstr_test_2) {
  ck_assert_pstr_ne(s21_strstr("a\n\0", "\0"), strstr("a\n\0", "\n"));
}
END_TEST

// strstr III
START_TEST(s21_strstr_test_3) {
  ck_assert_pstr_eq(s21_strstr("Hello_World!\n\0", "Hell"),
                    strstr("Hello_World!\n\0", "Hell"));
}
END_TEST

// strstr IV
START_TEST(s21_strstr_test_4) {
  ck_assert_pstr_ne(s21_strstr("Hello World!\0", "!"),
                    strstr("Hello World!\0", "\0"));
}
END_TEST

// strstr V
START_TEST(s21_strstr_test_5) {
  ck_assert_pstr_eq(s21_strstr("", "1"), strstr("", "1"));
}
END_TEST

// strstr VI
START_TEST(s21_strstr_test_6) {
  ck_assert_pstr_ne(s21_strstr("H0\nRH\n1\0", "R"),
                    strstr("H0\nRH\n1\0", "\n"));
}
END_TEST

// strstr VII
START_TEST(s21_strstr_test_7) {
  ck_assert_pstr_eq(s21_strstr("a\n\0", ""), strstr("a\n\0", ""));
}
END_TEST

// strstr VIII
START_TEST(s21_strstr_test_8) {
  ck_assert_pstr_eq(s21_strstr("\n\0\n\0\nA1\n\0", "1"),
                    strstr("\n\0\n\0\nA1\n\0", "1"));
}
END_TEST

// strstr IX
START_TEST(s21_strstr_test_9) {
  ck_assert_pstr_ne(s21_strstr("\n\0\n\0\nA1\n\0", "\n"),
                    strstr("\n\0\n\0\nA1\n\0", "1"));
}
END_TEST
// ================================================================================================================

// strlen I
START_TEST(s21_strlen_test_1) {
  ck_assert_int_eq(s21_strlen("Hello_World!\n\0"), strlen("Hello_World!\n\0"));
}
END_TEST

// strlen II
START_TEST(s21_strlen_test_2) {
  ck_assert_int_ne(s21_strlen("Hello_World!"), strlen("Hello_World!\n\0"));
}
END_TEST

// strlen III
START_TEST(s21_strlen_test_3) {
  ck_assert_int_eq(s21_strlen("H3LL0_W0RLD!\0"), strlen("H3LL0_W0RLD!\0"));
}
END_TEST

// strlen IV
START_TEST(s21_strlen_test_4) {
  ck_assert_int_ne(s21_strlen("H3LL0_0LD!\0"), strlen("H3LL0_W0RLD!\0"));
}
END_TEST

// strlen V
START_TEST(s21_strlen_test_5) {
  ck_assert_int_eq(s21_strlen("\n\0"), strlen("\n\0"));
}
END_TEST

// strlen VI
START_TEST(s21_strlen_test_6) {
  ck_assert_int_ne(s21_strlen(" \n\0"), strlen("\n\0"));
}
END_TEST

// strlen VII
START_TEST(s21_strlen_test_7) {
  ck_assert_int_eq(s21_strlen(" \n\0"), strlen(" \n\0"));
}
END_TEST

// strlen VIII
START_TEST(s21_strlen_test_8) {
  ck_assert_int_eq(s21_strlen(" \0"), strlen(" \0"));
}
END_TEST
// ================================================================================================================

// memset I
START_TEST(s21_memset_test_1) {
  char str1[20] = "true or false\n\0";
  char str2[20] = "true or false\n\0";
  ck_assert_str_eq(s21_memset(str1, 'a', 5), memset(str2, 'a', 5));
}
END_TEST

// memset II
START_TEST(s21_memset_test_2) {
  char str1[20] = "false or true\n";
  char str2[20] = "false or true\n";
  ck_assert_str_ne(s21_memset(str1, 't', 4), memset(str2, 'R', 5));
}
END_TEST

// memset III
START_TEST(s21_memset_test_3) {
  char str1[20] = "false or true";
  char str2[20] = "false or true";
  ck_assert_str_eq(s21_memset(str1, 't', 4), memset(str2, 't', 4));
}
END_TEST

// memset IV
START_TEST(s21_memset_test_4) {
  char str1[20] = "Hello!\n\0";
  char str2[20] = "Hello!\n\0";
  ck_assert_str_eq(s21_memset(str1, 'H', 0), memset(str2, 'H', 0));
}
END_TEST

// memset V
START_TEST(s21_memset_test_5) {
  char str1[20] = "Hello!\n\0";
  char str2[20] = "Hello!\n\0";
  ck_assert_str_ne(s21_memset(str1, 'H', 9), memset(str2, 'o', 1));
}
END_TEST

// memset VI
START_TEST(s21_memset_test_6) {
  char str1[20] = "Hello!\n";
  char str2[20] = "Hello!\n";
  ck_assert_str_eq(s21_memset(str1, '\n', 7), memset(str2, '\n', 7));
}
END_TEST

// memset VII
START_TEST(s21_memset_test_7) {
  char str1[20] = "Hello!\n";
  char str2[20] = "Hello!\n";
  ck_assert_str_eq(s21_memset(str1, '\0', 7), memset(str2, '\0', 7));
}
END_TEST

// memset VIII
START_TEST(s21_memset_test_8) {
  char str1[20] = "       \n\0";
  char str2[20] = "       \n\0";
  ck_assert_str_ne(s21_memset(str1, ' ', 5), memset(str2, '\0', 7));
}
END_TEST

// memset IX
START_TEST(s21_memset_test_9) {
  char str1[20] = "HW\n\0";
  char str2[20] = "HW\n\0";
  ck_assert_str_eq(s21_memset(str1, ' ', 5), memset(str2, ' ', 5));
}
END_TEST

// memset X
START_TEST(s21_memset_test_10) {
  char str1[20] = "\0";
  char str2[20] = "\0";
  ck_assert_pstr_eq(s21_memset(str1, '1', 1), memset(str2, '1', 1));
}
END_TEST

// memset XI
START_TEST(s21_memset_test_11) {
  char str1[15] = "1234567890";
  char str2[15] = "1234567890";
  ck_assert_pstr_ne(s21_memset(str1, '1', 8), memset(str2, '2', 8));
}
END_TEST
// ================================================================================================================

// strncpy I
START_TEST(s21_strncpy_test_1) {
  char str1[15] = "";
  char str2[15] = "";
  ck_assert_str_eq(s21_strncpy(str1, "Hello!\n\0", 8),
                   strncpy(str2, "Hello!\n\0", 8));
}
END_TEST

// strncpy II
START_TEST(s21_strncpy_test_2) {
  char str1[15] = "Hello!\n\0";
  char str2[15] = "Hello!\n\0";
  ck_assert_pstr_eq(s21_strncpy(str1, "       ", 10),
                    strncpy(str2, "       ", 10));
}
END_TEST

// strncpy III
START_TEST(s21_strncpy_test_3) {
  char str1[15] = " \n\0";
  char str2[15] = " \n\0";
  ck_assert_pstr_eq(s21_strncpy(str1, "1", 14), strncpy(str2, "1", 14));
}
END_TEST

// strncpy IV
START_TEST(s21_strncpy_test_4) {
  char str1[15] = "a\n\0";
  char str2[15] = "a\n\0";
  ck_assert_str_eq(s21_strncpy(str1, " \n\0", 10), strncpy(str2, " \n\0", 10));
}
END_TEST

// strncpy V
START_TEST(s21_strncpy_test_5) {
  char str1[15] = "a\n\0";
  char str2[15] = "a\n\0";
  ck_assert_str_ne(s21_strncpy(str1, " \n", 11), strncpy(str2, "\0", 10));
}
END_TEST

// strncpy VI
START_TEST(s21_strncpy_test_6) {
  char str1[25] = "true       false";
  char str2[25] = "true       false";
  ck_assert_pstr_eq(s21_strncpy(str1, "a\n\0", 5), strncpy(str2, "a\n\0", 5));
}
END_TEST

// strncpy VII
START_TEST(s21_strncpy_test_7) {
  char str1[15] = "true false";
  char str2[15] = "true false";
  ck_assert_str_ne(s21_strncpy(str1, "a\n\0", 5), strncpy(str2, "\n", 5));
}
END_TEST

// strncpy VIII
START_TEST(s21_strncpy_test_8) {
  char str1[15] = "A\nL\nO\nH\nA\n\0";
  char str2[15] = "A\nL\nO\nH\nA\n\0";
  ck_assert_pstr_eq(s21_strncpy(str1, "HELLO", 10), strncpy(str2, "HELLO", 10));
}
END_TEST

START_TEST(s21_strncpy_test_9) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test_10) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test_11) {
  char str1[9] = "abc";
  char str2[] = "de\nf";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test_12) {
#line 2241
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test_13) {
#line 2248
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test_14) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test_15) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST


// ================================================================================================================

// strncmp I
START_TEST(s21_strncmp_test_1) {
  char str1[15] = "1234567890";
  char str2[15] = "1234509876";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

// strncmp II
START_TEST(s21_strncmp_test_2) {
  char str1[15] = "1234567890";
  char str2[15] = "1234567890";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 7));
}
END_TEST

// strncmp III
START_TEST(s21_strncmp_test_3) {
  char str1[15] = "1234567890\n\0";
  char str2[15] = "1234567890\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}
END_TEST

// strncmp IV
START_TEST(s21_strncmp_test_4) {
  char str1[15] = "12345\n67890\n\0";
  char str2[15] = "12345\n09876\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 13), strncmp(str1, str2, 13));
}
END_TEST

// strncmp V
START_TEST(s21_strncmp_test_5) {
  char str1[15] = "12345\n67890\n\0";
  char str2[15] = "12345\n09876\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 13));
}
END_TEST

// strncmp VI
START_TEST(s21_strncmp_test_6) {
  char str1[15] = "12345\067890\n\0";
  char str2[15] = "12345\09876\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

// strncmp VII
START_TEST(s21_strncmp_test_7) {
  char str1[15] = " \n\0";
  char str2[15] = " \n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 13), strncmp(str1, str2, 13));
}
END_TEST

// strncmp VIII
START_TEST(s21_strncmp_test_8) {
  char str1[15] = "\0";
  char str2[15] = "\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 15), strncmp(str1, str2, 15));
}
END_TEST

// strncmp IX
START_TEST(s21_strncmp_test_9) {
  char str1[15] = " a\0";
  char str2[15] = " a\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

// strncmp X
START_TEST(s21_strncmp_test_10) {
  char str1[15] = "Hello\nWorld\n:)\0";
  char str2[15] = "Hello\nWorld\n:)\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 8), strncmp(str1, str2, 8));
}
END_TEST

START_TEST(s21_strncmp_test_11) {
  char str1[] = "abc";
  char str2[] = " abc";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(s21_strncmp_test_12) {
  char str1[] = "123";
  char str2[] = "321";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(s21_strncmp_test_13) {
  char str1[] = "321";
  char str2[] = "123";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(s21_strncmp_test_14) {
  char str1[] = "1234";
  char str2[] = "123";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(s21_strncmp_test_15) {
  char str1[] = "132";
  char str2[] = "1234";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(s21_strncmp_test_17) {
  char str1[] = "abc";
  char str2[] = "abcd";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(s21_strncmp_test_18) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  if (s21 > 1) {
    s21 = 1;
  }
  if (s21 < -1) {
    s21 = -1;
  }
  if (s00 > 1) {
    s00 = 1;
  }
  if (s00 < -1) {
    s00 = -1;
  }
  ck_assert_int_eq(s21, s00);
}
END_TEST
// ================================================================================================================

// strcmp I
START_TEST(s21_strcmp_test_1) {
  char str1[15] = "1234567890\n\0";
  char str2[15] = "1234567890\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp II
START_TEST(s21_strcmp_test_2) {
  char str1[15] = "1234567890\n\0";
  char str2[15] = "123456890\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp III
START_TEST(s21_strcmp_test_3) {
  char str1[15] = "1234567890\n\0";
  char str2[15] = "1234509876\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp IV
START_TEST(s21_strcmp_test_4) {
  char str1[15] = "\n\n\n\0";
  char str2[15] = "\n\n\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp V
START_TEST(s21_strcmp_test_5) {
  char str1[15] = "   \n\0";
  char str2[15] = "   \n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp VI
START_TEST(s21_strcmp_test_6) {
  char str1[15] = "\0";
  char str2[15] = "\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp VII
START_TEST(s21_strcmp_test_7) {
  char str1[15] = "\n\0";
  char str2[15] = "\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp VIII
START_TEST(s21_strcmp_test_8) {
  char str1[15] = " \n\0";
  char str2[15] = "\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp IX
START_TEST(s21_strcmp_test_9) {
  char str1[15] = "1\n2\n//\n\3\0";
  char str2[15] = "1\n2\n//\n\3\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// strcmp X
START_TEST(s21_strcmp_test_10) {
  char str1[15] = "'\\$\'//\0";
  char str2[15] = "'\\$\'//\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST
// ================================================================================================================

// memmove I
START_TEST(s21_memmove_test_1) {
  char str1[30] = "this is string\n\0";
  char str2[30] = "this is string\n\0";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 4), memmove(str1, str2, 4));
}
END_TEST

// memmove II
START_TEST(s21_memmove_test_2) {
  char str1[20] = "this is string\n\0";
  char str2[20] = "   \n\0";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 8), memmove(str1, str2, 8));
}
END_TEST

// memmove III
START_TEST(s21_memmove_test_3) {
  char str1[30] = "this is string\0";
  char str2[30] = "Hello World\0";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 5), memmove(str1, str2, 5));
}
END_TEST

// memmove IV
START_TEST(s21_memmove_test_4) {
  char str1[15] = "";
  char str2[15] = "true";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 5), memmove(str1, str2, 5));
}
END_TEST

// memmove V
START_TEST(s21_memmove_test_5) {
  char str1[20] = "";
  char str2[20] = "\0";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 19), memmove(str1, str2, 19));
}
END_TEST

// memmove VI
START_TEST(s21_memmove_test_6) {
  char str1[15] = "a\n\0";
  char str2[15] = "Aloha\n";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 6), memmove(str1, str2, 6));
}
END_TEST

// memmove VII
START_TEST(s21_memmove_test_7) {
  char str1[100] = "9999\0";
  char str2[100] = "01\0";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 50), memmove(str1, str2, 50));
}
END_TEST

// memmove VIII
START_TEST(s21_memmove_test_8) {
  char str1[100] = "-123123%s";
  char str2[100] = "-123123%s";
  ck_assert_pstr_eq(s21_memmove(str1, str2, 15), memmove(str1, str2, 15));
}
END_TEST
// ================================================================================================================

// strcpy I
START_TEST(s21_strcpy_test_1) {
  char str1[15] = "Hello World!\n\0";
  char ptr[20] = "";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy II
START_TEST(s21_strcpy_test_2) {
  char str1[30] = "123Hello$s%s\n\0";
  char ptr[35] = "\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy III
START_TEST(s21_strcpy_test_3) {
  char str1[25] = "a\n\0";
  char ptr[25] = "a\n\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy IV
START_TEST(s21_strcpy_test_4) {
  char str1[100] = "";
  char ptr[100] = "false or true\n\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy V
START_TEST(s21_strcpy_test_5) {
  char str1[25] = "B\nO\nO\nB\nA";
  char ptr[30] = "B O O\n B\nA\n%s";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy VI
START_TEST(s21_strcpy_test_6) {
  char str1[15] = "BOOBA";
  char ptr[20] = " \n\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy VII
START_TEST(s21_strcpy_test_7) {
  char str1[15] = "BABABOY\0";
  char ptr[20] = "\n\n\n\n\n\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcoy VIII
START_TEST(s21_strcpy_test_8) {
  char str1[15] = "n\n\n\n\n";
  char ptr[20] = "BABABOY\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST

// strcpy IX
START_TEST(s21_strcpy_test_9) {
  char str1[15] = "n\n\n\n\n";
  char ptr[20] = "BABABOY\0";
  ck_assert_pstr_eq(s21_strcpy(str1, ptr), strcpy(str1, ptr));
}
END_TEST
// ================================================================================================================

// memcpy I
START_TEST(s21_memcpy_test_1) {
  char str1[15] = "Hello_World!\n\0";
  char ptr[15] = "";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 13), memcpy(ptr, str1, 13));
}
END_TEST

// memcpy II
START_TEST(s21_memcpy_test_2) {
  char str1[15] = " A\nL\nO\nH\nA\n\0";
  char ptr[15] = "";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 12), memcpy(ptr, str1, 12));
}
END_TEST

// memcpy III
START_TEST(s21_memcpy_test_3) {
  char str1[15] = "1\0";
  char ptr[15] = "";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 10), memcpy(ptr, str1, 10));
}
END_TEST

// memcpy IV
START_TEST(s21_memcpy_test_4) {
  char str1[15] = "\n\0";
  char ptr[15] = "";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 15), memcpy(ptr, str1, 15));
}
END_TEST

// memcpy V
START_TEST(s21_memcpy_test_5) {
  char str1[15] = "BOOBA\0";
  char ptr[15] = "";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 5), memcpy(ptr, str1, 5));
}
END_TEST

// memcpy VI
START_TEST(s21_memcpy_test_6) {
  char str1[15] = "\n\0";
  char ptr[15] = "";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 15), memcpy(ptr, str1, 15));
}
END_TEST

// memcpy VII
START_TEST(s21_memcpy_test_7) {
  char str1[15] = "BOOBA\0";
  char ptr[15] = "Aloha\n";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 15), memcpy(ptr, str1, 15));
}
END_TEST

// memcpy VIII
START_TEST(s21_memcpy_test_8) {
  char str1[15] = "Aloha%s%c\n\0";
  char ptr[30] = "false/true%s\0";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 15), memcpy(ptr, str1, 15));
}
END_TEST

// memcpy IX
START_TEST(s21_memcpy_test_9) {
  char str1[15] = "\n\n\n\n\n \0";
  char ptr[20] = "BABABOY";
  ck_assert_pstr_eq(s21_memcpy(ptr, str1, 15), memcpy(ptr, str1, 15));
}
END_TEST
// ================================================================================================================

// strtok I
START_TEST(s21_strtok_test_1) {
  char str1[20] = "its, not a. bug\n\0";
  ck_assert_pstr_eq(s21_strtok(str1, ", ."), strtok(str1, ", ."));
}
END_TEST

// strtok II
START_TEST(s21_strtok_test_2) {
  char str1[20] = "B.\nO.\nO.\nB.\nA.\0";
  ck_assert_pstr_eq(s21_strtok(str1, "."), strtok(str1, "."));
}
END_TEST

// strtok III
START_TEST(s21_strtok_test_3) {
  char str1[20] = "A\\ l/ o. h, a]\n";
  ck_assert_pstr_eq(s21_strtok(str1, "\\/., "), strtok(str1, "\\/., "));
}
END_TEST

// strtok IV
START_TEST(s21_strtok_test_4) {
  char str1[20] = "\n.\0";
  ck_assert_pstr_eq(s21_strtok(str1, "."), strtok(str1, "."));
}
END_TEST

// strtok V
START_TEST(s21_strtok_test_5) {
  char str1[20] = "\0";
  ck_assert_pstr_eq(s21_strtok(str1, ""), strtok(str1, ""));
}
END_TEST

// strtok VI
START_TEST(s21_strtok_test_6) {
  char str1[20] = "\0";
  ck_assert_pstr_eq(s21_strtok(str1, "123"), strtok(str1, "123"));
}
END_TEST

// strtok VII
START_TEST(s21_strtok_test_7) {
  char str1[20] = "\n\0";
  ck_assert_pstr_eq(s21_strtok(str1, "    "), strtok(str1, "  "));
}
END_TEST

// strtok VIII
START_TEST(s21_strtok_test_8) {
  char str1[20] = "\n";
  ck_assert_pstr_eq(s21_strtok(str1, "\n\0"), strtok(str1, "\n\0"));
}
END_TEST

// strtok IX
START_TEST(s21_strtok_test_9) {
  char str1[20] = "B00BA%s\n\0";
  ck_assert_pstr_eq(s21_strtok(str1, "0A\n"), strtok(str1, "0A\n"));
}
END_TEST

START_TEST(s21_strtok_test_10) {
char s[20] = "weg|rbnt|rn";
char ch[20]  = " |";
char *res_org = strtok(s,  ch);
char *res_s21 = s21_strtok(s,  ch);

while(res_org != s21_NULL && res_s21 != s21_NULL) {
    ck_assert_pstr_eq(res_org,  res_s21);
    res_org = strtok(s21_NULL,  ch);
    res_s21 = s21_strtok(s21_NULL,  ch);
    }
}
END_TEST

START_TEST(s21_strtok_test_11) {
char s[20] = "weg rbn    t|rn";
char ch[20] = " |";
char *res_org = strtok(s,  ch);
char *res_s21 = s21_strtok(s,  ch);

while(res_org != s21_NULL && res_s21 != s21_NULL) {
    ck_assert_pstr_eq(res_org,  res_s21);
    res_org = strtok(s21_NULL,  ch);
    res_s21 = s21_strtok(s21_NULL,  ch);
    }
}
END_TEST

START_TEST(s21_strtok_test_12) {
char s[20] = "12|";
char ch[20] = " |";
char *res_org = strtok(s,  ch);
char *res_s21 = s21_strtok(s,  ch);

while(res_org != s21_NULL && res_s21 != s21_NULL) {
    ck_assert_pstr_eq(res_org,  res_s21);
    res_org = strtok(s21_NULL,  ch);
    res_s21 = s21_strtok(s21_NULL,  ch);
    }
}
END_TEST

START_TEST(s21_strtok_test_13) {
char s[20] = "weg|rbnt|rn";
char ch[20] = "\0";
char *res_org = strtok(s,  ch);
char *res_s21 = s21_strtok(s,  ch);

while(res_org != s21_NULL && res_s21 != s21_NULL) {
    ck_assert_pstr_eq(res_org,  res_s21);
    res_org = strtok(s21_NULL,  ch);
    res_s21 = s21_strtok(s21_NULL,  ch);
    }
}
END_TEST

START_TEST(s21_strtok_test_14) {
char s[20] = "...test/test/test...";
char ch[20] = "./";
char *res_org = strtok(s,  ch);
char *res_s21 = s21_strtok(s,  ch);

while(res_org != s21_NULL && res_s21 != s21_NULL) {
    ck_assert_pstr_eq(res_org,  res_s21);
    res_org = strtok(s21_NULL,  ch);
    res_s21 = s21_strtok(s21_NULL,  ch);
    }
}
// ================================================================================================================

// strcat I
START_TEST(s21_strcat_test_1) {
  char str1[20] = "All\n\0";
  char str2[20] = "Hello ";
  ck_assert_pstr_eq(s21_strcat(str2, str1), strcat(str2, str1));
}
END_TEST

// strcat II
START_TEST(s21_strcat_test_2) {
  char str1[20] = "All\0";
  char str2[20] = "Hello\n";
  ck_assert_pstr_eq(s21_strcat(str2, str1), strcat(str2, str1));
}
END_TEST

// strcat III
START_TEST(s21_strcat_test_3) {
  char str1[20] = "All\n";
  char str2[20] = "Hello\0";
  ck_assert_pstr_eq(s21_strcat(str2, str1), strcat(str2, str1));
}
END_TEST

// strcat IV
START_TEST(s21_strcat_test_4) {
  char str1[20] = "All\n\0";
  char str2[20] = "Hello ";
  ck_assert_pstr_eq(s21_strcat(str1, str2), strcat(str1, str2));
}
END_TEST

// strcat V
START_TEST(s21_strcat_test_5) {
  char str1[20] = "\0";
  char str2[20] = "HelloWorld\n";
  ck_assert_pstr_eq(s21_strcat(str2, str1), strcat(str2, str1));
}
END_TEST

// strcat VI
START_TEST(s21_strcat_test_6) {
  char str1[20] = "\n\0";
  char str2[20] = "false";
  ck_assert_pstr_eq(s21_strcat(str1, str2), strcat(str1, str2));
}
END_TEST

// strcat VII
START_TEST(s21_strcat_test_7) {
  char str1[20] = "true";
  char str2[20] = "\n\0";
  ck_assert_pstr_eq(s21_strcat(str1, str2), strcat(str1, str2));
}
END_TEST

// strcat VIII
START_TEST(s21_strcat_test_8) {
  char str1[50] = "//\\\\%s,.*#@!:;\"\0";
  char str2[50] = "//\\\\%s,.*#@!:;\"\n";
  ck_assert_pstr_eq(s21_strcat(str2, str1), strcat(str2, str1));
}
END_TEST

// strcat IX
START_TEST(s21_strcat_test_9) {
  char str1[50] = "//\\\\%s,.*#@!:;\"\0";
  char str2[50] = "//\\\\%s,.*#@!:;\"\n";
  ck_assert_pstr_eq(s21_strcat(str2, str1), strcat(str2, str1));
}
END_TEST
// ================================================================================================================

// memcmp I
START_TEST(s21_memcmp_test_1) {
  char str1[15] = "1234567890\n\0";
  char str2[15] = "1234567890\n\0";
  ck_assert_int_eq((s21_memcmp(str1, str2, 11) == 0),
                   (memcmp(str1, str2, 11) == 0));
}
END_TEST

// memcmp II
START_TEST(s21_memcmp_test_2) {
  char str1[15] = "1234567890\0";
  char str2[15] = "1234567890\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

// memcmp III
START_TEST(s21_memcmp_test_3) {
  char str1[15] = "1234509876\n\0";
  char str2[15] = "1234567890\n\0";
  ck_assert_int_eq((s21_memcmp(str1, str2, 11) == 0),
                   (memcmp(str1, str2, 11) == 0));
}
END_TEST

// memcmp IV
START_TEST(s21_memcmp_test_4) {
  char str1[15] = "1\n2\n3\n4\n5\n6\0";
  char str2[15] = "1\n2\n3\n5\n6\n4\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

// memcmp V
START_TEST(s21_memcmp_test_5) {
  char str1[15] = "\ngoogle\0";
  char str2[15] = "\ngooble\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 15), memcmp(str1, str2, 15));
}
END_TEST

// memcmp VI
START_TEST(s21_memcmp_test_6) {
  char str1[100] = "booble%s%s\\//\'\0";
  char str2[100] = "booble%s%s\\//\'\00";
  ck_assert_int_eq(s21_memcmp(str1, str2, 100), memcmp(str1, str2, 100));
}
END_TEST

// memcmp VII
START_TEST(s21_memcmp_test_7) {
  char str1[100] = "booble%s%s\\//\'\0";
  char str2[100] = "booble%s%s\\//\'\00";
  ck_assert_int_eq(s21_memcmp(str1, str2, 99), memcmp(str1, str2, 99));
}
END_TEST

// memcmp VIII
START_TEST(s21_memcmp_test_8) {
  char str1[20] = "Hello World\n";
  char str2[20] = "Hello world";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

// memcmp IX
START_TEST(s21_memcmp_test_9) {
  char str1[20] = "Hello World\0";
  char str2[20] = "Hello World!\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

// memcmp X
START_TEST(s21_memcmp_test_10) {
  char str1[100] = "\n\n\n\n\n\n\0";
  char str2[50] = "\n\n\n\n\n\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 50), memcmp(str1, str2, 50));
}
END_TEST
// ================================================================================================================

// strspn I
START_TEST(s21_strspn_test_1) {
  ck_assert_int_eq(s21_strspn("\n", "\n\0"), strspn("\n", "\n\0"));
}
END_TEST

// strspn II
START_TEST(s21_strspn_test_2) {
  ck_assert_int_eq(s21_strspn("Aloha123\0", "oa3\0"),
                   strspn("Aloha123\0", "oa3\0"));
}
END_TEST

// strspn III
START_TEST(s21_strspn_test_3) {
  ck_assert_int_eq(s21_strspn("\nB\nO\nB\n\0", "\n8\n0\nB\n\0"),
                   strspn("\nB\nO\nB\n\0", "\n8\n0\nB\n\0"));
}
END_TEST

// strspn IV
START_TEST(s21_strspn_test_4) {
  ck_assert_int_eq(s21_strspn("\0", ""), strspn("\0", ""));
}
END_TEST

// strspn V
START_TEST(s21_strspn_test_5) {
  ck_assert_int_eq(s21_strspn("\0", ""), strspn("\0", ""));
}
END_TEST

// strspn VI
START_TEST(s21_strspn_test_6) {
  ck_assert_int_eq(s21_strspn("", "\n\0"), strspn("", "\n\0"));
}
END_TEST

// strspn VII
START_TEST(s21_strspn_test_7) {
  ck_assert_int_eq(s21_strspn("H E L L O ! \0", "L L O ! \0"),
                   strspn("H E L L O ! \0", "L L O ! \n"));
}
END_TEST
// ================================================================================================================

// strncat I
START_TEST(s21_strncat_test_1) {
  char str1[100] = "H E L L O |";
  char str2[100] = "A L O H A |\n";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 7), strncat(str1, str2, 7));
}
END_TEST

// strncat II
START_TEST(s21_strncat_test_2) {
  char str1[25] = "a\n\0";
  char str2[25] = "a\n\0";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 10), strncat(str1, str2, 10));
}
END_TEST

// strncat III
START_TEST(s21_strncat_test_3) {
  char str1[25] = "Hello_World!\n\0";
  char str2[25] = "BOB\0";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 3), strncat(str1, str2, 3));
}
END_TEST

// strncat IV
START_TEST(s21_strncat_test_4) {
  char str1[25] = "\0";
  char str2[25] = "\0";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 1), strncat(str1, str2, 1));
}
END_TEST

// strncat V
START_TEST(s21_strncat_test_5) {
  char str1[10] = "";
  char str2[10] = "\n\0";
  ck_assert_pstr_eq(s21_strncat(str1, str2, 8), strncat(str1, str2, 8));
}
END_TEST

// strncat VI
START_TEST(s21_strncat_test_6) {
  char str1[30] = "Hotline!\0";
  char str2[10] = "       ";
  ck_assert_str_eq(s21_strncat(str1, str2, 10), strncat(str1, str2, 10));
}
END_TEST

// strncat VII
START_TEST(s21_strncat_test_7) {
  char str1[30] = "Hotline!\0";
  char str2[30] = "       ";
  ck_assert_str_eq(s21_strncat(str2, str1, 8), strncat(str2, str1, 8));
}
END_TEST

// strncat VIII
START_TEST(s21_strncat_test_8) {
  char str1[30] = "Hotline\0";
  char str2[30] = "       ";
  ck_assert_str_eq(s21_strncat(str2, str1, 8), strncat(str2, str1, 8));
}
END_TEST

// ================================================================================================================

// strcspn I
START_TEST(s21_strcspn_test_1) {
  char str1[20] = "ABCD013";
  char str2[20] = "CD0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn II
START_TEST(s21_strcspn_test_2) {
  char str1[20] = "ABCD013\n\0";
  char str2[20] = "\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn III
START_TEST(s21_strcspn_test_3) {
  char str1[20] = "ABCD013\n\0";
  char str2[20] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn IV
START_TEST(s21_strcspn_test_4) {
  char str1[20] = "ABCD013\n\0";
  char str2[20] = "\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn V
START_TEST(s21_strcspn_test_5) {
  char str1[20] = "ABCD013\n\0";
  char str2[20] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn VI
START_TEST(s21_strcspn_test_6) {
  char str1[20] = "";
  char str2[20] = "\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn VII
START_TEST(s21_strcspn_test_7) {
  char str1[20] = "";
  char str2[20] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn VIII
START_TEST(s21_strcspn_test_8) {
  char str1[20] = "\0";
  char str2[20] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// strcspn IX
START_TEST(s21_strcspn_test_9) {
  char str1[20] = "";
  char str2[20] = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST
// ================================================================================================================

// strerror I
START_TEST(s21_strerror_test_1) {
  char *str1;
  str1 = s21_strerror(15);
  ck_assert_str_eq(str1, strerror(15));
}
END_TEST

// strerror II
START_TEST(s21_strerror_test_2) {
  char *str1;
  str1 = s21_strerror(-10);
  ck_assert_str_eq(str1, strerror(-10));
}
END_TEST

// strerror III
START_TEST(s21_strerror_test_3) {
  char *str1;
  str1 = s21_strerror(-10);
  ck_assert_str_eq(str1, strerror(-10));
}
END_TEST

// strerror IV
START_TEST(s21_strerror_test_4) {
  char *str1;
  str1 = s21_strerror(44);
  ck_assert_str_eq(str1, strerror(44));
}
END_TEST

// strerror V
START_TEST(s21_strerror_test_5) {
  char *str1;
  str1 = s21_strerror(1000);
  ck_assert_str_eq(str1, strerror(1000));
}
END_TEST

// strerror VI
START_TEST(s21_strerror_test_6) {
  char *str1;
  str1 = s21_strerror(1000);
  ck_assert_str_eq(str1, strerror(1000));
}
END_TEST

// strerror VII
START_TEST(s21_strerror_test_7) {
  char *str1;
  str1 = s21_strerror(123);
  ck_assert_pstr_eq(str1, strerror(123));
}
END_TEST
// ================================================================================================================

// lower I
START_TEST(s21_to_lower_test_1) {
  char str1[10] = "abcdefg";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "abcdefg");
  free(str2);
}
END_TEST

// lower II
START_TEST(s21_to_lower_test_2) {
  char str1[20] = "HELLO_WORLD!\n\0";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello_world!\n\0");
  free(str2);
}
END_TEST

// lower III
START_TEST(s21_to_lower_test_3) {
  char str1[20] = "Hello World\0";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello world\0");
  free(str2);
}
END_TEST

// lower IV
START_TEST(s21_to_lower_test_4) {
  char str1[20] = "A\nB\nC\nD\0";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "a\nb\nc\nd\0");
  free(str2);
}
END_TEST

// lower V
START_TEST(s21_to_lower_test_5) {
  char str1[20] = "";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

// lower VI
START_TEST(s21_to_lower_test_6) {
  char str1[20] = " \n\0";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, " \n\0");
  free(str2);
}
END_TEST

// lower VII
START_TEST(s21_to_lower_test_7) {
  char str1[20] = "123EFG321";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "123efg321");
  free(str2);
}
END_TEST

// lower VIII
START_TEST(s21_to_lower_test_8) {
  char str1[20] = "B00BA%s\n";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_str_eq(str2, "b00ba%s\n");
  free(str2);
}
END_TEST
// ================================================================================================================

// upper I
START_TEST(s21_to_upper_test_1) {
  char str1[10] = "ABCDEFG";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABCDEFG");
  free(str2);
}
END_TEST

// upper II
START_TEST(s21_to_upper_test_2) {
  char str1[20] = "hello_world!\n\0";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "HELLO_WORLD!\n\0");
  free(str2);
}
END_TEST

// upper III
START_TEST(s21_to_upper_test_3) {
  char str1[20] = "Hello World!\n";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "HELLO WORLD!\n");
  free(str2);
}
END_TEST

// upper IV
START_TEST(s21_to_upper_test_4) {
  char str1[20] = "a\nb\nc\nd\n";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "A\nB\nC\nD\n");
  free(str2);
}
END_TEST

// upper V
START_TEST(s21_to_upper_test_5) {
  char str1[20] = "";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

// upper VI
START_TEST(s21_to_upper_test_6) {
  char str1[20] = " \n\0";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, " \n\0");
  free(str2);
}
END_TEST

// upper VII
START_TEST(s21_to_upper_test_7) {
  char str1[20] = "123abcd321\n";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "123ABCD321\n");
  free(str2);
}
END_TEST

// upper VIII
START_TEST(s21_to_upper_test_8) {
  char str1[20] = "b00ba\n";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_str_eq(str2, "B00BA\n");
  free(str2);
}
END_TEST
// ================================================================================================================

// trim I
START_TEST(s21_trim_test_1) {
  char *str1 = "oboobao";
  char *str2 = "oa";
  void *res;
  res = s21_trim(str1, str2);
  ck_assert_str_eq(res, "boob");
  free(res);
}
END_TEST

// trim II
START_TEST(s21_trim_test_2) {
  char *str1 = "  BOOBA   ";
  char *str2 = "  ";
  void *res;
  res = s21_trim(str1, str2);
  ck_assert_str_eq(res, "BOOBA");
  free(res);
}
END_TEST

// trim II
START_TEST(s21_trim_test_3) {
  char *str1 = "  Hello_World!\n\0";
  char *str2 = "  ";
  void *res;
  res = s21_trim(str1, str2);
  ck_assert_str_eq(res, "Hello_World!\n\0");
  free(res);
}
END_TEST

// trim IV
START_TEST(s21_trim_test_4) {
  char *str1 = "nicecoockB\nO\nO\nB\nAnicecoock";
  char *str2 = "nicecoock";
  void *res;
  res = s21_trim(str1, str2);
  ck_assert_str_eq(res, "B\nO\nO\nB\nA");
  free(res);
}
END_TEST

// trim V
START_TEST(s21_trim_test_5) {
  char *str1 = "*!@look at me@!*";
  char *str2 = "*!@";
  void *res;
  res = s21_trim(str1, str2);
  ck_assert_str_eq(res, "look at me");
  free(res);
}
END_TEST

START_TEST(s21_trim_test_6) {
char src[5] = "f45f";
char trim_chars[5] = "f6";
char *res_s21 = s21_trim(src,  trim_chars);
char res_org[5] = "45";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}
END_TEST

START_TEST(s21_trim_test_7) {
char src[5] = "123";
char trim_chars[5] = "f6";
char *res_s21 = s21_trim(src,  trim_chars);
char res_org[5] = "123";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}
END_TEST

START_TEST(s21_trim_test_8) {
char src[30] = "123u3iui78231";
char trim_chars[10] = "1hg23";
char *res_s21 = s21_trim(src,  trim_chars);
char res_org[20] = "u3iui78";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}
END_TEST

START_TEST(s21_trim_test_9) {
char src[5] = "\0";
char trim_chars[5] = "f6";
char *res_s21 = s21_trim(src,  trim_chars);
char *res_org = "\0";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}
END_TEST

START_TEST(s21_trim_test_10) {
char src[6] = "fg\0fv";
char trim_chars[6] = "f6";
char *res_s21 = s21_trim(src,  trim_chars);
char res_org[5] = "g";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}
END_TEST

START_TEST(s21_trim_test_11) {
char src[] = "qqq";
char *trim_chars = "q";
char *res_s21 = s21_trim(src, trim_chars);
char *res_org = "\0";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}

START_TEST(s21_trim_test_12) {
char src[] = "\0";
char *trim_chars = "\0";
char *res_s21 = s21_trim(src, trim_chars);
char *res_org = "\0";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}

START_TEST(s21_trim_test_13) {
char src[] = "qqq    v   ";
char *trim_chars = s21_NULL;
char *res_s21 = s21_trim(src,  trim_chars);
char res_org[] = "qqq    v";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}

END_TEST
START_TEST(s21_trim_test_14) {
char src[10] = "/=f45f";
char trim_chars[5] = "f";
char *res_s21 = s21_trim(src,  trim_chars);
char res_org[10] = "/=f45";
ck_assert_pstr_eq(res_s21,  res_org);
free(res_s21);
}
END_TEST

// ================================================================================================================

// insert I
START_TEST(s21_insert_test_1) {
  char *str1 = "i like";
  char *str2 = "_BOOBA";
  char *res;
  res = s21_insert(str1, str2, 6);
  ck_assert_str_eq(res, "i like_BOOBA");
  free(res);
}
END_TEST

// insert II
START_TEST(s21_insert_test_2) {
  char *str1 = "insert\n\0";
  char *str2 = "|girl";
  char *res;
  res = s21_insert(str1, str2, 6);
  ck_assert_str_eq(res, "insert|girl\n\0");
  free(res);
}
END_TEST

// insert III
START_TEST(s21_insert_test_3) {
  char *str1 = "run , RUN\0";
  char *str2 = "Forrest\n";
  char *res;
  res = s21_insert(str1, str2, 4);
  ck_assert_str_eq(res, "run Forrest\n, RUN\0");
  free(res);
}
END_TEST

// insert IV
START_TEST(s21_insert_test_4) {
  char *str1 = "Hello__World!\n\0";
  char *str2 = "1984";
  char *res;
  res = s21_insert(str1, str2, 6);
  ck_assert_str_eq(res, "Hello_1984_World!\n\0");
  free(res);
}
END_TEST

// insert V
START_TEST(s21_insert_test_5) {
  char *str1 = "Hello\n\nWorld\0";
  char *str2 = "1984";
  char *res;
  res = s21_insert(str1, str2, 6);
  ck_assert_str_eq(res, "Hello\n1984\nWorld\0");
  free(res);
}
END_TEST

// insert VI
START_TEST(s21_insert_test_6) {
  char *str1 = "|truefalse|";
  char *str2 = "====";
  char *res;
  res = s21_insert(str1, str2, 5);
  ck_assert_str_eq(res, "|true====false|");
  free(res);
}
END_TEST
// ================================================================================================================

// printf I
START_TEST(s21_sprintf_test_1) {
  char str1[512];
  char str2[512];
  wchar_t ch_1 = 'G', ch_2 = 'k';

  int res_1 = sprintf(str1,
                        "|%c|%5c|%-7c|%*c|%*c|%-*c|%-8lc|%lc|",
                        'a', 'b', 'C', 12, 'D', -8, 'E', -5, 'F', ch_1, ch_2);
  int res_2 = s21_sprintf(str2,
                            "|%c|%5c|%-7c|%*c|%*c|%-*c|%-8lc|%lc|",
                            'a', 'b', 'C', 12, 'D', -8, 'E', -5, 'F', ch_1, ch_2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf II
START_TEST(s21_sprintf_test_2) {
  char str1[512];
  char str2[512];
  wchar_t str_1[5] = {'b', 'y', 'e'};
  wchar_t str_2[5] = {'g', 'o', 'o', 'd'};

  int res_1 = sprintf(str1,
                    "|%s|%3s|%-4s|%5.s|%5.2s|%3.*s|%*.*s|%*s|%3ls|%5.5ls|%.3s|",
                    "hello", "WorlD", "Adobe", "Good bye", "DeEp BoOm", -3, "Follow",
                    10, 5, "bye", -5, "system", str_1, str_2, "abcdefg");
  int res_2 = s21_sprintf(str2,
                    "|%s|%3s|%-4s|%5.s|%5.2s|%3.*s|%*.*s|%*s|%3ls|%5.5ls|%.3s|",
                    "hello", "WorlD", "Adobe", "Good bye", "DeEp BoOm", -3, "Follow",
                    10, 5, "bye", -5, "system", str_1, str_2, "abcdefg");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf III
START_TEST(s21_sprintf_test_3) {
  char str1[512];
  char str2[512];
  short num_1 = 22;

  int res_1 = sprintf(str1,
                    "|%-7.3d|%15.7d|%.8d|%6d|%*d|%*.*d|%+-6.*d|%+4.2ld|%-9.*hd|",
                    327, 288, 2367, 17, 13, 36, 7, 12, 689, 6, 888, 123456789l, 9, num_1);
  int res_2 = s21_sprintf(str2,
                    "|%-7.3d|%15.7d|%.8d|%6d|%*d|%*.*d|%+-6.*d|%+4.2ld|%-9.*hd|",
                    327, 288, 2367, 17, 13, 36, 7, 12, 689, 6, 888, 123456789l, 9, num_1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf IV
START_TEST(s21_sprintf_test_4) {
  char str1[512];
  char str2[512];
  short num_1 = 22;
  long num_2 = 12121212121222;

  int res_1 = sprintf(str1,
                    "|%+20.i|%-12.17i|%17.i|%18i|%*.*i|%-13.*i|%+13.5li|%*.14hi|",
                    32457, 388, 2367, 147, 13, 6, 237, 12, 689, num_2, 88, num_1);
  int res_2 = s21_sprintf(str2,
                    "|%+20.i|%-12.17i|%17.i|%18i|%*.*i|%-13.*i|%+13.5li|%*.14hi|",
                    32457, 388, 2367, 147, 13, 6, 237, 12, 689, num_2, 88, num_1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf V
START_TEST(s21_sprintf_test_5) {
  char str1[512];
  char str2[512];
  int res_1 = sprintf(str1,
                    "|%+-23e|%013.*e|%-*.14e|%#023.7e|%*.*e|%*.15e|%#010.*e|%27.18e|",
                    12345.654321, 12, 987456.145289, 7, -0.0000785, 857545.1234789,
                    10, 15, 113123.45, 12, -3123.3234234, 14, -0.000234, 2342342352.243245);
  int res_2 = s21_sprintf(str2,
                    "|%+-23e|%013.*e|%-*.14e|%#023.7e|%*.*e|%*.15e|%#010.*e|%27.18e|",
                    12345.654321, 12, 987456.145289, 7, -0.0000785, 857545.1234789,
                    10, 15, 113123.45, 12, -3123.3234234, 14, -0.000234, 2342342352.243245);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf VI
START_TEST(s21_sprintf_test_6) {
  char str1[512];
  char str2[512];

  int res_1 = sprintf(str1,
                    "|%+-23E|%013.*E|%-*.14E|%#023.7E|%*.*E|%*.15E|%#010.*E|%27.18E|",
                    12345.654321, 12, 987456.145289, 7, -0.0000785, 857545.1234789,
                    10, 15, 113123.45, 12, -3123.3234234, 14, -0.000234, 2342342352.243245);
  int res_2 = s21_sprintf(str2,
                    "|%+-23E|%013.*E|%-*.14E|%#023.7E|%*.*E|%*.15E|%#010.*E|%27.18E|",
                    12345.654321, 12, 987456.145289, 7, -0.0000785, 857545.1234789,
                    10, 15, 113123.45, 12, -3123.3234234, 14, -0.000234, 2342342352.243245);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf VII
START_TEST(s21_sprintf_test_7) {
  char str1[512];
  char str2[512];

  int res_1 = sprintf(str1,
                    "|%+-10.5f|%+10.2f|%15.16f|%+*.10f|%*.16f|%-10.*f|%25.*f|%25.f|%#+10.f|%*.*f|",
                    1234.432158, 8956.1457, 5548.1765534, 17, 14614.56454878, 10, 145761517681.541511,
                    3, 45146.51454, 2, 1234124.123123123, 434214543.321321, 12312.234125, 12, 3,
                    12343.54534);
  int res_2 = s21_sprintf(str2,
                    "|%+-10.5f|%+10.2f|%15.16f|%+*.10f|%*.16f|%-10.*f|%25.*f|%25.f|%#+10.f|%*.*f|",
                    1234.432158, 8956.1457, 5548.1765534, 17, 14614.56454878, 10, 145761517681.541511,
                    3, 45146.51454, 2, 1234124.123123123, 434214543.321321, 12312.234125, 12, 3,
                    12343.54534);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf VIII
START_TEST(s21_sprintf_test_8) {
  char str1[512];
  char str2[512];

  int res_1 = sprintf(str1,
                    "|%g|%13g|%-12g|%011g|%#13.7g|%0#12.9g|%+10.5g|%#*.g|%-7.*g|%+#15.7g|",
                    1234.43, 2345.24, 4534.26, 43434.4, 0.00043534, -3453454.435435,
                    3454.32345, 5, 2345.53454, 10, 234234.2344, 0.000012);
  int res_2 = s21_sprintf(str2,
                    "|%g|%13g|%-12g|%011g|%#13.7g|%0#12.9g|%+10.5g|%#*.g|%-7.*g|%+#15.7g|",
                    1234.43, 2345.24, 4534.26, 43434.4, 0.00043534, -3453454.435435,
                    3454.32345, 5, 2345.53454, 10, 234234.2344, 0.000012);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf IX
START_TEST(s21_sprintf_test_9) {
  char str1[512];
  char str2[512];

  int res_1 = sprintf(str1,
                    "|%G|%13G|%-12G|%011G|%#13.7G|%0#12.9G|%+10.5G|%#*.G|%-7.*G|%+#15.7G|",
                    1234.43, 2345.24, 4534.26, 43434.4, 0.00043534, -3453454.435435,
                    3454.32345, 5, 2345.53454, 10, 234234.2344, 0.000012);
  int res_2 = s21_sprintf(str2,
                    "|%G|%13G|%-12G|%011G|%#13.7G|%0#12.9G|%+10.5G|%#*.G|%-7.*G|%+#15.7G|",
                    1234.43, 2345.24, 4534.26, 43434.4, 0.00043534, -3453454.435435,
                    3454.32345, 5, 2345.53454, 10, 234234.2344, 0.000012);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf X
START_TEST(s21_sprintf_test_10) {
  char str1[512];
  char str2[512];
  unsigned short num_3 = 22;
  unsigned long num_4 = 12121212121222l;

  int res_1 = sprintf(str1,
                    "|%-25.10o|%-10o|%#-30.2o|%#*.10o|%#*.*o|%25.*o|%#.10ho|%*lo|",
                    12345, 532247, 74582, 12, 2134543, 13, 5, 1234, 7, 1234, num_3, 7, num_4);
  int res_2 = s21_sprintf(str2,
                    "|%-25.10o|%-10o|%#-30.2o|%#*.10o|%#*.*o|%25.*o|%#.10ho|%*lo|",
                    12345, 532247, 74582, 12, 2134543, 13, 5, 1234, 7, 1234, num_3, 7, num_4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf XI
START_TEST(s21_sprintf_test_11) {
  char str1[512];
  char str2[512];
  unsigned short num_3 = 22;
  unsigned long num_4 = 12121212121222l;

  int res_1 = sprintf(str1,
                    "|%u|%12u|%-21u|%017u|%-13.9u|%20.*u|%*.*u|%*.10u|%-20.10lu|%18hu|",
                    1234u, 1234567u, 43534u, 11234234u, 5345631u, 8, 123213u, 10, 4, 1234u, 8,
                    1325u, num_4, num_3);
  int res_2 = s21_sprintf(str2,
                    "|%u|%12u|%-21u|%017u|%-13.9u|%20.*u|%*.*u|%*.10u|%-20.10lu|%18hu|",
                    1234u, 1234567u, 43534u, 11234234u, 5345631u, 8, 123213u, 10, 4, 1234u, 8,
                    1325u, num_4, num_3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf XII
START_TEST(s21_sprintf_test_12) {
  char str1[512];
  char str2[512];
  unsigned short num_3 = 22;
  unsigned long num_4 = 12121212121222l;

  int res_1 = sprintf(str1,
                    "|%x|%-17x|%#14x|%#-10x|%#12.6x|%-23.32x|%#-12.3x|%*.*x|%#*.10x|"
                    "%20.*x|%#12.*x|%*.7hx|%10.21lx|", 123, 1213, 34324, 123643, 2345436,
                    45645, 456755, 11, 13, 2423, 7, 234324, 11, 234543, 4, 23423, 10, num_3, num_4);
  int res_2 = s21_sprintf(str2,
                    "|%x|%-17x|%#14x|%#-10x|%#12.6x|%-23.32x|%#-12.3x|%*.*x|%#*.10x|"
                    "%20.*x|%#12.*x|%*.7hx|%10.21lx|", 123, 1213, 34324, 123643, 2345436,
                    45645, 456755, 11, 13, 2423, 7, 234324, 11, 234543, 4, 23423,
                    10, num_3, num_4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf XIII
START_TEST(s21_sprintf_test_13) {
  char str1[512];
  char str2[512];
  unsigned short num_3 = 22;
  unsigned long num_4 = 12121212121222l;

  int res_1 = sprintf(str1,
                    "|%X|%-17X|%#14X|%#-10X|%#12.6X|%-23.32X|%#-12.3X|%*.*X|%#*.10X|"
                    "%20.*X|%#12.*X|%*.7hX|%10.21lX|", 123, 1213, 34324, 123643, 2345436, 45645,
                    456755, 11, 13, 2423, 7, 234324, 11, 234543, 4, 23423, 10, num_3, num_4);
  int res_2 = s21_sprintf(str2,
                    "|%X|%-17X|%#14X|%#-10X|%#12.6X|%-23.32X|%#-12.3X|%*.*X|%#*.10X|"
                    "%20.*X|%#12.*X|%*.7hX|%10.21lX|", 123, 1213, 34324, 123643, 2345436, 45645,
                    456755, 11, 13, 2423, 7, 234324, 11, 234543, 4, 23423, 10, num_3, num_4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf XIV
START_TEST(s21_sprintf_test_14) {
  char str1[512];
  char str2[512];
  void *ptr_1 = (void*)43567;
  void *ptr_2 = (void*)0x12345;

  int res_1 = sprintf(str1,
                    "|%p|%14p|%-12p|%6p|%-14p|%*p|%7p|%*p|",
                    ptr_1, ptr_2, ptr_2, ptr_2, ptr_1, 7, ptr_2, ptr_2, 10, ptr_2);
  int res_2 = s21_sprintf(str2,
                    "|%p|%14p|%-12p|%6p|%-14p|%*p|%7p|%*p|",
                    ptr_1, ptr_2, ptr_2, ptr_2, ptr_1, 7, ptr_2, ptr_2, 10, ptr_2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// printf XV
START_TEST(s21_sprintf_test_15) {
  char str1[512];
  char str2[512];
  int n_1, n_2;

  int res_1 = sprintf(str1, "|%%%n|%%|%%%%|%%%%%n|%%%%%%%%%%%%%%%%%%%%|", &n_1, &n_2);
  int res_2 = s21_sprintf(str2, "|%%%n|%%|%%%%|%%%%%n|%%%%%%%%%%%%%%%%%%%%|", &n_1, &n_2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_sprintf_test_int_16) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_17) {
    char str1[512];
    char str2[512];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_18) {
    char str1[512];
    char str2[512];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_19) {
    char str1[512];
    char str2[512];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_20) {
    char str1[512];
    char str2[512];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_21) {
    char str1[512];
    char str2[512];

    char *format = "%012i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_22) {
    char str1[512];
    char str2[512];

    char *format = "%0*d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_23) {
    char str1[512];
    char str2[512];

    char *format = "%0.*i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_24) {
    char str1[512];
    char str2[512];

    char format[] = "%0.*i %d %4.*i %013d %d";
    int val = 69;
    ck_assert_int_eq(
        s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
        sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_25) {
    char str1[512];
    char str2[512];

    char *format = "%+5.31li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_26) {
    char str1[512];
    char str2[512];

    char *format = "%-16.9hi";
    short int val = 6958;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_27) {
    char str1[512];
    char str2[512];

    char *format = "%0.*ld";
    long val = 8581385185;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_28) {
    char str1[512];
    char str2[512];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_int_29) {
    char str1[512];
    char str2[512];

    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_val_30) {
    char str1[512];
    char str2[512];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_val_31) {
    char str1[512];
    char str2[512];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_val_32) {
    char str1[512];
    char str2[512];

    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_val_33) {
    char str1[512];
    char str2[512];

    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_val_34) {
    char str1[512];
    char str2[512];

    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_val_35) {
    char str1[512];
    char str2[512];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_val_36) {
    char str1[512];
    char str2[512];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_val_37) {
    char str1[512];
    char str2[512];

    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
                     sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_val_38) {
    char str1[512];
    char str2[512];

    char *format = "%15o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_39) {
    char str1[512];
    char str2[512];

    char *format = "%-16o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_40) {
    char str1[512];
    char str2[512];

    char *format = "%.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_octal_41) {
    char str1[512];
    char str2[512];

    char *format = "%-5.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_42) {
    char str1[512];
    char str2[512];

    char *format = "%o";
    ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_43) {
    char str1[512];
    char str2[512];

    char *format = "%#o";
    int val = 57175;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_octal_44) {
    char str1[512];
    char str2[512];

    char *format = "%hd";
    short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_45) {
    char str1[512];
    char str2[512];

    char *format = "%lo";
    long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_46) {
    char str1[512];
    char str2[512];

    char *format = "%lo, %o, %ho, %.5o, %5.o";
    long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
                     sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_octal_47) {
    char str1[512];
    char str2[512];

    char *format = "%lo";
    long int val = 84518;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_zero_48) {
    char str1[512];
    char str2[512];

    char *format = "%u";
    ck_assert_int_eq(s21_sprintf(str1, format, 0),
                     sprintf(str2, format, (unsigned)0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_hex_49) {
    char str1[512];
    char str2[512];

    char *format = "%5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_hex_50) {
    char str1[512];
    char str2[512];

    char *format = "%#-10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_51) {
    char str1[512];
    char str2[512];

    char *format = "%.15x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_52) {
    char str1[512];
    char str2[512];

    char *format = "%#-10x%x%X%#x%#X%5.5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                     sprintf(str2, format, val, val, val, val, val, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_53) {
    char str1[512];
    char str2[512];

    char *format = "%#-5.10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_54) {
    char str1[512];
    char str2[512];

    char *format = "%#x";
    unsigned val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_55) {
    char str1[512];
    char str2[512];

    char *format = "%#x";
    unsigned val = 18571;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_56) {
    char str1[512];
    char str2[512];

    char *format = "%#hx";
    unsigned short val = 12352;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_57) {
    char str1[512];
    char str2[512];

    char *format = "%#lx";
    unsigned long val = 18571757371571;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_hex_58) {
    char str1[512];
    char str2[512];

    char *format = "%#2x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_hex_59) {
    char str1[512];
    char str2[512];

    char *format = "%#30x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_60) {
    char str1[512];
    char str2[512];

    char *format = "%c";
    char val = 'X';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_61) {
    char str1[512];
    char str2[512];

    char *format = "%.5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_62) {
    char str1[512];
    char str2[512];

    char *format = "% -5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_63) {
    char str1[512];
    char str2[512];

    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_64) {
    char str1[512];
    char str2[512];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_65) {
    char str1[512];
    char str2[512];

    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_string_66) {
    char str1[512];
    char str2[512];

    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_string_67) {
    char str1[512];
    char str2[512];

    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_string_68) {
    char str1[512];
    char str2[512];

    char *format = "%15s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_string_69) {
    char str1[512];
    char str2[512];

    char *format = "%-15.9s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_string_70) {
    char str1[512];
    char str2[512];

    char *format = "%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_string_71) {
    char str1[512];
    char str2[512];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_ptr_72) {
    char str1[512];
    char str2[512];

    char *format = "%p";
    ck_assert_int_eq(s21_sprintf(str1, format, format),
                     sprintf(str2, format, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_ptr_73) {
    char str1[512];
    char str2[512];

    char *format = "%15p";
    ck_assert_int_eq(s21_sprintf(str1, format, format),
                     sprintf(str2, format, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_ptr_74) {
    char str1[512];
    char str2[512];

    char *format = "%.5p";
    ck_assert_int_eq(s21_sprintf(str1, format, format),
                     sprintf(str2, format, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_ptr_75) {
    char str1[512];
    char str2[512];

    char *format = "%p";
    char *ptr = NULL;
    ck_assert_int_eq(s21_sprintf(str1, format, ptr),
                     sprintf(str2, format, ptr));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_76) {
    char str1[512];
    char str2[512];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_77) {
    char str1[512];
    char str2[512];
    int ret = 0;
    char *format = "Hello, my sexy little aboba abobushka abobina %n";
    ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                     sprintf(str2, format, &ret));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_78) {
    char str1[512];
    char str2[512];
    char *format = "%Lf";
    long double val = 513515.131513515151351;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_79) {
    char str1[512];
    char str2[512];
    char *format = "%10Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_80) {
    char str1[512];
    char str2[512];
    char *format = "%.0Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_81) {
    char str1[512];
    char str2[512];
    char *format = "%.Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_82) {
    char str1[512];
    char str2[512];
    char *format = "%.15Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_83) {
    char str1[512];
    char str2[512];
    char *format = "%.15Lf";
    long double val = -15.35581134;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_84) {
    char str1[512];
    char str2[512];
    char *format = "%Lf";
    long double val = 72537572375.1431341;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_85) {
    char str1[512];
    char str2[512];
    char *format = "% f";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_86) {
    char str1[512];
    char str2[512];
    char *format = "% .0f %.lf %Lf %f %lf %Lf";
    float val = 0;
    double val1 = 0;
    long double val2 = 3515315.153151;
    float val3 = 5.5;
    double val4 = 9851.51351;
    long double val5 = 95919539159.53151351131;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
        sprintf(str2, format, val, val1, val2, val3, val4, val5));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_87) {
    char str1[512];
    char str2[512];
    char *format = "%.17Le";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_88) {
    char str1[512];
    char str2[512];
    char *format = "%.0Le";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_89) {
    char str1[512];
    char str2[512];
    char *format = "%.Le";
    long double val = 15.000009121;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_90) {
    char str1[512];
    char str2[512];
    char *format = "%.15Le";
    long double val = 0.000000000000000123;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_91) {
    char str1[512];
    char str2[512];
    char *format = "%.15Le";
    long double val = -15.35581134;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_92) {
    char str1[512];
    char str2[512];
    char *format = "%Le";
    long double val = 72537572375.1431341;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_93) {
    char str1[512];
    char str2[512];
    char *format = "%015E";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_94) {
    char str1[512];
    char str2[512];
    char *format = "%15e";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_95) {
    char str1[512];
    char str2[512];
    char *format = "% .0e %.le %Le %e %le %Le";
    float val = 0;
    double val1 = 0;
    long double val2 = 3515315.153151;
    float val3 = 5.5;
    double val4 = 0.094913941;
    long double val5 = 95919539159.53151351131;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
        sprintf(str2, format, val, val1, val2, val3, val4, val5));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_96) {
    char str1[512];
    char str2[512];
    char *format = "%.17LE";
    long double val = 4134121;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_97) {
    char str1[512];
    char str2[512];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_98) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_99) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_100) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_101) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                     sprintf(str2, "%s", "Drop Sega PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_102) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
        sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_103) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_104) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_105) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_106) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_107) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                     sprintf(str2, "%f", 0.0001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_108) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_109) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                     sprintf(str2, "%u", (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_110) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_111) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_112) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                     sprintf(str2, "%-8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_113) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(s21_sprintf_test_114) {
    char str1[512];
    char str2[512];
    ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                     sprintf(str2, "%x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                     sprintf(str2, "%x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_115) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                     sprintf(str2, "%X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                     sprintf(str2, "%X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_116) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_117) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(s21_sprintf_test_118) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                     sprintf(str2, "%-3x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                     sprintf(str2, "%-3x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_119) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                     sprintf(str2, "%13x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                     sprintf(str2, "%13x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_120) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                     sprintf(str2, "%-60X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                     sprintf(str2, "%-60X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_121) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                     sprintf(str2, "%7X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                     sprintf(str2, "%7X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_122) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_123) {
    char str1[512];
    char str2[512];
    ck_assert_int_eq(
        s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(s21_sprintf_test_124) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                     sprintf(str2, "%#x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                     sprintf(str2, "%#x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_125) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                     sprintf(str2, "%#X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                     sprintf(str2, "%#X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_126) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535,
                                 -13, -0, 123213123),
                     sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13,
                             -0, 123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_127) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535,
                                 -13, -0, 123213123),
                     sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13,
                             -0, 123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(s21_sprintf_test_128) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                     sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                     sprintf(str2, "%*x", 11, 0));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                     sprintf(str2, "%*x", 11, INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_129) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                     sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                     sprintf(str2, "%*X", 11, 0));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                     sprintf(str2, "%*X", 11, INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_130) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251),
                     sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                             199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_131) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251),
                     sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                             199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(s21_sprintf_test_132) {
    char str1[512];
    char str2[512];

    int a = s21_sprintf(str1, "%*.6x", 11, 0);
    int b = sprintf(str2, "%*.6x", 11, 0);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_133) {
    char str1[512];
    char str2[512];

    int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
    int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_134) {
    char str1[512];
    char str2[512];
    int a = s21_sprintf(
        str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
        4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
    int b = sprintf(
        str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
        4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_135) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(
        s21_sprintf(str1,
                    "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
                    -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                    41, -41, 33),
        sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
                -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
                -41, 33));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(s21_sprintf_test_136) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                     sprintf(str2, "%hx", (unsigned short)-11));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                     sprintf(str2, "%hx", (unsigned short)0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                     sprintf(str2, "%hx", (unsigned short)11));
    ck_assert_str_eq(str1, str2);
    long unsigned int val = INT32_MAX;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
    ck_assert_str_eq(str1, str2);
    long unsigned int v = 0;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_137) {
    char str1[512];
    char str2[512];

    ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                     sprintf(str2, "%hx", (unsigned short)-11));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                     sprintf(str2, "%hx", (unsigned short)0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                     sprintf(str2, "%hx", (unsigned short)11));
    ck_assert_str_eq(str1, str2);
    long unsigned int val = INT32_MAX;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
    ck_assert_str_eq(str1, str2);
    long unsigned int v = 0;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_138) {
    char str1[512];
    char str2[512];
    char format[] = "%10ld";

    ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_139) {
    char str1[512];
    char str2[512];
    char format[] = "%1.1f";

    ck_assert_int_eq(s21_sprintf(str1, format, 1.1),
                     sprintf(str2, format, 1.1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_140) {
    char str1[512];
    char str2[512];
    char format[] = "%8.3c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_141) {
    char str1[512];
    char str2[512];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    int a = s21_sprintf(str1, format, val);
    int b = sprintf(str2, format, val);
    ck_assert_int_eq(a, b);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_142) {
    char str1[512];
    char str2[512];
    char format[] = "%7.7f";

    ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                     sprintf(str2, format, 11.123456));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_143) {
    char str1[512];
    char str2[512];
    char format[] = "%7.4s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                     sprintf(str2, format, "aboba floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_144) {
    char str1[512];
    char str2[512];
    char format[] = "%6.6u";

    ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                     sprintf(str2, format, 12341151));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_145) {
    char str1[512];
    char str2[512];
    char format[] = "%li%ld%lu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                     sprintf(str2, format, 666666666666, 777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_146) {
    char str1[512];
    char str2[512];
    char format[] = "%hi%hd%hu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                     sprintf(str2, format, 666, -777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_147) {
    char str1[512];
    char str2[512];
    char format[] = "%+li%+lu%+d%+lf";

    ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                     sprintf(str2, format, -123, 321, -5555, -1213.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_148) {
    char str1[512];
    char str2[512];
    char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
    long double k = 333.33213;

    ck_assert_int_eq(
        s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
        sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_149) {
    char str1[512];
    char str2[512];
    char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_150) {
    char str1[512];
    char str2[512];
    char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_151) {
    char str1[512];
    char str2[512];
    char format[] = "% c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_152) {
    char str1[512];
    char str2[512];
    char format[] = "% s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                     sprintf(str2, format, "aboba likes floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_153) {
    char str1[512];
    char str2[512];
    char format[] = "% s% c";

    ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                     sprintf(str2, format, "", 'f'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_154) {
    char str1[512];
    char str2[512];
    char format[] = "%210s";

    ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                     sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_155) {
    char str1[512];
    char str2[512];
    char format[] = "%-115s";

    ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                     sprintf(str2, format, "Nick her"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_156) {
    char str1[512];
    char str2[512];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                    "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666,
                "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_157) {
    char str1[512];
    char str2[512];
    char format[] = "%.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                     sprintf(str2, format, 121.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_158) {
    char str1[512];
    char str2[512];
    char format[] = "%%";

    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_159) {
    char str1[512];
    char str2[512];
    char format[] = "%%%%%%%%";

    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_160) {
    char str1[512];
    char str2[512];
    int n1;
    int n2;
    int a = s21_sprintf(str1, "%d%n", 123, &n1);
    int b = sprintf(str2, "%d%n", 123, &n2);

    ck_assert_int_eq(a, b);
    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_161) {
    char str1[512];
    char str2[512];
    char format[] = "%-.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                     sprintf(str2, format, 111.111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_162) {
    char str1[512];
    char str2[512];
    char format[] = "%-.1d";

    ck_assert_int_eq(s21_sprintf(str1, format, 111),
                     sprintf(str2, format, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_163) {
    char str1[512];
    char str2[512];
    char format[] = "%e";
    double x = 111;
    ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_164) {
    char str1[512];
    char str2[512];
    char format[] = "%e%e%e%e";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
        sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_165) {
    char str1[512];
    char str2[512];
    char format[] = "%Le";
    long double x = 122.1231;

    ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_166) {
    char str1[512];
    char str2[512];
    char format[] = "%.10e";

    ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                     sprintf(str2, format, 111.184314818));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_167) {
    char str1[512];
    char str2[512];
    char format[] = "%5.3e%3.2e%lf";

    ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                     sprintf(str2, format, 0.000111, 111.555, 1.999));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_168) {
    char str1[512];
    char str2[512];
    char format[] = "%E";

    ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                     sprintf(str2, format, 0.666666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_169) {
    char str1[512];
    char str2[512];
    char format[] = "%E%E%E";

    ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                     sprintf(str2, format, 0.0000999, 111.9999, 6.666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_170) {
    char str1[512];
    char str2[512];
    char format[] = "%e ABOBA %Lf %Lf %Le";
    long double c = 848181;
    long double a = 0.00000001;
    long double b = 1111111.11;
    ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                     sprintf(str2, format, 123.123, a, b, c));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_171) {
    char str1[512];
    char str2[512];
    char format[] = "%#e Floppa %#E%#f";

    ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                     sprintf(str2, format, 123.111, 0.0000999, 0.555));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_172) {
    char str1[512];
    char str2[512];
    char format[] = "%.Lf";
    long double a = 7.9418438184;

    ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_173) {
    char str1[512];
    char str2[512];
    char format[] = "%#5p";
    int a = 5;
    ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_174) {
    char str1[512];
    char str2[512];
    char format[] = "%.5o";

    ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                     sprintf(str2, format, 12345));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_175) {
    char str1[512];
    char str2[512];
    char format[] = "%#5lX";
    long hex = 314818438141;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_176) {
    char str1[512];
    char str2[512];
    char format[] = "%g";
    double hex = 0.50300;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_177) {
    char str1[512];
    char str2[512];
    char format[] = "%g";
    double hex = 5131.43141;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_178) {
    char str1[512];
    char str2[512];
    char format[] = "%g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_179) {
    char str1[512];
    char str2[512];
    char format[] = "%.5g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_180) {
    char str1[512];
    char str2[512];
    char format[] = "%.0g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_181) {
    char str1[512];
    char str2[512];
    char format[] = "%.g";
    double hex = 0.123000;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(s21_sprintf_test_182) {
    char str1[512];
    char str2[512];
    char format[] = "%.g";
    double hex = 0.0004;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_183) {
    char str1[512];
    char str2[512];
    char format[] = "%g";
    double hex = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_184) {
    char str1[512];
    char str2[512];
    char format[] = "%.5g";
    double hex = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_185) {
    char str1[512];
    char str2[512];
    char format[] = "%g";
    double hex = 0.0000005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_186) {
    char str1[512];
    char str2[512];
    char format[] = "%5.8g";
    double hex = 0.0000005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_187) {
    char str1[512];
    char str2[512];
    char format[] = "%g";
    double hex = 0.005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_188) {
    char str1[512];
    char str2[512];
    char format[] = "%LG";
    long double hex = 0.000005;
    ck_assert_int_eq(s21_sprintf(str1, format, hex),
                     sprintf(str2, format, hex));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_189) {
    char str1[512];
    char str2[512];
    char format[] = "%LG %g %G %Lg %.5g";
    long double hex = 0.000005;
    double hex1 = 41.1341;
    double hex2 = 848.9000;
    long double hex3 = 0.0843;
    double hex4 = 0.0005;
    double hex5 = 0.8481481;
    ck_assert_int_eq(
        s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
        sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_190) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %lc";
    unsigned long w = L'汉';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}

START_TEST(s21_sprintf_test_191) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %5c";
    char w = 'c';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
START_TEST(s21_sprintf_test_192) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %-5lc";
    unsigned long w = L'森';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_193) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_194) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %5.12ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_195) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %120ls ABOBA";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_196) {
    char str1[512];
    char str2[512];

    char *format = "This is a simple wide char %-43ls";
    wchar_t w[] = L"森我爱菠萝";
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}
END_TEST
// ================================================================================================================

Suite *s21_memchr_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memchr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memchr_test_1);
  tcase_add_test(tc_core, s21_memchr_test_2);
  tcase_add_test(tc_core, s21_memchr_test_3);
  tcase_add_test(tc_core, s21_memchr_test_4);
  tcase_add_test(tc_core, s21_memchr_test_5);
  tcase_add_test(tc_core, s21_memchr_test_6);
  tcase_add_test(tc_core, s21_memchr_test_7);
  tcase_add_test(tc_core, s21_memchr_test_8);
  tcase_add_test(tc_core, s21_memchr_test_9);
  tcase_add_test(tc_core, s21_memchr_test_10);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strchr_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strchr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strchr_test_1);
  tcase_add_test(tc_core, s21_strchr_test_2);
  tcase_add_test(tc_core, s21_strchr_test_3);
  tcase_add_test(tc_core, s21_strchr_test_4);
  tcase_add_test(tc_core, s21_strchr_test_5);
  tcase_add_test(tc_core, s21_strchr_test_6);
  tcase_add_test(tc_core, s21_strchr_test_7);
  tcase_add_test(tc_core, s21_strchr_test_8);
  tcase_add_test(tc_core, s21_strchr_test_9);
  tcase_add_test(tc_core, s21_strchr_test_10);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strrchr_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strrchr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strrchr_test_1);
  tcase_add_test(tc_core, s21_strrchr_test_2);
  tcase_add_test(tc_core, s21_strrchr_test_3);
  tcase_add_test(tc_core, s21_strrchr_test_4);
  tcase_add_test(tc_core, s21_strrchr_test_5);
  tcase_add_test(tc_core, s21_strrchr_test_6);
  tcase_add_test(tc_core, s21_strrchr_test_7);
  tcase_add_test(tc_core, s21_strrchr_test_8);
  tcase_add_test(tc_core, s21_strrchr_test_9);
  tcase_add_test(tc_core, s21_strrchr_test_10);
  tcase_add_test(tc_core, s21_strrchr_test_11);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strpbrk_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strpbrk");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strpbrk_test_1);
  tcase_add_test(tc_core, s21_strpbrk_test_2);
  tcase_add_test(tc_core, s21_strpbrk_test_3);
  tcase_add_test(tc_core, s21_strpbrk_test_4);
  tcase_add_test(tc_core, s21_strpbrk_test_5);
  tcase_add_test(tc_core, s21_strpbrk_test_6);
  tcase_add_test(tc_core, s21_strpbrk_test_7);
  tcase_add_test(tc_core, s21_strpbrk_test_8);
  tcase_add_test(tc_core, s21_strpbrk_test_9);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strstr_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strstr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strstr_test_1);
  tcase_add_test(tc_core, s21_strstr_test_2);
  tcase_add_test(tc_core, s21_strstr_test_3);
  tcase_add_test(tc_core, s21_strstr_test_4);
  tcase_add_test(tc_core, s21_strstr_test_5);
  tcase_add_test(tc_core, s21_strstr_test_6);
  tcase_add_test(tc_core, s21_strstr_test_7);
  tcase_add_test(tc_core, s21_strstr_test_8);
  tcase_add_test(tc_core, s21_strstr_test_9);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strlen_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strlen");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strlen_test_1);
  tcase_add_test(tc_core, s21_strlen_test_2);
  tcase_add_test(tc_core, s21_strlen_test_3);
  tcase_add_test(tc_core, s21_strlen_test_4);
  tcase_add_test(tc_core, s21_strlen_test_5);
  tcase_add_test(tc_core, s21_strlen_test_6);
  tcase_add_test(tc_core, s21_strlen_test_7);
  tcase_add_test(tc_core, s21_strlen_test_8);

  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_memset_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memset");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memset_test_1);
  tcase_add_test(tc_core, s21_memset_test_2);
  tcase_add_test(tc_core, s21_memset_test_3);
  tcase_add_test(tc_core, s21_memset_test_4);
  tcase_add_test(tc_core, s21_memset_test_5);
  tcase_add_test(tc_core, s21_memset_test_6);
  tcase_add_test(tc_core, s21_memset_test_7);
  tcase_add_test(tc_core, s21_memset_test_8);
  tcase_add_test(tc_core, s21_memset_test_9);
  tcase_add_test(tc_core, s21_memset_test_10);
  tcase_add_test(tc_core, s21_memset_test_11);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strncpy_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncpy");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strncpy_test_1);
  tcase_add_test(tc_core, s21_strncpy_test_2);
  tcase_add_test(tc_core, s21_strncpy_test_3);
  tcase_add_test(tc_core, s21_strncpy_test_4);
  tcase_add_test(tc_core, s21_strncpy_test_5);
  tcase_add_test(tc_core, s21_strncpy_test_6);
  tcase_add_test(tc_core, s21_strncpy_test_7);
  tcase_add_test(tc_core, s21_strncpy_test_8);
  tcase_add_test(tc_core, s21_strncpy_test_9);
  tcase_add_test(tc_core, s21_strncpy_test_10);
  tcase_add_test(tc_core, s21_strncpy_test_11);
  tcase_add_test(tc_core, s21_strncpy_test_12);
  tcase_add_test(tc_core, s21_strncpy_test_13);
  tcase_add_test(tc_core, s21_strncpy_test_14);
  tcase_add_test(tc_core, s21_strncpy_test_15);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strncmp_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncmp");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strncmp_test_1);
  tcase_add_test(tc_core, s21_strncmp_test_2);
  tcase_add_test(tc_core, s21_strncmp_test_3);
  tcase_add_test(tc_core, s21_strncmp_test_4);
  tcase_add_test(tc_core, s21_strncmp_test_5);
  tcase_add_test(tc_core, s21_strncmp_test_6);
  tcase_add_test(tc_core, s21_strncmp_test_7);
  tcase_add_test(tc_core, s21_strncmp_test_8);
  tcase_add_test(tc_core, s21_strncmp_test_9);
  tcase_add_test(tc_core, s21_strncmp_test_10);
  tcase_add_test(tc_core, s21_strncmp_test_11);
  tcase_add_test(tc_core, s21_strncmp_test_12);
  tcase_add_test(tc_core, s21_strncmp_test_13);
  tcase_add_test(tc_core, s21_strncmp_test_14);
  tcase_add_test(tc_core, s21_strncmp_test_15);
  tcase_add_test(tc_core, s21_strncmp_test_17);
  tcase_add_test(tc_core, s21_strncmp_test_18);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strcmp_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcmp");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strcmp_test_1);
  tcase_add_test(tc_core, s21_strcmp_test_2);
  tcase_add_test(tc_core, s21_strcmp_test_3);
  tcase_add_test(tc_core, s21_strcmp_test_4);
  tcase_add_test(tc_core, s21_strcmp_test_5);
  tcase_add_test(tc_core, s21_strcmp_test_6);
  tcase_add_test(tc_core, s21_strcmp_test_7);
  tcase_add_test(tc_core, s21_strcmp_test_8);
  tcase_add_test(tc_core, s21_strcmp_test_9);
  tcase_add_test(tc_core, s21_strcmp_test_10);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_memmove_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memmove");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memmove_test_1);
  tcase_add_test(tc_core, s21_memmove_test_2);
  tcase_add_test(tc_core, s21_memmove_test_3);
  tcase_add_test(tc_core, s21_memmove_test_4);
  tcase_add_test(tc_core, s21_memmove_test_5);
  tcase_add_test(tc_core, s21_memmove_test_6);
  tcase_add_test(tc_core, s21_memmove_test_7);
  tcase_add_test(tc_core, s21_memmove_test_8);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strcpy_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcpy");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strcpy_test_1);
  tcase_add_test(tc_core, s21_strcpy_test_2);
  tcase_add_test(tc_core, s21_strcpy_test_3);
  tcase_add_test(tc_core, s21_strcpy_test_4);
  tcase_add_test(tc_core, s21_strcpy_test_5);
  tcase_add_test(tc_core, s21_strcpy_test_6);
  tcase_add_test(tc_core, s21_strcpy_test_7);
  tcase_add_test(tc_core, s21_strcpy_test_8);
  tcase_add_test(tc_core, s21_strcpy_test_9);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_memcpy_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcpy");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memcpy_test_1);
  tcase_add_test(tc_core, s21_memcpy_test_2);
  tcase_add_test(tc_core, s21_memcpy_test_3);
  tcase_add_test(tc_core, s21_memcpy_test_4);
  tcase_add_test(tc_core, s21_memcpy_test_5);
  tcase_add_test(tc_core, s21_memcpy_test_6);
  tcase_add_test(tc_core, s21_memcpy_test_7);
  tcase_add_test(tc_core, s21_memcpy_test_8);
  tcase_add_test(tc_core, s21_memcpy_test_9);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strtok_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strtok");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strtok_test_1);
  tcase_add_test(tc_core, s21_strtok_test_2);
  tcase_add_test(tc_core, s21_strtok_test_3);
  tcase_add_test(tc_core, s21_strtok_test_4);
  tcase_add_test(tc_core, s21_strtok_test_5);
  tcase_add_test(tc_core, s21_strtok_test_6);
  tcase_add_test(tc_core, s21_strtok_test_7);
  tcase_add_test(tc_core, s21_strtok_test_8);
  tcase_add_test(tc_core, s21_strtok_test_9);
  tcase_add_test(tc_core, s21_strtok_test_10);
  tcase_add_test(tc_core, s21_strtok_test_11);
  tcase_add_test(tc_core, s21_strtok_test_12);
  tcase_add_test(tc_core, s21_strtok_test_13);
  tcase_add_test(tc_core, s21_strtok_test_14);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strcat_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcat");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strcat_test_1);
  tcase_add_test(tc_core, s21_strcat_test_2);
  tcase_add_test(tc_core, s21_strcat_test_3);
  tcase_add_test(tc_core, s21_strcat_test_4);
  tcase_add_test(tc_core, s21_strcat_test_5);
  tcase_add_test(tc_core, s21_strcat_test_6);
  tcase_add_test(tc_core, s21_strcat_test_7);
  tcase_add_test(tc_core, s21_strcat_test_8);
  tcase_add_test(tc_core, s21_strcat_test_9);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_memcmp_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("memcmp");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memcmp_test_1);
  tcase_add_test(tc_core, s21_memcmp_test_2);
  tcase_add_test(tc_core, s21_memcmp_test_3);
  tcase_add_test(tc_core, s21_memcmp_test_4);
  tcase_add_test(tc_core, s21_memcmp_test_5);
  tcase_add_test(tc_core, s21_memcmp_test_6);
  tcase_add_test(tc_core, s21_memcmp_test_7);
  tcase_add_test(tc_core, s21_memcmp_test_8);
  tcase_add_test(tc_core, s21_memcmp_test_9);
  tcase_add_test(tc_core, s21_memcmp_test_10);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strspn_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strspn");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strspn_test_1);
  tcase_add_test(tc_core, s21_strspn_test_2);
  tcase_add_test(tc_core, s21_strspn_test_3);
  tcase_add_test(tc_core, s21_strspn_test_4);
  tcase_add_test(tc_core, s21_strspn_test_5);
  tcase_add_test(tc_core, s21_strspn_test_6);
  tcase_add_test(tc_core, s21_strspn_test_7);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strncat_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strncat");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strncat_test_1);
  tcase_add_test(tc_core, s21_strncat_test_2);
  tcase_add_test(tc_core, s21_strncat_test_3);
  tcase_add_test(tc_core, s21_strncat_test_4);
  tcase_add_test(tc_core, s21_strncat_test_5);
  tcase_add_test(tc_core, s21_strncat_test_6);
  tcase_add_test(tc_core, s21_strncat_test_7);
  tcase_add_test(tc_core, s21_strncat_test_8);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strcspn_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strcspn");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strcspn_test_1);
  tcase_add_test(tc_core, s21_strcspn_test_2);
  tcase_add_test(tc_core, s21_strcspn_test_3);
  tcase_add_test(tc_core, s21_strcspn_test_4);
  tcase_add_test(tc_core, s21_strcspn_test_5);
  tcase_add_test(tc_core, s21_strcspn_test_6);
  tcase_add_test(tc_core, s21_strcspn_test_7);
  tcase_add_test(tc_core, s21_strcspn_test_8);
  tcase_add_test(tc_core, s21_strcspn_test_9);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_strerror_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("strerror");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strerror_test_1);
  tcase_add_test(tc_core, s21_strerror_test_2);
  tcase_add_test(tc_core, s21_strerror_test_3);
  tcase_add_test(tc_core, s21_strerror_test_4);
  tcase_add_test(tc_core, s21_strerror_test_5);
  tcase_add_test(tc_core, s21_strerror_test_6);
  tcase_add_test(tc_core, s21_strerror_test_7);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_to_lower_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("lower");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_to_lower_test_1);
  tcase_add_test(tc_core, s21_to_lower_test_2);
  tcase_add_test(tc_core, s21_to_lower_test_3);
  tcase_add_test(tc_core, s21_to_lower_test_4);
  tcase_add_test(tc_core, s21_to_lower_test_5);
  tcase_add_test(tc_core, s21_to_lower_test_6);
  tcase_add_test(tc_core, s21_to_lower_test_7);
  tcase_add_test(tc_core, s21_to_lower_test_8);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_to_upper_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("upper");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_to_upper_test_1);
  tcase_add_test(tc_core, s21_to_upper_test_2);
  tcase_add_test(tc_core, s21_to_upper_test_3);
  tcase_add_test(tc_core, s21_to_upper_test_4);
  tcase_add_test(tc_core, s21_to_upper_test_5);
  tcase_add_test(tc_core, s21_to_upper_test_6);
  tcase_add_test(tc_core, s21_to_upper_test_7);
  tcase_add_test(tc_core, s21_to_upper_test_8);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_trim_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("trim");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_trim_test_1);
  tcase_add_test(tc_core, s21_trim_test_2);
  tcase_add_test(tc_core, s21_trim_test_3);
  tcase_add_test(tc_core, s21_trim_test_4);
  tcase_add_test(tc_core, s21_trim_test_5);
  tcase_add_test(tc_core, s21_trim_test_6);
  tcase_add_test(tc_core, s21_trim_test_7);
  tcase_add_test(tc_core, s21_trim_test_8);
  tcase_add_test(tc_core, s21_trim_test_9);
  tcase_add_test(tc_core, s21_trim_test_10);
  tcase_add_test(tc_core, s21_trim_test_11);
  tcase_add_test(tc_core, s21_trim_test_12);
  tcase_add_test(tc_core, s21_trim_test_13);
  tcase_add_test(tc_core, s21_trim_test_14);
  suite_add_tcase(s, tc_core);

  return s;
}

Suite *s21_insert_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("insert");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_insert_test_1);
  tcase_add_test(tc_core, s21_insert_test_2);
  tcase_add_test(tc_core, s21_insert_test_3);
  tcase_add_test(tc_core, s21_insert_test_4);
  tcase_add_test(tc_core, s21_insert_test_5);
  tcase_add_test(tc_core, s21_insert_test_6);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_sprintf_ste(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("spintf");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_sprintf_test_1);
  tcase_add_test(tc_core, s21_sprintf_test_2);
  tcase_add_test(tc_core, s21_sprintf_test_3);
  tcase_add_test(tc_core, s21_sprintf_test_4);
  tcase_add_test(tc_core, s21_sprintf_test_5);
  tcase_add_test(tc_core, s21_sprintf_test_6);
  tcase_add_test(tc_core, s21_sprintf_test_7);
  tcase_add_test(tc_core, s21_sprintf_test_8);
  tcase_add_test(tc_core, s21_sprintf_test_9);
  tcase_add_test(tc_core, s21_sprintf_test_10);
  tcase_add_test(tc_core, s21_sprintf_test_11);
  tcase_add_test(tc_core, s21_sprintf_test_12);
  tcase_add_test(tc_core, s21_sprintf_test_13);
  tcase_add_test(tc_core, s21_sprintf_test_14);
  tcase_add_test(tc_core, s21_sprintf_test_15);
  tcase_add_test(tc_core, s21_sprintf_test_int_16);
  tcase_add_test(tc_core, s21_sprintf_test_int_17);
  tcase_add_test(tc_core, s21_sprintf_test_int_18);
  tcase_add_test(tc_core, s21_sprintf_test_int_19);
  tcase_add_test(tc_core, s21_sprintf_test_int_20);
  tcase_add_test(tc_core, s21_sprintf_test_int_21);
  tcase_add_test(tc_core, s21_sprintf_test_int_22);
  tcase_add_test(tc_core, s21_sprintf_test_int_23);
  tcase_add_test(tc_core, s21_sprintf_test_int_24);
  tcase_add_test(tc_core, s21_sprintf_test_int_25);
  tcase_add_test(tc_core, s21_sprintf_test_int_26);
  tcase_add_test(tc_core, s21_sprintf_test_int_27);
  tcase_add_test(tc_core, s21_sprintf_test_int_28);
  tcase_add_test(tc_core, s21_sprintf_test_int_29);
  tcase_add_test(tc_core, s21_sprintf_test_val_30);
  tcase_add_test(tc_core, s21_sprintf_test_val_31);
  tcase_add_test(tc_core, s21_sprintf_test_val_32);
  tcase_add_test(tc_core, s21_sprintf_test_val_33);
  tcase_add_test(tc_core, s21_sprintf_test_val_34);
  tcase_add_test(tc_core, s21_sprintf_test_val_35);
  tcase_add_test(tc_core, s21_sprintf_test_val_36);
  tcase_add_test(tc_core, s21_sprintf_test_val_37);
  tcase_add_test(tc_core, s21_sprintf_test_val_38);
  tcase_add_test(tc_core, s21_sprintf_test_octal_39);
  tcase_add_test(tc_core, s21_sprintf_test_octal_40);
  tcase_add_test(tc_core, s21_sprintf_test_octal_41);
  tcase_add_test(tc_core, s21_sprintf_test_octal_42);
  tcase_add_test(tc_core, s21_sprintf_test_octal_43);
  tcase_add_test(tc_core, s21_sprintf_test_octal_44);
  tcase_add_test(tc_core, s21_sprintf_test_octal_45);
  tcase_add_test(tc_core, s21_sprintf_test_octal_46);
  tcase_add_test(tc_core, s21_sprintf_test_octal_47);
  tcase_add_test(tc_core, s21_sprintf_test_zero_48);
  tcase_add_test(tc_core, s21_sprintf_test_hex_49);
  tcase_add_test(tc_core, s21_sprintf_test_hex_50);
  tcase_add_test(tc_core, s21_sprintf_test_hex_51);
  tcase_add_test(tc_core, s21_sprintf_test_hex_52);
  tcase_add_test(tc_core, s21_sprintf_test_hex_53);
  tcase_add_test(tc_core, s21_sprintf_test_hex_54);
  tcase_add_test(tc_core, s21_sprintf_test_hex_55);
  tcase_add_test(tc_core, s21_sprintf_test_hex_56);
  tcase_add_test(tc_core, s21_sprintf_test_hex_57);
  tcase_add_test(tc_core, s21_sprintf_test_hex_58);
  tcase_add_test(tc_core, s21_sprintf_test_hex_59);
  tcase_add_test(tc_core, s21_sprintf_test_60);
  tcase_add_test(tc_core, s21_sprintf_test_61);
  tcase_add_test(tc_core, s21_sprintf_test_62);
  tcase_add_test(tc_core, s21_sprintf_test_63);
  tcase_add_test(tc_core, s21_sprintf_test_64);
  tcase_add_test(tc_core, s21_sprintf_test_65);
  tcase_add_test(tc_core, s21_sprintf_test_string_66);
  tcase_add_test(tc_core, s21_sprintf_test_string_67);
  tcase_add_test(tc_core, s21_sprintf_test_string_68);
  tcase_add_test(tc_core, s21_sprintf_test_string_69);
  tcase_add_test(tc_core, s21_sprintf_test_string_70);
  tcase_add_test(tc_core, s21_sprintf_test_string_71);
  tcase_add_test(tc_core, s21_sprintf_test_ptr_72);
  tcase_add_test(tc_core, s21_sprintf_test_ptr_73);
  tcase_add_test(tc_core, s21_sprintf_test_ptr_74);
  tcase_add_test(tc_core, s21_sprintf_test_ptr_75);
  tcase_add_test(tc_core, s21_sprintf_test_76);
  tcase_add_test(tc_core, s21_sprintf_test_77);
  tcase_add_test(tc_core, s21_sprintf_test_78);
  tcase_add_test(tc_core, s21_sprintf_test_79);
  tcase_add_test(tc_core, s21_sprintf_test_80);
  tcase_add_test(tc_core, s21_sprintf_test_81);
  tcase_add_test(tc_core, s21_sprintf_test_82);
  tcase_add_test(tc_core, s21_sprintf_test_83);
  tcase_add_test(tc_core, s21_sprintf_test_84);
  tcase_add_test(tc_core, s21_sprintf_test_85);
  tcase_add_test(tc_core, s21_sprintf_test_86);
  tcase_add_test(tc_core, s21_sprintf_test_87);
  tcase_add_test(tc_core, s21_sprintf_test_88);
  tcase_add_test(tc_core, s21_sprintf_test_89);
  tcase_add_test(tc_core, s21_sprintf_test_90);
  tcase_add_test(tc_core, s21_sprintf_test_91);
  tcase_add_test(tc_core, s21_sprintf_test_92);
  tcase_add_test(tc_core, s21_sprintf_test_93);
  tcase_add_test(tc_core, s21_sprintf_test_94);
  tcase_add_test(tc_core, s21_sprintf_test_95);
  tcase_add_test(tc_core, s21_sprintf_test_96);
  tcase_add_test(tc_core, s21_sprintf_test_97);
  tcase_add_test(tc_core, s21_sprintf_test_98);
  tcase_add_test(tc_core, s21_sprintf_test_99);
  tcase_add_test(tc_core, s21_sprintf_test_100);
  tcase_add_test(tc_core, s21_sprintf_test_101);
  tcase_add_test(tc_core, s21_sprintf_test_102);
  tcase_add_test(tc_core, s21_sprintf_test_103);
  tcase_add_test(tc_core, s21_sprintf_test_104);
  tcase_add_test(tc_core, s21_sprintf_test_105);
  tcase_add_test(tc_core, s21_sprintf_test_106);
  tcase_add_test(tc_core, s21_sprintf_test_107);
  tcase_add_test(tc_core, s21_sprintf_test_108);
  tcase_add_test(tc_core, s21_sprintf_test_109);
  tcase_add_test(tc_core, s21_sprintf_test_110);
  tcase_add_test(tc_core, s21_sprintf_test_111);
  tcase_add_test(tc_core, s21_sprintf_test_112);
  tcase_add_test(tc_core, s21_sprintf_test_113);
  tcase_add_test(tc_core, s21_sprintf_test_114);
  tcase_add_test(tc_core, s21_sprintf_test_115);
  tcase_add_test(tc_core, s21_sprintf_test_116);
  tcase_add_test(tc_core, s21_sprintf_test_117);
  tcase_add_test(tc_core, s21_sprintf_test_118);
  tcase_add_test(tc_core, s21_sprintf_test_119);
  tcase_add_test(tc_core, s21_sprintf_test_120);
  tcase_add_test(tc_core, s21_sprintf_test_121);
  tcase_add_test(tc_core, s21_sprintf_test_122);
  tcase_add_test(tc_core, s21_sprintf_test_123);
  tcase_add_test(tc_core, s21_sprintf_test_124);
  tcase_add_test(tc_core, s21_sprintf_test_125);
  tcase_add_test(tc_core, s21_sprintf_test_126);
  tcase_add_test(tc_core, s21_sprintf_test_127);
  tcase_add_test(tc_core, s21_sprintf_test_128);
  tcase_add_test(tc_core, s21_sprintf_test_129);
  tcase_add_test(tc_core, s21_sprintf_test_130);
  tcase_add_test(tc_core, s21_sprintf_test_131);
  tcase_add_test(tc_core, s21_sprintf_test_132);
  tcase_add_test(tc_core, s21_sprintf_test_133);
  tcase_add_test(tc_core, s21_sprintf_test_134);
  tcase_add_test(tc_core, s21_sprintf_test_135);
  tcase_add_test(tc_core, s21_sprintf_test_136);
  tcase_add_test(tc_core, s21_sprintf_test_137);
  tcase_add_test(tc_core, s21_sprintf_test_138);
  tcase_add_test(tc_core, s21_sprintf_test_139);
  tcase_add_test(tc_core, s21_sprintf_test_140);
  tcase_add_test(tc_core, s21_sprintf_test_141);
  tcase_add_test(tc_core, s21_sprintf_test_142);
  tcase_add_test(tc_core, s21_sprintf_test_143);
  tcase_add_test(tc_core, s21_sprintf_test_144);
  tcase_add_test(tc_core, s21_sprintf_test_145);
  tcase_add_test(tc_core, s21_sprintf_test_146);
  tcase_add_test(tc_core, s21_sprintf_test_147);
  tcase_add_test(tc_core, s21_sprintf_test_148);
  tcase_add_test(tc_core, s21_sprintf_test_149);
  tcase_add_test(tc_core, s21_sprintf_test_150);
  tcase_add_test(tc_core, s21_sprintf_test_151);
  tcase_add_test(tc_core, s21_sprintf_test_152);
  tcase_add_test(tc_core, s21_sprintf_test_153);
  tcase_add_test(tc_core, s21_sprintf_test_154);
  tcase_add_test(tc_core, s21_sprintf_test_155);
  tcase_add_test(tc_core, s21_sprintf_test_156);
  tcase_add_test(tc_core, s21_sprintf_test_157);
  tcase_add_test(tc_core, s21_sprintf_test_158);
  tcase_add_test(tc_core, s21_sprintf_test_159);
  tcase_add_test(tc_core, s21_sprintf_test_160);
  tcase_add_test(tc_core, s21_sprintf_test_161);
  tcase_add_test(tc_core, s21_sprintf_test_162);
  tcase_add_test(tc_core, s21_sprintf_test_163);
  tcase_add_test(tc_core, s21_sprintf_test_164);
  tcase_add_test(tc_core, s21_sprintf_test_165);
  tcase_add_test(tc_core, s21_sprintf_test_166);
  tcase_add_test(tc_core, s21_sprintf_test_167);
  tcase_add_test(tc_core, s21_sprintf_test_168);
  tcase_add_test(tc_core, s21_sprintf_test_169);
  tcase_add_test(tc_core, s21_sprintf_test_170);
  tcase_add_test(tc_core, s21_sprintf_test_171);
  tcase_add_test(tc_core, s21_sprintf_test_172);
  tcase_add_test(tc_core, s21_sprintf_test_173);
  tcase_add_test(tc_core, s21_sprintf_test_174);
  tcase_add_test(tc_core, s21_sprintf_test_175);
  tcase_add_test(tc_core, s21_sprintf_test_176);
  tcase_add_test(tc_core, s21_sprintf_test_177);
  tcase_add_test(tc_core, s21_sprintf_test_178);
  tcase_add_test(tc_core, s21_sprintf_test_179);
  tcase_add_test(tc_core, s21_sprintf_test_180);
  tcase_add_test(tc_core, s21_sprintf_test_181);
  tcase_add_test(tc_core, s21_sprintf_test_182);
  tcase_add_test(tc_core, s21_sprintf_test_182);
  tcase_add_test(tc_core, s21_sprintf_test_183);
  tcase_add_test(tc_core, s21_sprintf_test_184);
  tcase_add_test(tc_core, s21_sprintf_test_185);
  tcase_add_test(tc_core, s21_sprintf_test_186);
  tcase_add_test(tc_core, s21_sprintf_test_187);
  tcase_add_test(tc_core, s21_sprintf_test_188);
  tcase_add_test(tc_core, s21_sprintf_test_189);
  tcase_add_test(tc_core, s21_sprintf_test_190);
  tcase_add_test(tc_core, s21_sprintf_test_191);
  tcase_add_test(tc_core, s21_sprintf_test_192);
  tcase_add_test(tc_core, s21_sprintf_test_193);
  tcase_add_test(tc_core, s21_sprintf_test_194);
  tcase_add_test(tc_core, s21_sprintf_test_195);
  tcase_add_test(tc_core, s21_sprintf_test_195);
  tcase_add_test(tc_core, s21_sprintf_test_196);

  suite_add_tcase(s, tc_core);

  return s;
}

int s21_str_test(Suite *s) {
  int SUCCESS = 0;
  SRunner *runner;
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  SUCCESS = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (SUCCESS == 0) ? 0 : 1;
}

int main(void) {
  s21_str_test(s21_memchr_ste());
  s21_str_test(s21_strchr_ste());
  s21_str_test(s21_strrchr_ste());
  s21_str_test(s21_strpbrk_ste());
  s21_str_test(s21_strstr_ste());
  s21_str_test(s21_strlen_ste());
  s21_str_test(s21_memset_ste());
  s21_str_test(s21_strncpy_ste());
  s21_str_test(s21_strncmp_ste());
  s21_str_test(s21_strcmp_ste());
  s21_str_test(s21_memmove_ste());
  s21_str_test(s21_strcpy_ste());
  s21_str_test(s21_memcpy_ste());
  s21_str_test(s21_strtok_ste());
  s21_str_test(s21_strcat_ste());
  s21_str_test(s21_memcmp_ste());
  s21_str_test(s21_strspn_ste());
  s21_str_test(s21_strncat_ste());
  s21_str_test(s21_strcspn_ste());
  s21_str_test(s21_strerror_ste());
  s21_str_test(s21_to_lower_ste());
  s21_str_test(s21_to_upper_ste());
  s21_str_test(s21_trim_ste());
  s21_str_test(s21_insert_ste());
  s21_str_test(s21_sprintf_ste());
  return (0);
}
