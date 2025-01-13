#include "s21_string.h"

void skip_whitespace(const char **str) {
  while (isspace(**str)) {
    (*str)++;
  }
}

int read_integer(const char **str, int *value, int width) {
  char buffer[32];
  int i = 0;
  bool is_negative = false;

  if (width <= 0 || (size_t)width > sizeof(buffer) - 1) {
    width = sizeof(buffer) - 1;
  }

  skip_whitespace(str);

  if (**str == '-') {
    is_negative = true;
    (*str)++;
    if (width > 0) {
      width--;
    }
  } else if (**str == '+') {
    (*str)++;
    if (width > 0) {
      width--;
    }
  }

  while (isdigit(**str) && (width == 0 || i < width)) {
    buffer[i++] = *(*str)++;
  }
  buffer[i] = '\0';

  if (i == 0) {
    return 0;  // Nothing was read
  }

  *value = atoi(buffer);
  if (is_negative) {
    *value = -(*value);
  }

  return i;
}

int read_unsigned(const char **str, unsigned int *value, int width) {
  char buffer[32];
  int i = 0;

  if (width <= 0 || (size_t)width > sizeof(buffer) - 1) {
    width = sizeof(buffer) - 1;
  }

  skip_whitespace(str);

  if (**str == '+' || **str == '-') {
    buffer[i++] = *(*str)++;
    if (width > 0) {
      width--;
    }
  }

  while (isdigit(**str) && (width == 0 || i < width)) {
    buffer[i++] = *(*str)++;
  }
  buffer[i] = '\0';

  if (i == 0 || (i == 1 && (buffer[0] == '+' || buffer[0] == '-'))) {
    return 0;  // Nothing was read or only sign was read
  }

  *value = strtoul(buffer, NULL, 10);

  return i;
}

int read_string(const char **str, char *value, int width) {
  int len = 0;
  while (**str && !isspace(**str) && (width == 0 || len < width)) {
    *value++ = **str;
    (*str)++;
    len++;
  }
  *value = '\0';
  return len;
}

int read_float(const char **str, float *value, int width) {
  char buffer[64];
  int i = 0;

  if (width <= 0 || (size_t)width > sizeof(buffer) - 1) {
    width = sizeof(buffer) - 1;
  }

  if (**str == '-' || **str == '+') {
    buffer[i++] = *(*str)++;
    if (width > 0) {
      width--;
    }
  }

  while ((isdigit(**str) || **str == '.') && (width == 0 || i < width)) {
    buffer[i++] = *(*str)++;
  }
  buffer[i] = '\0';

  if (i == 0) {
    return 0;  // Nothing was read
  }

  *value = strtof(buffer, NULL);

  return i;
}

int read_hex(const char **str, unsigned int *value, int width) {
  char buffer[32];
  int i = 0;

  if (width <= 0 || (size_t)width > sizeof(buffer) - 1) {
    width = sizeof(buffer) - 1;
  }

  skip_whitespace(str);

  while (isxdigit(**str) && (width == 0 || i < width)) {
    buffer[i++] = *(*str)++;
  }
  buffer[i] = '\0';

  if (i == 0) {
    return 0;  // Nothing was read
  }

  *value = strtoul(buffer, NULL, 16);

  return i;
}

int read_pointer(const char **str, void **value) {
  skip_whitespace(str);
  int length = sscanf(*str, "%p", value);
  if (length > 0) {
    while (**str && (isxdigit(**str) || **str == 'x' || **str == 'X')) {
      (*str)++;
    }
  }
  return length;
}

int parse_format(const char **format, FormatSpecifier *specifier) {
  if (**format == '%') {
    (*format)++;
    if (**format == '*') {
      specifier->suppress = true;
      (*format)++;
    }
    if (isdigit(**format)) {
      specifier->width = 0;
      while (isdigit(**format)) {
        specifier->width = specifier->width * 10 + (**format - '0');
        (*format)++;
      }
    }
    switch (**format) {
      case 'c':
        specifier->type = SPEC_CHAR;
        break;
      case 'd':
        specifier->type = SPEC_DECIMAL;
        break;
      case 'i':
        specifier->type = SPEC_INTEGER;
        break;
      case 'f':
        specifier->type = SPEC_FLOAT;
        break;
      case 'o':
        specifier->type = SPEC_OCTAL;
        break;
      case 's':
        specifier->type = SPEC_STRING;
        break;
      case 'u':
        specifier->type = SPEC_UNSIGNED;
        break;
      case 'x':
        specifier->type = SPEC_HEX;
        break;
      case 'p':
        specifier->type = SPEC_POINTER;
        break;
      case 'n':
        specifier->type = SPEC_COUNT;
        break;
      case '%':
        specifier->type = SPEC_PERCENT;
        break;
      default:
        return -1;
    }
    (*format)++;
    return 0;
  }
  return -1;
}

