#include "test.h"

START_TEST(s21_memcpy_test0) {
  char test1[] = "123456";
  char test2[10] = "4";

  ck_assert_str_eq(s21_memcpy(test1, test2, 6), memcpy(test1, test2, 6));
}
END_TEST

START_TEST(s21_memcpy_test1) {
  char test1[] = "123456";
  char test2[10] = " ";

  ck_assert_str_eq(s21_memcpy(test1, test2, 6), memcpy(test1, test2, 6));
}
END_TEST

START_TEST(s21_memcpy_test2) {
  char test1[] = "123456";
  char test2[10] = "";

  ck_assert_str_eq(s21_memcpy(test1, test2, 6), memcpy(test1, test2, 6));
}
END_TEST

START_TEST(s21_memcpy_test3) {
  char test1[] = "321";
  char test2[10] = "123456";

  ck_assert_str_eq(s21_memcpy(test1, test2, 3), memcpy(test1, test2, 3));
}
END_TEST

START_TEST(s21_memcpy_test4) {
  char test1[] = "";
  char test2[10] = "52";

  ck_assert_str_eq(s21_memcpy(test1, test2, 1), memcpy(test1, test2, 1));
}
END_TEST

START_TEST(s21_memcpy_test5) {
  char test1[] = " ";
  char test2[10] = "52";

  ck_assert_str_eq(s21_memcpy(test1, test2, 1), memcpy(test1, test2, 1));
}
END_TEST

Suite* s21_memcpy_test_suite() {
  Suite* s = suite_create("s21_memcpy");
  TCase* tc_case = tcase_create("s21_memcpy_case");
  tcase_add_test(tc_case, s21_memcpy_test0);
  tcase_add_test(tc_case, s21_memcpy_test1);
  tcase_add_test(tc_case, s21_memcpy_test2);
  tcase_add_test(tc_case, s21_memcpy_test3);
  tcase_add_test(tc_case, s21_memcpy_test4);
  tcase_add_test(tc_case, s21_memcpy_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memcpy_tests() {
  Suite* s = s21_memcpy_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}