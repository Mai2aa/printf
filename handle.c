#include "main.h"
/**
 * handle_print - Print arguments as there forms
 * @fmt: Format
 * @list: List of arguments
 * @index: index
 * @buffer: array
 * @flags: flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: 1 , 2
 */
int handle_print(const char *fmt, int *index, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, len = 0, counter = -1;
	fmt_t fmt_list1[] = {
		{'c', print_ch}, {'s', print_str}, {'%', print_per},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'p', print_pointer}, {'r', print_reverse}, {'R', print_rot13string},
		{'\0', NULL}
	};
	for (i = 0; fmt_list1[i].form != '\0'; i++)
		if (fmt[*index] == fmt_list1[i].form)
			return (fmt_list1[i].fn(list, buffer, flags, width, precision, size));
	if (fmt_list1[i].form == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &fmt[*index], 1);
		return (len);
	}
	return (counter);
}
/**
 * handle_ch - Print string
 * @c: char
 * @buffer: array
 * @flags:  flags
 * @width: width
 * @precision: precision
 * @size: Size
 * Return: Number of characters
 */
int handle_ch(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @index: char
 * @buffer: array
 * @flags:  flags
 * @width: width
 * @precision: precision
 * @size: Size
 * Return: Number of chaaracters got printed
 */
int write_number(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size)
{
	int longi = BUFF_SIZE - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(index, buffer, flags, width, precision,
				longi, padd, extra_ch));
}
/**
 * write_num - Write the number in thee bufffer
 * @index: Index
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @longi: length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of characters
 */
int write_num(int index, char buffer[],
		int flags, int width, int prec,
		int longi, char padd, char extra_c)
{
	int i, start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (prec > 0 && prec < longi)
		padd = ' ';
	while (prec > longi)
		buffer[--index] = '0', longi++;
	if (extra_c != 0)
		longi++;
	if (width > longi)
	{
		for (i = 1; i < width - longi + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], longi) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], longi));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--start] = extra_c;
			return (write(1, &buffer[start], i - start) +
					write(1, &buffer[index], longi - (1 - start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], longi));
}
/**
 * write_pointer - Write address
 * @buffer: Arrays
 * @index: Index
 * @longi: Length
 * @width: Width
 * @flags: Flags
 * @padd: Char
 * @extra_c: Char representing extra char
 * @start: Index at which padding should start
 * Return: Number of chars.
 */
int write_pointer(char buffer[], int index, int longi,
		int width, int flags, char padd, char extra_c, int start)
{
	int i;

	if (width > longi)
	{
		for (i = 3; i < width - longi + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], longi) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], longi));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[start], i - start) +
					write(1, &buffer[index], longi - (1 - start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

