#include "test.h"

START_TEST(s21_memset_test0) {
  unsigned char test1[10] = "1234357890";
  //        unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));
}
END_TEST

START_TEST(s21_memset_test1) {
  unsigned char test1[10] = "1234357890";
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '3', 10),
                    (unsigned long)memchr(test1, '3', 10));
}
END_TEST

START_TEST(s21_memset_test2) {
  unsigned char test1[10] = "1234357890";
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '/', 8),
                    (unsigned long)memchr(test1, '/', 8));
}
END_TEST

START_TEST(s21_memset_test3) {
  unsigned char test1[10] = "1234357890";
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
}
END_TEST

START_TEST(s21_memset_test4) {
  unsigned char test1[10] = "1234357890";

  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '0', 4),
                    (unsigned long)memchr(test1, '0', 4));
}
END_TEST

START_TEST(s21_memset_test5) {
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '1', 3),
                    (unsigned long)memchr(test2, '1', 3));
}
END_TEST

Suite* s21_memset_test_suite() {
  Suite* s = suite_create("s21_memset");
  TCase* tc_case = tcase_create("s21_memset_case");
  tcase_add_test(tc_case, s21_memset_test0);
  tcase_add_test(tc_case, s21_memset_test1);
  tcase_add_test(tc_case, s21_memset_test2);
  tcase_add_test(tc_case, s21_memset_test3);
  tcase_add_test(tc_case, s21_memset_test4);
  tcase_add_test(tc_case, s21_memset_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memset_tests() {
  Suite* s = s21_memset_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}