CFLAGS = -Wall -Wextra -Werror
CC = -gcc -std=c11
SOURCE = s21_*.c
TARGET = s21_string
TEST_SOURCE = tests/*.c

all: s21_string.a

s21_string.a:
	$(CC) $(CFLAGS) $(SOURCE) -c
	ar rc $(TARGET).a *.o
	@rm *.o

clean:
	@rm -rf *.o *.a *.gcno *.gcda coverage.info test_runner coverage_report a.out

test: s21_string.a
	$(CC) $(CFLAGS) $(TEST_SOURCE) s21_string.a -o test_runner -lcheck -lm -lpthread
	-./test_runner

clang_format:
	clang-format -style=google -i *.c *.h
	clang-format -style=google -i tests/*.c tests/*.h

style:
	clang-format -style=google -n *.c *.h
	clang-format -style=google -n tests/*.c tests/*.h

valgrind: s21_string.a
	$(CC) $(CFLAGS) $(TEST_SOURCE) s21_string.a -o test_runner -lcheck -lsubunit -lm -lpthread
	./test_runner
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test_runner

gcov_report:
	$(CC) --coverage $(CFLAGS) $(SOURCE) -c
	ar rc $(TARGET).a *.o
	@rm *.o
	ranlib s21_string.a
	$(CC) --coverage $(CFLAGS) $(TEST_SOURCE) s21_string.a -o test_runner -lcheck -lm -lpthread
	./test_runner
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info
	lcov --remove coverage.info 'src/tests/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	open ./coverage_report/index.html

.PHONY: all clean