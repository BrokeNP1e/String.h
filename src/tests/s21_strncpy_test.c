#include "test.h"

START_TEST(s21_strncpy_test0) {
  char test1[7] = "No homo";
  char dest1[8] = " ";
  char dest2[8] = " ";
  char* result1 = s21_strncpy(dest1, test1, 5);
  char* result2 = strncpy(dest2, test1, 5);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncpy_test1) {
  char test1[100] = "No 345568jhjmnbn homo";
  char dest1[8] = " ";
  char dest2[8] = " ";
  char* result1 = s21_strncpy(dest1, test1, 5);
  char* result2 = strncpy(dest2, test1, 5);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncpy_test2) {
  char test1[9] = "No \0 homo";
  char dest1[8] = " ";
  char dest2[8] = " ";

  char* result1 = s21_strncpy(dest1, test1, 7);
  char* result2 = strncpy(dest2, test1, 7);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncpy_test3) {
  char test1[] = "";
  char dest1[] = " ";
  char dest2[] = " ";

  char* result1 = s21_strncpy(dest1, test1, 2);
  char* result2 = strncpy(dest2, test1, 2);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncpy_test4) {
  char test1[14] = "No homo 911  !";
  char dest1[15] = " ";
  char dest2[15] = " ";

  char* result1 = s21_strncpy(dest1, test1, 14);
  char* result2 = strncpy(dest2, test1, 14);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(s21_strncpy_test5) {
  char test1[8] = "\000 homo";
  char dest1[8] = " ";
  char dest2[8] = " ";

  char* result1 = s21_strncpy(dest1, test1, 8);
  char* result2 = strncpy(dest2, test1, 8);
  ck_assert_str_eq(result1, result2);
}
END_TEST

Suite* s21_strncpy_test_suite() {
  Suite* s = suite_create("s21_strncpy");
  TCase* tc_case = tcase_create("s21_strncpy_case");
  tcase_add_test(tc_case, s21_strncpy_test0);
  tcase_add_test(tc_case, s21_strncpy_test1);
  tcase_add_test(tc_case, s21_strncpy_test2);
  tcase_add_test(tc_case, s21_strncpy_test3);
  tcase_add_test(tc_case, s21_strncpy_test4);
  tcase_add_test(tc_case, s21_strncpy_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strncpy_tests() {
  Suite* s = s21_strncpy_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
