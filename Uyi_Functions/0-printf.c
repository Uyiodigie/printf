//#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char* format,...);
char *convert(unsigned int num, int base);
char *convertHex(unsigned int num, int base);

/**
 * @brief 
 * 
 */
 * @format: format string
 * Return: length of formatted output string
 */
int _printf(const char* format,...)
{
	char *traverse;
	unsigned int i;
	char *s;

	//Module 1: Initializing Myprintf's arguments
	va_list arg;
	va_start(arg, format);

	for(traverse = format; *traverse != '\0'; traverse++)
	{
		while( *traverse != '%' )
		{
			putchar(*traverse);
			traverse++;
		}

		traverse++;

		//Module 2: Fetching and executing arguments
		switch(*traverse)
		{
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						putchar(i);
						return (1);

			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						if(i<0)
						{
							i = -i;
							putchar('-');
						}
						puts(convert(i,10));
						break;

			case 'u' : i = va_arg(arg, unsigned int);
						puts(convert(i, 10));
						//free(i);  // freeing the buffer s
						break;

			case 'b' : i = va_arg(arg, unsigned int);
						puts(convert(i, 2));
						break;

			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
						puts(convert(i,8));
						break;

			case 's': s = va_arg(arg,char *); 		//Fetch string
						//puts(s);
						write(1, s, strlen(s));  //writing with the write keyword
						//free(s); // freeing the buffer s
						return (strlen(s) - 1);

			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						puts(convertHex(i,16));
						break;

			case 'X': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						puts(convert(i,16));
						break;
		}
	}

	//Module 3: Closing argument list to necessary clean-up
	free(arg);
	free(traverse);
	//free(i);
	free(s);
	va_end(arg);
}

/**
 * convert - coverts from int to base when using %x
 * @num: number to convert
 * @base: base of the number
 * Return: length of formatted output string
 */
char *convert(unsigned int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}

/**
 * convertHex - coverts from int to hex when using %x
 * @num: number to convert
 * @base: base of the number
 * Return: length of formatted output string
 */
char *convertHex(unsigned int num, int base)
{
	static char Representation[]= "0123456789abcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}
