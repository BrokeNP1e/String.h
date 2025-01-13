#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_src = s21_NULL;
  int start = -1;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    int end_check = 0;
    while (end_check != 2) {
      start++;
      end_check = 0;
      for (int j = 0; trim_chars[j] != '\0' && end_check == 0; ++j) {
        if (src[start] == trim_chars[j]) {
          end_check = 1;
        } else if (trim_chars[j + 1] == '\0') {
          end_check = 2;
        }
      }
      if (end_check == 0) {
        end_check = 2;
      }
    }
    end_check = 0;
    int end = s21_strlen(src);
    while (end_check != 2) {
      end--;
      end_check = 0;
      for (int j = 0; trim_chars[j] != '\0' && end_check == 0; ++j) {
        if (src[end] == trim_chars[j]) {
          end_check = 1;
        } else if (trim_chars[j + 1] == '\0') {
          end_check = 2;
        }
      }
      if (end_check == 0) {
        end_check = 2;
      }
    }
    int count = 0;
    new_src = malloc(end - start + 1);
    for (int i = start; i <= end; ++i) {
      new_src[count] = src[i];
      count++;
    }
    new_src[count] = '\0';
  }
  return new_src;
}
