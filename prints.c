#include "main.h"
/**
 * printint - prints integer
 * @list: list of arguments
 * @pcounter: counter
 * Return: 0
 */
int printint(va_list list, int *pcounter)
{
	unsigned int number = va_arg(list, int);

	print_int(number, pcounter);

	return (0);
}
/**
 * printstr - prints string
 * @list: list of arguments
 * @pcounter: counter
 * Return: 1 if success -1 if error
 */
int printstr(va_list list, int *pcounter)
{
	char *str;
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	if (print_str(str, string_len(str)) != -1)
		*pcounter += string_len(str);
	else
		return (-1);
	return (1);
}
/**
 * print_ch - prints characater
 * @list: list of arguments
 * @pcounter: counter
 * Return: 1 if success -1 if error
 */
int print_ch(va_list list, int *pcounter)
{
	if (_putchar((unsigned char)va_arg(list, int)) != -1)
		*pcounter++;
	else
		return (-1);
	return (1);
}
