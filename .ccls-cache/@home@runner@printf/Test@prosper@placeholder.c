
#include "main.h"

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}



#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/**
 * _printf - produces output according to a format.
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
						
			case 'd' : i = va_arg(arg,int);
						if(i<0) 
						{ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break;

			case 'u' : i = va_arg(arg, unsigned int);
						puts(convert(i, 10));
						break;

			case 'b' : i = va_arg(arg, unsigned int);
						puts(convert(i, 2));
						break;

			case 'o': i = va_arg(arg,unsigned int);
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