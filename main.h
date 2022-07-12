#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

int _printf(const char* format,...);
char *convert(unsigned int num, int base);
char *convertHex(unsigned int num, int base);

/**
 * _printf - produces output according to a format.
 * @format: format string
 * Return: length of formatted output string
 */
int _printf(const char* format,...)
{
char *traverse;
int i = 0;
char *s = NULL;

va_list arg;
va_start(arg, format);

for(traverse = (char *)format ; *traverse != '\0'; traverse++)
{
while( *traverse != '%' )
{
putchar(*traverse);
traverse++;
}

traverse++;
switch(*traverse)
{
case 'c' : i = va_arg(arg,int);
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

case 's': s = va_arg(arg,char *);
puts(s);
return (strlen(s) - 1);

case 'x': i = va_arg(arg,unsigned int);
puts(convertHex(i,16));
break;

case 'X': i = va_arg(arg,unsigned int);
puts(convert(i,16));
break;
}
}

free(arg);
free(traverse);
free(s);
va_end(arg);
return(i);
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

#endif
