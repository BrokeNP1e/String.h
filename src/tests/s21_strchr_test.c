#include "test.h"

START_TEST(s21_strchr_test0) {
  char test1[] = "No homo";
  char test2 = 'h';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

START_TEST(s21_strchr_test1) {
  char test1[] = "No \0 homo";
  char test2 = 'h';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

START_TEST(s21_strchr_test2) {
  char test1[] = "N0 \n homo";
  char test2 = 'h';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

START_TEST(s21_strchr_test3) {
  char test1[] = "No homo";
  char test2 = 'b';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

START_TEST(s21_strchr_test4) {
  char test1[] = "\0";
  char test2 = 'f';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

START_TEST(s21_strchr_test5) {
  char test1[] = "No homo";
  char test2 = '\0';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

START_TEST(s21_strchr_test6) {
  char test1[] = "1234567890";
  char test2 = '0';

  ck_assert_ptr_eq(s21_strchr(test1, test2), strchr(test1, test2));
}
END_TEST

Suite* s21_strchr_test_suite() {
  Suite* s = suite_create("s21_strchr");
  TCase* tc_case = tcase_create("s21_strchr_case");
  tcase_add_test(tc_case, s21_strchr_test0);
  tcase_add_test(tc_case, s21_strchr_test1);
  tcase_add_test(tc_case, s21_strchr_test2);
  tcase_add_test(tc_case, s21_strchr_test3);
  tcase_add_test(tc_case, s21_strchr_test4);
  tcase_add_test(tc_case, s21_strchr_test5);
  tcase_add_test(tc_case, s21_strchr_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strchr_tests() {
  Suite* s = s21_strchr_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
