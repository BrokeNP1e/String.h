#include "test.h"

START_TEST(s21_memchr_test0) {
  char test1[] = "123456";
  char test2 = '4';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
}
END_TEST

START_TEST(s21_memchr_test1) {
  char test1[] = "123456";
  char test2 = '7';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
}
END_TEST

START_TEST(s21_memchr_test2) {
  char test1[] = "hello";
  char test2 = 'h';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 5),
                    (unsigned long)memchr(test1, test2, 5));
}
END_TEST

START_TEST(s21_memchr_test3) {
  char test1[] = "hello";
  char test2 = ' ';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 5),
                    (unsigned long)memchr(test1, test2, 5));
}
END_TEST

START_TEST(s21_memchr_test4) {
  char test1[] = "hello ";
  char test2 = ' ';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
}
END_TEST

START_TEST(s21_memchr_test5) {
  char test1[] = "hello";
  char test2 = '\0';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
}
END_TEST

START_TEST(s21_memchr_test6) {
  char test1[] = "hello/";
  char test2 = '/';

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
}
END_TEST

Suite* s21_memchr_test_suite() {
  Suite* s = suite_create("s21_memchr");
  TCase* tc_case = tcase_create("s21_memchr_case");
  tcase_add_test(tc_case, s21_memchr_test0);
  tcase_add_test(tc_case, s21_memchr_test1);
  tcase_add_test(tc_case, s21_memchr_test2);
  tcase_add_test(tc_case, s21_memchr_test3);
  tcase_add_test(tc_case, s21_memchr_test4);
  tcase_add_test(tc_case, s21_memchr_test5);
  tcase_add_test(tc_case, s21_memchr_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memchr_tests() {
  Suite* s = s21_memchr_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
