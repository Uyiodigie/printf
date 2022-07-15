#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int  _printf(const char *format, ...)
{
  int count, i = 0;

  va_list data;
  va_start(data, format);

  for (i = 0; format[i] != '%' && format[i] != '\0')
  {
    // count the number of characters
    count = count + _putchar(format[i]);
    // print the screen the character counted
  }

  return (count);
}