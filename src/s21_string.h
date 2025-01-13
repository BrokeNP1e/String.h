#ifndef C2_S21_STRINGPLUS_1_ALDUINHU_H
#define C2_S21_STRINGPLUS_1_ALDUINHU_H

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define s21_NULL ((void *)0)
#define s21_size_t unsigned long

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);

typedef enum {
  SPEC_CHAR,      // %c
  SPEC_DECIMAL,   // %d
  SPEC_INTEGER,   // %i
  SPEC_FLOAT,     // %e, %E, %f, %g, %G
  SPEC_OCTAL,     // %o
  SPEC_STRING,    // %s
  SPEC_UNSIGNED,  // %u
  SPEC_HEX,       // %x, %X
  SPEC_POINTER,   // %p
  SPEC_COUNT,     // %n
  SPEC_PERCENT    // %%
} FormatSpecifierType;

typedef struct {
  FormatSpecifierType type;  // Тип спецификатора
  bool suppress;  // Подавление присваивания (*)
  int width;      // Ширина поля
  int length;
} FormatSpecifier;

void skip_whitespace(const char **str);
int read_integer(const char **str, int *value, int width);
int parse_format(const char **format, FormatSpecifier *specifier);
int read_string(const char **str, char *value, int width);
int s21_sscanf(const char *str, const char *format, ...);

struct options {
  int minus;
  int plus;
  int space;
  int width;
  int length;
};
#endif  // C2_S21_STRINGPLUS_1_ALDUINHU_H
