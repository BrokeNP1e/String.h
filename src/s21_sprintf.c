#include "s21_string.h"

void int_to_str(long long value, char *str, int precision) {
  char *ptr = str, tmp_char;
  long long tmp_value;
  int count_pre = 0;
  if (value < 0) {
    value = -value;
    *ptr++ = '-';
  }
  char *ptr1 = ptr;
  while (value != 0) {
    tmp_value = value;
    value /= 10;
    *ptr++ = (tmp_value - value * 10) + '0';
    count_pre++;
  }

  while (count_pre < precision) {
    *ptr++ = '0';
    count_pre++;
  }

  *ptr-- = '\0';

  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
}

void float_to_str(long double value, char *str, int precision) {
  long long int_part = (long long)value;
  long double frac_part = value - int_part;
  int_to_str(int_part, str, 1);
  while (*str) str++;

  if (precision != 0) {
    *str++ = '.';
  }

  for (int i = 0; i < precision; i++) {
    frac_part *= 10;
    int frac_digit = (int)frac_part;
    *str++ = '0' + frac_digit;
    frac_part -= frac_digit;
  }

  *str = '\0';
}

void unsigned_int_to_str(unsigned long long value, char *str,
                         unsigned int precision) {
  char *ptr = str, tmp_char;
  unsigned int tmp_value;
  unsigned int count_pre = 0;
  char *ptr1 = ptr;
  while (value != 0) {
    tmp_value = value;
    value /= 10;
    *ptr++ = (tmp_value - value * 10) + '0';
    count_pre++;
  }

  while (count_pre < precision) {
    *ptr++ = '0';
    count_pre++;
  }

  *ptr-- = '\0';

  while (ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = tmp_char;
  }
}

void zeroing(struct options *opt) {
  opt->minus = 0;
  opt->plus = 0;
  opt->space = 0;
  opt->width = 0;
  opt->length = 0;
}

