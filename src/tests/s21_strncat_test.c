#include "test.h"

START_TEST(s21_strncat_test0) {
  char test1[14] = "Hello";
  char test2[14] = "Hello";
  const char* plus = ", world!";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

START_TEST(s21_strncat_test1) {
  char test1[14] = "Hello";
  char test2[14] = "Hello";
  const char* plus = ", world!";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

START_TEST(s21_strncat_test2) {
  char test1[14] = "Hello";
  char test2[14] = "Hello";
  const char* plus = "!";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

START_TEST(s21_strncat_test3) {
  char test1[14] = "\0";
  char test2[14] = "\0";
  const char* plus = ", world";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

START_TEST(s21_strncat_test4) {
  char test1[14] = "Hello";
  char test2[14] = "Hello";
  const char* plus = "/123";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

START_TEST(s21_strncat_test5) {
  char test1[14] = "Hello";
  char test2[14] = "Hello";
  const char* plus = "";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

START_TEST(s21_strncat_test6) {
  char test1[14] = "Hello";
  char test2[14] = "Hello";
  const char* plus = " ";

  ck_assert_str_eq(s21_strncat(test1, plus, 1), strncat(test2, plus, 1));
}
END_TEST

Suite* s21_strncat_test_suite() {
  Suite* s = suite_create("s21_strncat");
  TCase* tc_case = tcase_create("s21_strncat_case");
  tcase_add_test(tc_case, s21_strncat_test0);
  tcase_add_test(tc_case, s21_strncat_test1);
  tcase_add_test(tc_case, s21_strncat_test2);
  tcase_add_test(tc_case, s21_strncat_test3);
  tcase_add_test(tc_case, s21_strncat_test4);
  tcase_add_test(tc_case, s21_strncat_test5);
  tcase_add_test(tc_case, s21_strncat_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strncat_tests() {
  Suite* s = s21_strncat_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
