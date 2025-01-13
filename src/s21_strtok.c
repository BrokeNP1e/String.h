#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;
  char *result = s21_NULL;

  if (str != s21_NULL) {
    next_token = str;
  }
  if (next_token != s21_NULL) {
    char *start = next_token;
    while (*start != '\0' && s21_strchr(delim, *start) != s21_NULL) {
      start++;
    }
    if (*start != '\0') {
      char *end = start;
      while (*end != '\0' && s21_strchr(delim, *end) == s21_NULL) {
        end++;
      }
      if (*end == '\0') {
        next_token = s21_NULL;
      } else {
        *end = '\0';
        next_token = end + 1;
      }
      result = start;
    } else {
      next_token = s21_NULL;
    }
  }
  return result;
}