#include "main.h"

int print_string(char *string)
{
  int i, count = 0;
  for (i = 0; string[i] != '\0'; i++)
    count += _putchar(string[i]);
  return (count);
}