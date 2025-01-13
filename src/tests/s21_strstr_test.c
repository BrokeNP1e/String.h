#include "test.h"

START_TEST(s21_strstr_test0) {
  char test1[] = "<<<5>>>";
  char test2[] = "5";

  ck_assert_ptr_eq(s21_strstr(test1, test2), strstr(test1, test2));
}
END_TEST

START_TEST(s21_strstr_test1) {
  char test3[] = "HelloHelloHello";
  char test4[] = "Hello";

  ck_assert_ptr_eq(s21_strstr(test3, test4), strstr(test3, test4));
}
END_TEST

START_TEST(s21_strstr_test2) {
  char test4[] = "Hello";
  char test5[] = "";
  ck_assert_ptr_eq(s21_strstr(test4, test5), strstr(test4, test5));
}
END_TEST

START_TEST(s21_strstr_test3) {
  char test1[] = "Hello";
  char test2[] = "Hello";
  const char* plus = " ";

  ck_assert_ptr_eq(s21_strstr(test1, plus), strstr(test2, plus));
}
END_TEST

START_TEST(s21_strstr_test4) {
  char test1[] = "12345Hello6789";
  char test2[] = "12345Hello6789";
  const char* plus = "123456789";

  ck_assert_ptr_eq(s21_strstr(test1, plus), strstr(test2, plus));
}
END_TEST

////START_TEST(s21_strstr_test5) {
////    char test1[]= "12345Hello6789";
////    char test2[]= "12345Hello6789";
////    const char* plus = "a";
////
////    ck_assert_ptr_eq(s21_strstr(test1, plus), strstr(test2, plus));
////}
////END_TEST

Suite* s21_strstr_test_suite() {
  Suite* s = suite_create("s21_strstr");
  TCase* tc_case = tcase_create("s21_strstr_case");
  tcase_add_test(tc_case, s21_strstr_test0);
  tcase_add_test(tc_case, s21_strstr_test1);
  tcase_add_test(tc_case, s21_strstr_test2);
  tcase_add_test(tc_case, s21_strstr_test3);
  tcase_add_test(tc_case, s21_strstr_test4);

  suite_add_tcase(s, tc_case);

  return s;
}
int s21_strstr_tests() {
  Suite* s = s21_strstr_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
