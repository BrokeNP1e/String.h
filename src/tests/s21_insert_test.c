#include "test.h"

START_TEST(s21_insert_test0) {
  char *src = "I dont";
  char *str = " Understand";
  char *new_str = s21_insert(src, str, 7);
  ck_assert_str_eq(new_str, "I dont Understand");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test1) {
  char *src = "Hello, world!";
  char *str = " Beautiful";
  char *new_str = s21_insert(src, str, 7);
  ck_assert_str_eq(new_str, "Hello, Beautiful world!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test2) {
  char *src = "Hello, world!";
  char *str = "";
  char *new_str = s21_insert(src, str, 7);
  ck_assert_str_eq(new_str, "Hello, world!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test3) {
  char *src = "Hello,world!";
  char *str = " ";
  char *new_str = s21_insert(src, str, 7);
  ck_assert_str_eq(new_str, "Hello, world!");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test4) {
  char *src = "hellohello";
  char *str = "Hello";
  char *new_str = s21_insert(src, str, 6);
  ck_assert_str_eq(new_str, "helloHellohello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test5) {
  char *src = "hellohello";
  char *str = "Hello";
  char *new_str = s21_insert(src, str, 1);
  ck_assert_str_eq(new_str, "Hellohellohello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test6) {
  char *src = "hellohello";
  char *str = "Hello";
  char *new_str = s21_insert(src, str, 11);
  ck_assert_str_eq(new_str, "hellohelloHello");
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test7) {
  char *src = "hellohello";
  char *str = "Hello";
  char *new_str = s21_insert(src, str, 15);
  if (new_str == NULL) {
    ck_assert_str_eq("NULL", "NULL");
  } else {
    ck_assert_str_eq(new_str, NULL);
  }
  if (new_str != NULL) free(new_str);
}
END_TEST

START_TEST(s21_insert_test8) {
  char *src = "";
  char *str = "Hello";
  char *new_str = s21_insert(src, str, 19);
  if (new_str == NULL) {
    ck_assert_str_eq("NULL", "NULL");
  } else {
    ck_assert_str_eq(new_str, NULL);
  }
  if (new_str != NULL) free(new_str);
}
END_TEST

Suite *s21_insert_test_suite() {
  Suite *s = suite_create("s21_insert");
  TCase *tc_case = tcase_create("s21_insert_case");
  tcase_add_test(tc_case, s21_insert_test0);
  tcase_add_test(tc_case, s21_insert_test1);
  tcase_add_test(tc_case, s21_insert_test2);
  tcase_add_test(tc_case, s21_insert_test3);
  tcase_add_test(tc_case, s21_insert_test4);
  tcase_add_test(tc_case, s21_insert_test5);
  tcase_add_test(tc_case, s21_insert_test6);
  tcase_add_test(tc_case, s21_insert_test7);
  tcase_add_test(tc_case, s21_insert_test8);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_insert_tests() {
  Suite *s = s21_insert_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
