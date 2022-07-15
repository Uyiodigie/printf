#include <unistd.h>
// _putchar - function returns character to stdout
int _putchar(char c)
{
  int num = write(1, &c, 1);
  return 1;
}