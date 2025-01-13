#include "test.h"

START_TEST(s21_strpbrk_test0) {
  char test1[] = "Helloworld";
  char test2[] = "Helloworld";
  const char* plus = "world";

  ck_assert_str_eq(s21_strpbrk(test1, plus), strpbrk(test2, plus));
}
END_TEST

START_TEST(s21_strpbrk_test1) {
  char test1[] = "Helloworld";
  char test2[] = "Helloworld";
  const char* plus = "llo";

  ck_assert_str_eq(s21_strpbrk(test1, plus), strpbrk(test2, plus));
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  char test1[] = "Helloworld ";
  char test2[] = "Helloworld ";
  const char* plus = " ";

  ck_assert_str_eq(s21_strpbrk(test1, plus), strpbrk(test2, plus));
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  char test1[] = "Helloworld";
  char test2[] = "Helloworld";
  const char* plus = "vo";

  ck_assert_str_eq(s21_strpbrk(test1, plus), strpbrk(test2, plus));
}
END_TEST

Suite* s21_strpbrk_test_suite() {
  Suite* s = suite_create("s21_strpbrk");
  TCase* tc_case = tcase_create("s21_strpbrk_case");
  tcase_add_test(tc_case, s21_strpbrk_test0);
  tcase_add_test(tc_case, s21_strpbrk_test1);
  tcase_add_test(tc_case, s21_strpbrk_test2);
  tcase_add_test(tc_case, s21_strpbrk_test3);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strpbrk_tests() {
  Suite* s = s21_strpbrk_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
