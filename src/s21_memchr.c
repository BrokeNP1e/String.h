#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *flag = s21_NULL;
  for (unsigned char *i = (unsigned char *)str; n-- > 0 && flag == s21_NULL;
       ++i) {
    if ((unsigned char)c == *i) {
      flag = i;
    }
  }
  return flag;
}
