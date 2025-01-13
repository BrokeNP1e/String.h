#include "test.h"

START_TEST(s21_to_upper_test0) {
  char str1[] = "hellohellohello";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, "HELLOHELLOHELLO");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test1) {
  char str1[] = "prIVet";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, "PRIVET");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test2) {
  char str1[] = "MOMMy";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, "MOMMY");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test3) {
  char str1[] = "hello, world!";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, "HELLO, WORLD!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test4) {
  char str1[] = "  hello, world!";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, "  HELLO, WORLD!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test5) {
  char str1[] = "";
  char *new_str = s21_to_upper(str1);
  if (new_str == NULL) {
    ck_assert_str_eq("NULL", "NULL");
  } else {
    ck_assert_str_eq(new_str, NULL);
  }
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test6) {
  char str1[] = " ";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, " ");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_to_upper_test7) {
  char str1[] = "...";
  char *new_str = s21_to_upper(str1);
  ck_assert_str_eq(new_str, "...");
  if (new_str != NULL) free(new_str);
}
END_TEST

Suite *s21_to_upper_test_suite() {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc_case = tcase_create("s21_to_upper_case");
  tcase_add_test(tc_case, s21_to_upper_test0);
  tcase_add_test(tc_case, s21_to_upper_test1);
  tcase_add_test(tc_case, s21_to_upper_test2);
  tcase_add_test(tc_case, s21_to_upper_test3);
  tcase_add_test(tc_case, s21_to_upper_test4);
  tcase_add_test(tc_case, s21_to_upper_test5);
  tcase_add_test(tc_case, s21_to_upper_test6);
  tcase_add_test(tc_case, s21_to_upper_test7);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_to_upper_tests() {
  Suite *s = s21_to_upper_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