void d_func(int *precision, va_list *args, struct options *opt, char *str_ptr) {
  short int si_argument = 0;
  long int li_argument = 0;
  int i_argument = 0;
  char buffer[512];
  if (*precision == -1) {
    *precision = 1;
  }
  if (opt->length == 1) {
    si_argument = (short int)va_arg(*args, int);
    int_to_str(si_argument, buffer, *precision);

  } else if (opt->length == 2) {
    li_argument = va_arg(*args, long int);
    int_to_str(li_argument, buffer, *precision);
  } else {
    i_argument = va_arg(*args, int);
    int_to_str(i_argument, buffer, *precision);
  }
  int i = 0;
  int j = 0;
  if (opt->plus == 1 ||
      (opt->space == 1 &&
       (si_argument >= 0 && li_argument >= 0 && i_argument >= 0))) {
    j = j + 1;
  }
  for (; j < opt->width - (int)s21_strlen(buffer) && opt->minus == 0 &&
         opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  if (opt->plus == 1 &&
      (si_argument >= 0 && li_argument >= 0 && i_argument >= 0)) {
    *str_ptr++ = '+';
  } else if (opt->space == 1 &&
             (si_argument >= 0 && li_argument >= 0 && i_argument >= 0)) {
    *str_ptr++ = ' ';
  }
  while (buffer[i] != '\0') {
    *str_ptr++ = buffer[i++];
  }
  for (; j < opt->width - (int)s21_strlen(buffer) && opt->minus == 1 &&
         opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  *str_ptr = '\0';
  *precision = -1;
  zeroing(opt);
}

void f_func(int *precision, va_list *args, struct options *opt, char *str_ptr) {
  long double ld_argument = 0;
  double d_argument = 0;
  char buffer[512];
  if (*precision == -1) {
    *precision = 6;
  }
  if (opt->length == 3) {
    ld_argument = va_arg(*args, long double);
    float_to_str(ld_argument, buffer, *precision);
  } else {
    d_argument = va_arg(*args, double);
    float_to_str(d_argument, buffer, *precision);
  }
  int i = 0;
  int j = 0;
  if (opt->plus == 1 ||
      (opt->space == 1 && (d_argument >= 0 && ld_argument >= 0))) {
    j = j + 1;
  }
  for (; j < opt->width - (int)s21_strlen(buffer) && opt->minus == 0 &&
         opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  if (opt->plus == 1 && (d_argument >= 0 && ld_argument >= 0)) {
    *str_ptr++ = '+';
  } else if (opt->space == 1 && (d_argument >= 0 && ld_argument >= 0)) {
    *str_ptr++ = ' ';
  }
  while (buffer[i] != '\0') {
    *str_ptr++ = buffer[i++];
  }
  for (; j < opt->width - (int)s21_strlen(buffer) && opt->minus == 1 &&
         opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  *str_ptr = '\0';
  *precision = -1;
  zeroing(opt);
}

void s_func(int *precision, va_list *args, struct options *opt, char *str_ptr) {
  wchar_t *ls_argument;
  char *s_argument;
  int len = 0;
  if (opt->length == 2) {
    ls_argument = va_arg(*args, wchar_t *);
    while ((char)*ls_argument++ != '\0') {
      len++;
    }
    ls_argument = ls_argument - len - 1;
  } else {
    s_argument = va_arg(*args, char *);
    len = (int)s21_strlen(s_argument);
  }
  for (int j = 0; j < opt->width - len && opt->minus == 0 && opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  if (opt->length == 2) {
    while ((char)*ls_argument != '\0') {
      *str_ptr++ = (char)*ls_argument++;
    }
  } else {
    for (int i; *s_argument != '\0' && (i < *precision || *precision == -1);
         i++) {
      *str_ptr++ = *s_argument++;
    }
  }
  for (int j = 0; j < opt->width - len && opt->minus == 1 && opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  *str_ptr = '\0';
  zeroing(opt);
}

void c_func(va_list *args, struct options *opt, char *str_ptr) {
  wchar_t lc_argument;
  char c_argument;
  if (opt->length == 2) {
    lc_argument = va_arg(*args, wchar_t);
  } else {
    c_argument = va_arg(*args, int);
  }
  for (int j = 0; j < opt->width - 1 && opt->minus == 0 && opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  if (opt->length == 2) {
    *str_ptr++ = (char)lc_argument;
  } else {
    *str_ptr++ = (char)c_argument;
  }
  for (int j = 0; j < opt->width - 1 && opt->minus == 1 && opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  *str_ptr = '\0';
  zeroing(opt);
}

void u_func(int *precision, va_list *args, struct options *opt, char *str_ptr) {
  unsigned short us_argument;
  unsigned long ul_argument;
  unsigned int u_argument;
  char buffer[512];
  if (*precision == -1) {
    *precision = 1;
  }
  if (opt->length == 1) {
    us_argument = (unsigned short)va_arg(*args, unsigned int);
    unsigned_int_to_str(us_argument, buffer, *precision);
  } else if (opt->length == 2) {
    ul_argument = va_arg(*args, unsigned long);
    unsigned_int_to_str(ul_argument, buffer, *precision);
  } else {
    u_argument = va_arg(*args, unsigned int);
    unsigned_int_to_str(u_argument, buffer, *precision);
  }
  int i = 0;
  for (int j = 0; j < opt->width - (int)s21_strlen(buffer) && opt->minus == 0 &&
                  opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  while (buffer[i] != '\0') {
    *str_ptr++ = buffer[i++];
  }
  for (int j = 0; j < opt->width - (int)s21_strlen(buffer) && opt->minus == 1 &&
                  opt->width != 0;
       j++) {
    *str_ptr++ = ' ';
  }
  *str_ptr = '\0';
  *precision = -1;
  zeroing(opt);
}

void mark_opt(const char *format, struct options *opt, int *flag_check) {
  *flag_check = 1;
  switch (*format) {
    case '-':
      opt->minus = 1;
      break;
    case '+':
      opt->plus = 1;
      break;
    case ' ':
      opt->space = 1;
      break;
    case 'h':
      opt->length = 1;
      break;
    case 'l':
      opt->length = 2;
      break;
    case 'L':
      opt->length = 3;
      break;
  }
}

void specifiers(const char *format, int *precision, va_list *args,
                struct options *opt, char *str_ptr) {
  switch (*format) {
    case 'd':
      d_func(precision, args, opt, str_ptr);
      break;
    case 'f':
      f_func(precision, args, opt, str_ptr);
      break;
    case 's':
      s_func(precision, args, opt, str_ptr);
      break;
    case 'c':
      c_func(args, opt, str_ptr);
      break;
    case 'u':
      u_func(precision, args, opt, str_ptr);
      break;
  }
}

int dot_func(const char *format, int *precision, int *flag_check) {
  *flag_check = 1;
  format++;
  if (*precision == -1) {
    *precision = 0;
  }
  int n = 0;
  while (*format >= 48 && *format <= 57) {
    *precision = *precision * 10 + ((int)*format - 48);
    format++;
    n++;
  }
  return n;
}

int s21_sprintf(char *str, const char *format, ...) {
  struct options opt = {0};
  va_list args;
  va_start(args, format);
  char *str_ptr = str;
  int flag_check = 0, precision = -1;
  while (*format != '\0') {
    if (*format == '%' || flag_check == 1) {
      if (*format == '%') format++;
      flag_check = 0;
      switch (*format) {
        case '-':
        case '+':
        case ' ':
        case 'h':
        case 'l':
        case 'L':
          mark_opt(format, &opt, &flag_check);
          break;
        case 'd':
        case 'f':
        case 's':
        case 'c':
        case 'u':
          specifiers(format, &precision, &args, &opt, str_ptr);
          str_ptr = str_ptr + s21_strlen(str_ptr);
          break;
        case '.':
          format = format + dot_func(format, &precision, &flag_check);
          break;
        case '%':
          *str_ptr++ = '%';
          break;
        default:
          while (*format >= 48 && *format <= 57) {
            opt.width = opt.width * 10 + ((int)*format++ - 48);
            flag_check = 1;
          }
          format--;
      }
    } else {
      *str_ptr++ = *format;
    }
    format++;
  }
  *str_ptr = '\0';
  va_end(args);
  return str_ptr - str;
}