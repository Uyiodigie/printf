#include <stdio.h>
#include "main.h"
#include <limits.h>

int main(void)
{
  int i = 0;
  // Prints Hello followed by a character
  int n = _printf("The String is %s and it starts with %c", "HELLO", 'H');
  // return the number of characters printed in line 9 by returning the integer n
  printf("\nn = %d\n", n);

  return (0);
}