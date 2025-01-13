#include "test.h"

int main() {
  int result = 0;

  result += s21_memchr_tests();
  result += s21_memcmp_tests();
  result += s21_memcpy_tests();
  result += s21_memset_tests();
  result += s21_strncat_tests();
  result += s21_strchr_tests();
  result += s21_strncmp_tests();
  result += s21_strncpy_tests();
  result += s21_strcspn_tests();
  result += s21_strerror_tests();
  result += s21_strlen_tests();
  result += s21_strpbrk_tests();
  result += s21_strrchr_tests();
  result += s21_strstr_tests();
  result += s21_strtok_tests();
  result += s21_to_upper_tests();
  result += s21_to_lower_tests();
  result += s21_insert_tests();
  result += s21_trim_tests();
  result += s21_sprintf_tests();
  result += s21_sscanf_tests();

  return (result == 0) ? 0 : 0;
}
