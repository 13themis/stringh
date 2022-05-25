CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g -fsanitize=address
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(CHECK_FLAGS) $(GCOV_FLAGS)
SRCS = s21_sprintf.c s21_memchr.c s21_memcmp.c s21_memcpy.c \
	   s21_memmove.c s21_memset.c s21_strcat.c \
	   s21_strpbrk.c s21_strchr.c s21_strcmp.c \
	   s21_strcpy.c s21_strspn.c s21_strcspn.c \
	   s21_strlen.c s21_strncat.c s21_strncmp.c \
	   s21_strncpy.c s21_strrchr.c s21_strstr.c \
	   s21_to_lower.c s21_strtok.c s21_strerror.c \
	   s21_insert.c s21_trim.c s21_to_upper.c \

OBJECT = $(SRCS:.c=.o)
NAME = test
REPORT_NAME = report

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: s21_string.a test clean gcov_report check

test: s21_string_test.o s21_string.a
	$(CC) $(CFLAGS) $(CHECK_FLAGS) $(OBJECT) s21_string_test.o -o $(NAME)
	make clean
clean_all:
	rm -rf $(OBJECT)
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.a
	rm -rf $(REPORT_NAME)
	rm $(NAME)
clean:
	rm -rf $(OBJECT)
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
s21_string.a: $(OBJECT)
	ar rc s21_string.a $(OBJECT)
	ranlib s21_string.a
gcov_report:
	$(CC) -o $(NAME) s21_string_test.c $(SRCS) $(ALL_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o s21_string_tests.info -c -d .
	genhtml -o $(REPORT_NAME) s21_string_tests.info
	rm $(NAME)
	make clean
check: s21_string.a
	@cppcheck *.h *.c
	@cppcheck -q --enable=all --inconclusive *.h *.c
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	@python3 ../materials/linters/cpplint.py --extension=c *.h *.h
	@$(CC) s21_string_test.c s21_string.a -lcheck
	@CK_FORK=no leaks --atExit -- ./a.out
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./a.out
	@rm CPPLINT.cfg
