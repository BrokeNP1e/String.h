#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p1;
  const char *p2;
  s21_size_t count = s21_strlen(str1);
  int flag = 0;
  for (p1 = str1; flag != 1 && *p1 != '\0'; p1++) {
    for (p2 = str2; *p2 != '\0'; p2++) {
      if (*p1 == *p2) {
        count = p1 - str1;
        flag = 1;
      }
    }
  }

  return count;
}
