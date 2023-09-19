#include "main.h"
/**
 * print_ch - Print a character
 * @list1: List a of arguments
 * @buffer:  array
 * @flags:  flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters to be printed
 */
int print_ch(va_list list1, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(list1, int);

	return (handle_ch(c, buffer, flags, width, precision, size));
}
/**
 * print_str - Print a string
 * @list1: List a of arguments
 * @buffer: array
 * @flags: flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_str(va_list list1, char buffer[],
		int flags, int width, int precision, int size)
{
	int longi = 0, i;
	char *str = va_arg(list1, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[longi] != '\0')
		longi++;
	if (precision >= 0 && precision < longi)
		longi = precision;
	if (width > longi)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], longi);
			for (i = width - longi; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - longi; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], longi);
			return (width);
		}
	}
	return (write(1, str, longi));
}
/**
 * print_per - Print a percent
 * @list1: List of arguments
 * @buffer: array
 * @flags:  flags
 * @width: width.
 * @precision: Precision
 * @size: Size specifier
 * Return: characters to be printed
 */
int print_per(va_list list1, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(list1);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print integer
 * @list1: List of arguments
 * @buffer: array
 * @flags: flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: integers to be printed
 */
int print_int(va_list list1, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(list1, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

