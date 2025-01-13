#include "test.h"

START_TEST(s21_strlen_test0) {
  char test1[] = "Hello";
  char test2[] = "Hello";

  ck_assert_int_eq(s21_strlen(test1), strlen(test2));
}
END_TEST

START_TEST(s21_strlen_test1) {
  char test1[] = "";
  char test2[] = "";

  ck_assert_int_eq(s21_strlen(test1), strlen(test2));
}
END_TEST

START_TEST(s21_strlen_test2) {
  char test1[] = " ";
  char test2[] = " ";

  ck_assert_int_eq(s21_strlen(test1), strlen(test2));
}
END_TEST

START_TEST(s21_strlen_test3) {
  char test1[] = "1\0";
  char test2[] = "1\0";

  ck_assert_int_eq(s21_strlen(test1), strlen(test2));
}
END_TEST

START_TEST(s21_strlen_test4) {
  char test1[] = "1/45";
  char test2[] = "1/45";

  ck_assert_int_eq(s21_strlen(test1), strlen(test2));
}
END_TEST

Suite* s21_strlen_test0_suite() {
  Suite* s = suite_create("s21_strlen");
  TCase* tc_case = tcase_create("s21_strlen_case");
  tcase_add_test(tc_case, s21_strlen_test0);
  tcase_add_test(tc_case, s21_strlen_test1);
  tcase_add_test(tc_case, s21_strlen_test2);
  tcase_add_test(tc_case, s21_strlen_test3);
  tcase_add_test(tc_case, s21_strlen_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strlen_tests() {
  Suite* s = s21_strlen_test0_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
