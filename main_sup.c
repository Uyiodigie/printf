#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Hello %s\n New Me", "World");
	_printf("Hello %s\n", "World");
	_printf("String 1 length: %b", len);
	_printf("Stirng Length %b", len2);
	return (0);
}
