#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *temp_dest = (unsigned char *)dest;
  const unsigned char *temp_src = (const unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    temp_dest[i] = temp_src[i];
  }
  return temp_dest;
}
