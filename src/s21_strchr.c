#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  int i = 0;
  char *result = s21_NULL;
  char *temp_str = (char *)str;
  while (temp_str[i] != '\0') {
    if (temp_str[i] == c) {
      result = &temp_str[i];
    }
    i++;
  }
  if ((char)c == '\0') {
    result = &temp_str[i];
  }
  return result;
}
