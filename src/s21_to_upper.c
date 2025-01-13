#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *temp_str = s21_NULL;
  s21_size_t i = 0;
  while (str != s21_NULL && (char)str[i] != '\0') {
    if ((char)str[i] >= 97 && (char)str[i] <= 122) {
      temp_str = realloc(temp_str, i + 1);
      temp_str[i] = str[i] - 32;
    } else {
      temp_str = realloc(temp_str, i + 1);
      temp_str[i] = str[i];
    }
    i++;
  }
  if (str != s21_NULL && temp_str != s21_NULL) {
    temp_str = realloc(temp_str, i + 1);
    temp_str[i] = 0;
  }
  return temp_str;
}
