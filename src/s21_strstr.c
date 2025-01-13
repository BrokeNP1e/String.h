#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int match = 1, max_size = s21_strlen(needle);
  char *sovpad = s21_NULL;
  while (match && *haystack) {
    int size = 0;
    while (needle[size] && needle[size] == haystack[size]) {
      size++;
    }
    if (size == max_size) {
      match = 0;
      sovpad = (char *)haystack;
    }
    haystack++;
  }
  if (match == 1) {
    sovpad = s21_NULL;
  }
  return sovpad;
}
