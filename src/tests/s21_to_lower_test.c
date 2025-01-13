#include "test.h"

START_TEST(s21_to_lower_test0) {
  char str1[] = "HELLOHELLOHELLO";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "hellohellohello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test1) {
  char str1[] = "hElLO";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "hello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test2) {
  char str1[] = "HELLo";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "hello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test3) {
  char str1[] = "hELLO";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "hello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test4) {
  char str1[] = "HELLO, WORLD!";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "hello, world!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test5) {
  char str1[] = "  HELLO, WORLD!";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "  hello, world!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test6) {
  char str1[] = "";
  char *new_str = s21_to_lower(str1);
  if (new_str == NULL) {
    ck_assert_str_eq("NULL", "NULL");
  } else {
    ck_assert_str_eq(new_str, NULL);
  }
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test7) {
  char str1[] = " ";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, " ");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_lower_test8) {
  char str1[] = "...";
  char *new_str = s21_to_lower(str1);
  ck_assert_str_eq(new_str, "...");
  if (new_str != NULL) free(new_str);
}
END_TEST

Suite *s21_to_lower_test_suite() {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc_case = tcase_create("s21_to_lower_case");
  tcase_add_test(tc_case, s21_to_lower_test0);
  tcase_add_test(tc_case, s21_to_lower_test1);
  tcase_add_test(tc_case, s21_to_lower_test2);
  tcase_add_test(tc_case, s21_to_lower_test3);
  tcase_add_test(tc_case, s21_to_lower_test4);
  tcase_add_test(tc_case, s21_to_lower_test5);
  tcase_add_test(tc_case, s21_to_lower_test6);
  tcase_add_test(tc_case, s21_to_lower_test7);
  tcase_add_test(tc_case, s21_to_lower_test8);

  suite_add_tcase(s, tc_case);
  return s;
}

int s21_to_lower_tests() {
  Suite *s = s21_to_lower_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
