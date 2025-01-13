#include "test.h"

START_TEST(s21_memcmp_test0) {
  char test1[] = "54321";
  char test2[] = "54321";
  const char* plus = "5";

  ck_assert_uint_eq(s21_memcmp(test1, plus, 1), memcmp(test2, plus, 1));
}
END_TEST

START_TEST(s21_memcmp_test1) {
  char test1[] = "54321";
  char test2[] = "54321";
  const char* plus = "5321";

  ck_assert_uint_eq(s21_memcmp(test1, plus, 1), memcmp(test2, plus, 1));
}
END_TEST

START_TEST(s21_memcmp_test2) {
  char test1[] = "hello";
  char test2[] = "hello";
  const char* plus = "";

  ck_assert_uint_eq(s21_memcmp(test1, plus, 1), memcmp(test2, plus, 1));
}
END_TEST

START_TEST(s21_memcmp_test3) {
  char test1[] = " hello";
  char test2[] = " hello";
  const char* plus = " ";

  ck_assert_int_eq(s21_memcmp(test1, plus, 1), memcmp(test2, plus, 1));
}
END_TEST

START_TEST(s21_memcmp_test4) {
  char test1[] = "hello";
  char test2[] = "hello";
  const char* plus = "lo";

  ck_assert_uint_eq(s21_memcmp(test1, plus, 1), memcmp(test2, plus, 1));
}
END_TEST

Suite* s21_memcmp_test_suite() {
  Suite* s = suite_create("s21_memcmp");
  TCase* tc_case = tcase_create("s21_memcmp_case");
  tcase_add_test(tc_case, s21_memcmp_test0);
  tcase_add_test(tc_case, s21_memcmp_test1);
  tcase_add_test(tc_case, s21_memcmp_test2);
  tcase_add_test(tc_case, s21_memcmp_test3);
  tcase_add_test(tc_case, s21_memcmp_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memcmp_tests() {
  Suite* s = s21_memcmp_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}