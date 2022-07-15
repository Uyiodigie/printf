#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
  int count = 0, i;

  for (i = 0; format[i] != '\0'; i++)
  {
    if (format[i] != '%')
    {
      count += _putchar(format[i]);
      i++;
    }
    else if (format[i] == '%' && format[i + 1] != ' ')
    {
      i += 2;
    }
  }
}