int read_octal(const char **str, void *value, int width, char length) {
  char buffer[32];
  int i = 0;

  if (width <= 0 || (size_t)width > sizeof(buffer) - 1) {
    width = sizeof(buffer) - 1;
  }

  skip_whitespace(str);

  while (**str >= '0' && **str <= '7' && (width == 0 || i < width)) {
    buffer[i++] = *(*str)++;
  }
  buffer[i] = '\0';

  if (i == 0) {
    return 0;  // Nothing was read
  }

  if (length == 'h') {
    *(unsigned short *)value = (unsigned short)strtoul(buffer, NULL, 8);
  } else if (length == 'l') {
    *(unsigned long *)value = strtoul(buffer, NULL, 8);
  } else {
    *(unsigned int *)value = (unsigned int)strtoul(buffer, NULL, 8);
  }

  return i;
}

int read_char(const char **str, char *value) {
  if (**str) {
    *value = *(*str)++;
    return 1;
  }
  return 0;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int count = 0;

  while (*format) {
    if (isspace(*format)) {
      skip_whitespace(&format);
      skip_whitespace(&str);
    } else if (*format == '%') {
      FormatSpecifier specifier = {0};
      if (parse_format(&format, &specifier) != 0) {
        break;  // Error in format
      }
      if (specifier.type == SPEC_PERCENT) {
        if (*str == '%') {
          str++;
        } else {
          break;  // Mismatch for '%'
        }
      } else if (specifier.type == SPEC_DECIMAL ||
                 specifier.type == SPEC_INTEGER) {
        int value;
        skip_whitespace(&str);  // Skip whitespace before number
        int length = read_integer(&str, &value, specifier.width);
        if (length > 0) {
          if (specifier.suppress == false) {
            int *arg = va_arg(args, int *);
            *arg = value;
            count++;
          }
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_UNSIGNED) {
        unsigned int value;
        skip_whitespace(&str);  // Skip whitespace before number
        int length = read_unsigned(&str, &value, specifier.width);
        if (length > 0) {
          if (specifier.suppress == false) {
            unsigned int *arg = va_arg(args, unsigned int *);
            *arg = value;
            count++;
          }
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_STRING) {
        char *value = va_arg(args, char *);
        skip_whitespace(&str);  // Skip whitespace before string
        int length = read_string(&str, value, specifier.width);
        if (length > 0) {
          count++;
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_CHAR) {
        char value;
        int length = read_char(&str, &value);
        if (length > 0) {
          if (specifier.suppress == false) {
            char *arg = va_arg(args, char *);
            *arg = value;
            count++;
          }
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_FLOAT) {
        float value;
        skip_whitespace(&str);  // Skip whitespace before number
        int length = read_float(&str, &value, specifier.width);
        if (length > 0) {
          if (specifier.suppress == false) {
            float *arg = va_arg(args, float *);
            *arg = value;
            count++;
          }
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_HEX) {
        unsigned int value;
        skip_whitespace(&str);  // Skip whitespace before number
        int length = read_hex(&str, &value, specifier.width);
        if (length > 0) {
          if (specifier.suppress == false) {
            unsigned int *arg = va_arg(args, unsigned int *);
            *arg = value;
            count++;
          }
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_POINTER) {
        void *value;
        skip_whitespace(&str);  // Skip whitespace before number
        int length = read_pointer(&str, &value);
        if (length > 0) {
          if (specifier.suppress == false) {
            void **arg = va_arg(args, void **);
            *arg = value;
            count++;
          }
        } else {
          break;  // Reading error
        }
      } else if (specifier.type == SPEC_COUNT) {
        if (specifier.suppress == false) {
          int *arg = va_arg(args, int *);
          *arg = count;
        }
      } else if (specifier.type == SPEC_OCTAL) {
        skip_whitespace(&str);  // Skip whitespace before number
        void *arg;
        if (specifier.length == 'h') {
          arg = va_arg(args, unsigned short *);
        } else if (specifier.length == 'l') {
          arg = va_arg(args, unsigned long *);
        } else {
          arg = va_arg(args, unsigned int *);
        }
        int length = read_octal(&str, arg, specifier.width, specifier.length);
        if (length > 0) {
          if (specifier.suppress == false) {
            count++;
          }
        } else {
          break;  // Reading error
        }
      }
    } else {
      if (*str == *format) {
        str++;
        format++;
      } else {
        break;  // Mismatch in characters
      }
    }
  }

  va_end(args);
  return count;
}
