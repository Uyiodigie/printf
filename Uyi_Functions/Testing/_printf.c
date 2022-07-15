#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...) {
  int count = 0, i;
  int temp_count = 0;
  int j = 0;
  char *s;

  va_list data;
  va_start(data, format);

  for (i = 0; format[i] != '\0'; i++) {
    // count the number of characters
    // print the screen the character counted
    if (format[i] != '%') {
      // count += _putchar(format[i]);
      temp_count += _putchar(format[i]);
    } else if (format[i] == '%' && format[i + 1] == 'c') {
      i += 1;
      j = va_arg(data, int);
      _putchar(j);
      temp_count += 1;
    } else if (format[i] == '%' && format[i + 1] == 's') {
      i += 1;
      s = va_arg(data, char *);
      write(1, s, strlen(s));
      temp_count += strlen((char *)s);
    }
  }
  count += temp_count;
  va_end(data);
  return (count);
}