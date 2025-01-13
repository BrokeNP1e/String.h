#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int flag = 0;
  unsigned char *temp_str1 = (unsigned char *)str1;
  unsigned char *temp_str2 = (unsigned char *)str2;
  while (flag == 0 && n-- > 0) {
    if (*temp_str1 != *temp_str2) {
      flag = *temp_str1 - *temp_str2;
    }
    ++temp_str1;
    ++temp_str2;
  }
  return flag;
}
