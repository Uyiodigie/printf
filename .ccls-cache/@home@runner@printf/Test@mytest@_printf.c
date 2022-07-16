#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - custom made printf function
 * @format: number of characters of the string
 * Return: success
 */
int _printf(const char *format, ...) {
  int count = 0, i = 0, j = 0;
  unsigned int p;
  va_list data;
  va_start(data, format);

  for (i = 0; format[i] != '\0';) {
    if (format[i] != '%') {
      count += _putchar(format[i]);
      i++;
    } else if (format[i] == '%' && format[i + 1] != ' ') {
      switch (format[i + 1]) {
      case 'c':
        count += _putchar(va_arg(data, int));
        break;
        
      case 's':
        count += print_string(va_arg(data, char *));
        break;
        
      case '%':
        count += _putchar('%');
        break;
        
      case 'd':
        j = va_arg(data, int);
        if (j < 0) {
          j = -j;
          _putchar('-');
        }
        _printf(convert(j, 10));
        break;
        
      case 'u':
        p = va_arg(data, unsigned int);
        _printf(convert(i, 10));
        break;

      case 'b':
        p = va_arg(data, unsigned int);
        _printf(convert(i, 2));
        break;

      case 'o':
        p = va_arg(data, unsigned int);
        _printf(convert(i, 8));
        break;
        
      default:
        break;
      }
      i += 2;
    }
  }
  va_end(data);
  return (count);
}

char *convert(unsigned int num, int base) {
  static char Representation[] = "0123456789ABCDEF";
  static char buffer[50];
  char *ptr;

  ptr = &buffer[49];
  *ptr = '\0';

  do {
    *--ptr = Representation[num % base];
    num /= base;
  } while (num != 0);

  return (ptr);
}