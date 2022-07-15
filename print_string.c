#include "main.h"

/**
 * print_string - prints string to stdout
 * @string: string parameter
 * Return: count
 */
int print_string(char *string)
{
	int i, count = 0;

	for (i = 0; string[i] != '\0'; i++)
		count += _putchar(string[i]);
	return (count);
}
