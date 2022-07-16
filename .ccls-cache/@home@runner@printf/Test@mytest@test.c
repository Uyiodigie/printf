#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
  int n = _printf("%c, %s, %%", 'H', "Heros are born in may");
  _printf("%d %d\n", 257+234, -234);
  _printf("Binary: %b\nOctal: %o\nUnsigned int: %u\n", 20, 321, 12301032);
  _printf("\nn = %d \n", n);
  return (0);
}