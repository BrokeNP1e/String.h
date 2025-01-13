#include "test.h"

START_TEST(s21_strncmp_test0) {
  char str1[] = "хhelloх";
  char str2[] = "х";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

START_TEST(s21_strncmp_test1) {
  char str1[] = "HELLO";
  char str2[] = "HELLO";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test2) {
  char str1[] = "hello";
  char str2[] = "hello";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test3) {
  char str1[] = "hello";
  char str2[] = "HELLO";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test4) {
  char str1[] = " ";
  char str2[] = " ";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
}
END_TEST

Suite* s21_strncmp_test_suite() {
  Suite* s = suite_create("s21_strncmp");
  TCase* tc_case = tcase_create("s21_strncmp_case");
  tcase_add_test(tc_case, s21_strncmp_test0);
  tcase_add_test(tc_case, s21_strncmp_test1);
  tcase_add_test(tc_case, s21_strncmp_test2);
  tcase_add_test(tc_case, s21_strncmp_test3);
  tcase_add_test(tc_case, s21_strncmp_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strncmp_tests() {
  Suite* s = s21_strncmp_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}