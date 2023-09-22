#include "main.h"
/**
 *_printf - The Printf function
 *_putchar - Prints function
 *@format: Program format
 *Return: printed chars
 */
int _printf(const char *format, ...)
{
va_list list;
if(format == NULL)
return (-1);
va_start(list, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c': {
int arg = va_arg(list, int);
_putchar(arg);
break;
}
case '%': {
_putchar ('%');
break;
}
case 's': {
char str = va_arg(list, int);
_putchar(str);
break;
}
default:
putchar(*format);
}
}
	else
{
putchar(*format);
}
format++;
}
va_end(list);
}
