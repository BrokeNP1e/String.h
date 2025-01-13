#include "test.h"

START_TEST(s21_strerror_test0) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
}
END_TEST

START_TEST(s21_strerror_test1) {
  ck_assert_str_eq(s21_strerror(12), strerror(12));
}
END_TEST

START_TEST(s21_strerror_test2) {
  ck_assert_str_eq(s21_strerror(123456), strerror(123456));
}
END_TEST

START_TEST(s21_strerror_test3) {
  ck_assert_str_eq(s21_strerror(-27), strerror(-27));
}
END_TEST

START_TEST(s21_strerror_test4) {
  ck_assert_str_eq(s21_strerror(34), strerror(34));
}
END_TEST

Suite* s21_strerror_test_suite() {
  Suite* s = suite_create("s21_strerror");
  TCase* tc_case = tcase_create("s21_strrror_case");
  tcase_add_test(tc_case, s21_strerror_test0);
  tcase_add_test(tc_case, s21_strerror_test1);
  tcase_add_test(tc_case, s21_strerror_test2);
  tcase_add_test(tc_case, s21_strerror_test3);
  tcase_add_test(tc_case, s21_strerror_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strerror_tests() {
  Suite* s = s21_strerror_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
