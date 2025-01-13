#include "test.h"

START_TEST(s21_strtok_test0) {
  char test1[] = "No homo";
  char test2[] = "No homo";
  char delim1[] = "o";
  char delim2[] = "o";
  char *my_strtok = s21_strtok(test1, delim1);
  char *origin_strtok = strtok(test2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strtok_test1) {
  char test1[] = "No \0homo";
  char test2[] = "No \0homo";
  char delim1[] = "o";
  char delim2[] = "o";
  char *my_strtok = s21_strtok(test1, delim1);
  char *origin_strtok = strtok(test2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strtok_test2) {
  char test1[] = "No \000homo";
  char test2[] = "No \000homo";
  char delim1[] = "o";
  char delim2[] = "o";
  char *my_strtok = s21_strtok(test1, delim1);
  char *origin_strtok = strtok(test2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strtok_test3) {
  char test1[] = "No homo";
  char test2[] = "No homo";
  char delim1[] = "g";
  char delim2[] = "g";
  char *my_strtok = s21_strtok(test1, delim1);
  char *origin_strtok = strtok(test2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strtok_test4) {
  char test1[] = "No homo9()";
  char test2[] = "No homo9()";
  char delim1[] = "9o";
  char delim2[] = "9o";
  char *my_strtok = s21_strtok(test1, delim1);
  char *origin_strtok = strtok(test2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strtok_test5) {
  char test1[] = "No homo 911";
  char test2[] = "No homo 911";
  char delim1[] = "d";
  char delim2[] = "d";
  char *my_strtok = s21_strtok(test1, delim1);
  char *origin_strtok = strtok(test2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

Suite *s21_strtok_test_suite() {
  Suite *s = suite_create("s21_strtok");
  TCase *tc_case = tcase_create("s21_strtok_case");
  tcase_add_test(tc_case, s21_strtok_test0);
  tcase_add_test(tc_case, s21_strtok_test1);
  tcase_add_test(tc_case, s21_strtok_test2);
  tcase_add_test(tc_case, s21_strtok_test3);
  tcase_add_test(tc_case, s21_strtok_test4);
  tcase_add_test(tc_case, s21_strtok_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strtok_tests() {
  Suite *s = s21_strtok_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
