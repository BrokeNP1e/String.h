#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_src = s21_NULL;
  start_index = start_index - 1;
  if (src != s21_NULL && start_index < s21_strlen(src) + 2) {
    new_src = malloc(s21_strlen(src) + s21_strlen(str) + 1);
    s21_size_t i = 0;
    s21_size_t j = 0;
    for (; i < s21_strlen(src) + s21_strlen(str); i++) {
      int count = 0;
      while (i >= start_index && i < start_index + s21_strlen(str) &&
             str[count] != '\0') {
        new_src[i] = str[count];
        count++;
        i++;
      }
      if (i >= start_index + s21_strlen(str) || i <= start_index) {
        new_src[i] = src[j];
        j++;
      }
    }
    new_src[i + 1] = '\0';
  }
  return new_src;
}
