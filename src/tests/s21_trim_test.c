#include "test.h"

START_TEST(s21_trim_test0) {
  char str1[] = "хhelloх";
  char trim_chars[] = "х";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "hello");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test1) {
  char str1[] = " hello ";
  char trim_chars[] = " ";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "hello");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test2) {
  char str1[] = ".hello.";
  char trim_chars[] = ".";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "hello");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test3) {
  char str1[] = "000hello000";
  char trim_chars[] = "0";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "hello");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test4) {
  char str1[] = "hello";
  char trim_chars[] = "";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "hello");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test5) {
  char str1[] = "hehhelloheh";
  char trim_chars[] = "heh";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "llo");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test6) {
  char str1[] = "kkekk";
  char trim_chars[] = "k";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "e");
  free(new_str);
}
END_TEST

START_TEST(s21_trim_test7) {
  char str1[] = " Hello, World! ";
  char trim_chars[] = " H!";
  char *new_str = s21_trim(str1, trim_chars);
  ck_assert_str_eq(new_str, "ello, World");
  free(new_str);
}
END_TEST

Suite *s21_trim_test_suite() {
  Suite *s = suite_create("s21_trim");
  TCase *tc_case = tcase_create("s21_trim_case");
  tcase_add_test(tc_case, s21_trim_test0);
  tcase_add_test(tc_case, s21_trim_test1);
  tcase_add_test(tc_case, s21_trim_test2);
  tcase_add_test(tc_case, s21_trim_test3);
  tcase_add_test(tc_case, s21_trim_test4);
  tcase_add_test(tc_case, s21_trim_test5);
  tcase_add_test(tc_case, s21_trim_test6);
  tcase_add_test(tc_case, s21_trim_test7);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_trim_tests() {
  Suite *s = s21_trim_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}