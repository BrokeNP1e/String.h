#include "test.h"

// c
START_TEST(s21_sprintf_test0) {
  char str[80];
  char str1[80];
  char x = 'v';
  int res = s21_sprintf(str, "%c", x);
  int res1 = sprintf(str1, "%c", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test1) {
  char str[80];
  char str1[80];
  char x = 'n';
  int res = s21_sprintf(str, "%10c", x);
  int res1 = sprintf(str1, "%10c", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char str[80];
  char str1[80];
  char x = 'n';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char str[80];
  char str1[80];
  char x = '\0';
  s21_sprintf(str, "1%c", x);
  sprintf(str1, "1%c", x);
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char str[80];
  char str1[80];
  char x = 'n';
  int res = s21_sprintf(str, "%c", x);
  int res1 = sprintf(str1, "%c", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test5) {
  char str[80];
  char str1[80];
  char x = '\n';
  int res = s21_sprintf(str, "%c", x);
  int res1 = sprintf(str1, "%c", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

// d
START_TEST(s21_sprintf_test6) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%d", a);
  int res_1_orig = sprintf(str_orig, "%d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test7) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%10d", a);
  int res_1_orig = sprintf(str_orig, "%10d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test8) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%+10d", a);
  int res_1_orig = sprintf(str_orig, "%+10d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test9) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "% d", a);
  int res_1_orig = sprintf(str_orig, "% d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test10) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "% 1d", a);
  int res_1_orig = sprintf(str_orig, "% 1d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test11) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%d", a);
  int res_1_orig = sprintf(str_orig, "%d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test12) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%-10d", a);
  int res_1_orig = sprintf(str_orig, "%-10d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test13) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%5d", a);
  int res_1_orig = sprintf(str_orig, "%5d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test14) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%.d", a);
  int res_1_orig = sprintf(str_orig, "%.d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test15) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%.3d", a);
  int res_1_orig = sprintf(str_orig, "%.3d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test16) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%3.3d", a);
  int res_1_orig = sprintf(str_orig, "%3.3d", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

// f
START_TEST(s21_sprintf_test17) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%f", b);
  int res_1_orig = sprintf(str_orig, "%f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test18) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%10f", b);
  int res_1_orig = sprintf(str_orig, "%10f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test19) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%+10f", b);
  int res_1_orig = sprintf(str_orig, "%+10f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test20) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%-10f", b);
  int res_1_orig = sprintf(str_orig, "%-10f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test21) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%.3f", b);
  int res_1_orig = sprintf(str_orig, "%.3f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test22) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%3.3f", b);
  int res_1_orig = sprintf(str_orig, "%3.3f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test23) {
  char str[80];
  char str_orig[80];

  double b = 1234523459.123211111;
  int res_1 = s21_sprintf(str, "%.3f", b);
  int res_1_orig = sprintf(str_orig, "%.3f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test24) {
  char str[80];
  char str_orig[80];

  double b = 1234523459.123211111;
  int res_1 = s21_sprintf(str, "%3.3f", b);
  int res_1_orig = sprintf(str_orig, "%3.3f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test25) {
  char str[80];
  char str_orig[80];

  double b = 1234523459.123211111;
  int res_1 = s21_sprintf(str, "%-3.6f", b);
  int res_1_orig = sprintf(str_orig, "%-3.6f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test26) {
  char str[80];
  char str_orig[80];

  double b = 1234523459.123211111;
  int res_1 = s21_sprintf(str, "% .f", b);
  int res_1_orig = sprintf(str_orig, "% .f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test27) {
  char str[80];
  char str_orig[80];

  double b = 1234523459.123211111;
  int res_1 = s21_sprintf(str, "% f", b);
  int res_1_orig = sprintf(str_orig, "% f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

// s
START_TEST(s21_sprintf_test28) {
  char str[80];
  char str1[80];
  char *x = "no homo";
  int res = s21_sprintf(str, "%s", x);
  int res1 = sprintf(str1, "%s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test29) {
  char str[80];
  char str1[80];
  char *x = "no homo";
  int res = s21_sprintf(str, "%10s", x);
  int res1 = sprintf(str1, "%10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test30) {
  char str[80];
  char str1[80];
  char *x = "no homo";
  int res = s21_sprintf(str, "%.s", x);
  int res1 = sprintf(str1, "%.s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test31) {
  char str[80];
  char str1[80];
  char *x = "no homo";
  int res = s21_sprintf(str, "%-10s", x);
  int res1 = sprintf(str1, "%-10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test32) {
  char str[80];
  char str1[80];
  char *x = "no homo";
  int res = s21_sprintf(str, "%.3s", x);
  int res1 = sprintf(str1, "%.3s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test33) {
  char str[80];
  char str1[80];
  char *x = "no homo";
  int res = s21_sprintf(str, "%3.3s", x);
  int res1 = sprintf(str1, "%3.3s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

// u
START_TEST(s21_sprintf_test34) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%u", a);
  int res_1_orig = sprintf(str_orig, "%u", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test35) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%10u", a);
  int res_1_orig = sprintf(str_orig, "%10u", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test36) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%-10u", a);
  int res_1_orig = sprintf(str_orig, "%-10u", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test37) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%.3u", a);
  int res_1_orig = sprintf(str_orig, "%.3u", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test38) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%3.3u", a);
  int res_1_orig = sprintf(str_orig, "%3.3u", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

// h
START_TEST(s21_sprintf_test39) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%hd", a);
  int res_1_orig = sprintf(str_orig, "%hd", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test40) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%5hd", a);
  int res_1_orig = sprintf(str_orig, "%5hd", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test41) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%.5hd", a);
  int res_1_orig = sprintf(str_orig, "%.5hd", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test42) {
  char str[80];
  char str_orig[80];
  int a = 2345;
  int res_1 = s21_sprintf(str, "%5.5hd", a);
  int res_1_orig = sprintf(str_orig, "%5.5hd", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test43) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%hu", a);
  int res_1_orig = sprintf(str_orig, "%hu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test44) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%4hu", a);
  int res_1_orig = sprintf(str_orig, "%4hu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test45) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%.4hu", a);
  int res_1_orig = sprintf(str_orig, "%.4hu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test46) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%4.4hu", a);
  int res_1_orig = sprintf(str_orig, "%4.4hu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

// l
START_TEST(s21_sprintf_test47) {
  char str[80];
  char str_orig[80];
  long int a = 2345;
  int res_1 = s21_sprintf(str, "%ld", a);
  int res_1_orig = sprintf(str_orig, "%ld", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test48) {
  char str[80];
  char str_orig[80];
  long int a = 2345;
  int res_1 = s21_sprintf(str, "%5ld", a);
  int res_1_orig = sprintf(str_orig, "%5ld", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test49) {
  char str[80];
  char str_orig[80];
  long int a = 2345;
  int res_1 = s21_sprintf(str, "%.5ld", a);
  int res_1_orig = sprintf(str_orig, "%.5ld", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test50) {
  char str[80];
  char str_orig[80];
  long int a = 2345;
  int res_1 = s21_sprintf(str, "%5.5ld", a);
  int res_1_orig = sprintf(str_orig, "%5.5ld", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test51) {
  char str[80];
  char str_orig[80];
  long unsigned int a = 234556789;
  int res_1 = s21_sprintf(str, "%lu", a);
  int res_1_orig = sprintf(str_orig, "%lu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test52) {
  char str[80];
  char str_orig[80];
  long unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%4lu", a);
  int res_1_orig = sprintf(str_orig, "%4lu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test53) {
  char str[80];
  char str_orig[80];
  long unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%.4lu", a);
  int res_1_orig = sprintf(str_orig, "%.4lu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test54) {
  char str[80];
  char str_orig[80];
  long unsigned int a = 2345;
  int res_1 = s21_sprintf(str, "%4.4lu", a);
  int res_1_orig = sprintf(str_orig, "%4.4lu", a);
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test55) {
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%lc", (wchar_t)'n');
  int res1 = sprintf(str1, "%lc", (wchar_t)'n');
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test56) {
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%6lc", (wchar_t)'n');
  int res1 = sprintf(str1, "%6lc", (wchar_t)'n');
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test57) {
  char str[80];
  char str1[80];
  wchar_t x[] = L"no homo";
  int res = s21_sprintf(str, "%ls", x);
  int res1 = sprintf(str1, "%ls", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test58) {
  char str[80];
  char str1[80];
  wchar_t x[] = L"no homo";
  int res = s21_sprintf(str, "%13ls", x);
  int res1 = sprintf(str1, "%13ls", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test59) {
  char str[80];
  char str1[80];

  int res = s21_sprintf(str, "%%");
  int res1 = sprintf(str1, "%%");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test60) {
  char str[80];
  char str1[80];
  long double x = -123123123123123123;
  int res = s21_sprintf(str, "%Lf", x);
  int res1 = sprintf(str1, "%Lf", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_test61) {
  char str[80];
  char str1[80];
  unsigned int x = 123123;
  int res = s21_sprintf(str, "%.10u", x);
  int res1 = sprintf(str1, "%.10u", x);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

Suite *s21_sprintf_test_suite() {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_case = tcase_create("s21_sprintf_case");
  tcase_add_test(tc_case, s21_sprintf_test0);
  tcase_add_test(tc_case, s21_sprintf_test1);
  tcase_add_test(tc_case, s21_sprintf_test2);
  tcase_add_test(tc_case, s21_sprintf_test3);
  tcase_add_test(tc_case, s21_sprintf_test4);
  tcase_add_test(tc_case, s21_sprintf_test5);
  tcase_add_test(tc_case, s21_sprintf_test6);
  tcase_add_test(tc_case, s21_sprintf_test7);
  tcase_add_test(tc_case, s21_sprintf_test8);
  tcase_add_test(tc_case, s21_sprintf_test9);
  tcase_add_test(tc_case, s21_sprintf_test10);
  tcase_add_test(tc_case, s21_sprintf_test11);
  tcase_add_test(tc_case, s21_sprintf_test12);
  tcase_add_test(tc_case, s21_sprintf_test13);
  tcase_add_test(tc_case, s21_sprintf_test14);
  tcase_add_test(tc_case, s21_sprintf_test15);
  tcase_add_test(tc_case, s21_sprintf_test16);
  tcase_add_test(tc_case, s21_sprintf_test17);
  tcase_add_test(tc_case, s21_sprintf_test18);
  tcase_add_test(tc_case, s21_sprintf_test19);
  tcase_add_test(tc_case, s21_sprintf_test20);
  tcase_add_test(tc_case, s21_sprintf_test21);
  tcase_add_test(tc_case, s21_sprintf_test22);
  tcase_add_test(tc_case, s21_sprintf_test23);
  tcase_add_test(tc_case, s21_sprintf_test24);
  tcase_add_test(tc_case, s21_sprintf_test25);
  tcase_add_test(tc_case, s21_sprintf_test26);
  tcase_add_test(tc_case, s21_sprintf_test27);
  tcase_add_test(tc_case, s21_sprintf_test28);
  tcase_add_test(tc_case, s21_sprintf_test29);
  tcase_add_test(tc_case, s21_sprintf_test30);
  tcase_add_test(tc_case, s21_sprintf_test31);
  tcase_add_test(tc_case, s21_sprintf_test32);
  tcase_add_test(tc_case, s21_sprintf_test33);
  tcase_add_test(tc_case, s21_sprintf_test34);
  tcase_add_test(tc_case, s21_sprintf_test35);
  tcase_add_test(tc_case, s21_sprintf_test36);
  tcase_add_test(tc_case, s21_sprintf_test37);
  tcase_add_test(tc_case, s21_sprintf_test38);
  tcase_add_test(tc_case, s21_sprintf_test39);
  tcase_add_test(tc_case, s21_sprintf_test40);
  tcase_add_test(tc_case, s21_sprintf_test41);
  tcase_add_test(tc_case, s21_sprintf_test42);
  tcase_add_test(tc_case, s21_sprintf_test43);
  tcase_add_test(tc_case, s21_sprintf_test44);
  tcase_add_test(tc_case, s21_sprintf_test45);
  tcase_add_test(tc_case, s21_sprintf_test46);
  tcase_add_test(tc_case, s21_sprintf_test47);
  tcase_add_test(tc_case, s21_sprintf_test48);
  tcase_add_test(tc_case, s21_sprintf_test49);
  tcase_add_test(tc_case, s21_sprintf_test50);
  tcase_add_test(tc_case, s21_sprintf_test51);
  tcase_add_test(tc_case, s21_sprintf_test52);
  tcase_add_test(tc_case, s21_sprintf_test53);
  tcase_add_test(tc_case, s21_sprintf_test54);
  tcase_add_test(tc_case, s21_sprintf_test55);
  tcase_add_test(tc_case, s21_sprintf_test56);
  tcase_add_test(tc_case, s21_sprintf_test57);
  tcase_add_test(tc_case, s21_sprintf_test58);
  tcase_add_test(tc_case, s21_sprintf_test59);
  tcase_add_test(tc_case, s21_sprintf_test60);
  tcase_add_test(tc_case, s21_sprintf_test61);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_sprintf_tests() {
  Suite *s = s21_sprintf_test_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
