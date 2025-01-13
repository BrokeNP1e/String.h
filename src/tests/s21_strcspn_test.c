#include "test.h"

START_TEST(s21_strcspn_test0) {
  char test1[] = "2225222";
  char test2[] = "2225222";
  const char* plus = "5";

  ck_assert_uint_eq(s21_strcspn(test1, plus), strcspn(test2, plus));
}
END_TEST

START_TEST(s21_strcspn_test1) {
  char test1[] = "Hello, world!";
  char test2[] = "Hello, world!";
  const char* plus = "world";

  ck_assert_uint_eq(s21_strcspn(test1, plus), strcspn(test2, plus));
}
END_TEST

START_TEST(s21_strcspn_test2) {
  char test1[] = "Hello";
  char test2[] = "Hello";
  const char* plus = "";

  ck_assert_uint_eq(s21_strcspn(test1, plus), strcspn(test2, plus));
}
END_TEST

START_TEST(s21_strcspn_test3) {
  char test1[] = "Hello";
  char test2[] = "Hello";
  const char* plus = " ";

  ck_assert_uint_eq(s21_strcspn(test1, plus), strcspn(test2, plus));
}
END_TEST

START_TEST(s21_strcspn_test4) {
  char test1[] = "Hello";
  char test2[] = "Hello";
  const char* plus = "H";

  ck_assert_uint_eq(s21_strcspn(test1, plus), strcspn(test2, plus));
}
END_TEST

START_TEST(s21_strcspn_test5) {
  char test1[] = "Hello";
  char test2[] = "Hello";
  const char* plus = "vo";

  ck_assert_uint_eq(s21_strcspn(test1, plus), strcspn(test2, plus));
}
END_TEST

Suite* s21_strcspn_test_suite() {
  Suite* s = suite_create("s21_strcspn");
  TCase* tc_case = tcase_create("s21_strcspn_case");
  tcase_add_test(tc_case, s21_strcspn_test0);
  tcase_add_test(tc_case, s21_strcspn_test1);
  tcase_add_test(tc_case, s21_strcspn_test2);
  tcase_add_test(tc_case, s21_strcspn_test3);
  tcase_add_test(tc_case, s21_strcspn_test4);
  tcase_add_test(tc_case, s21_strcspn_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strcspn_tests() {
  Suite* s = s21_strcspn_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}