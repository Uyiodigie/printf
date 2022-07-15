#include <unistd.h>

/**
 * _putchar - prints a character to stdout
 * @c: character parameter
 * Return: output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
