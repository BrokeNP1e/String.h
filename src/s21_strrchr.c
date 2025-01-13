#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  char *temp_str = (char *)str;
  int size = (char)sizeof(str) / sizeof(str[0]);
  int i = size;
  while (i >= 0) {
    if (temp_str[i] == c && result == s21_NULL) {
      result = &temp_str[i];
    } else if (temp_str[i] == '\0') {
      result = s21_NULL;
    }
    i--;
  }

  return result;
}
