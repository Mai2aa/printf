#include "main.h"
void print_buffer(char buffer[], int *buff_index);
/**
 * _printf - Prints everything
 * @format: string format
 * Return: number of character been printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, counter = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			counter++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = handle_flags(format, &i);
			width = handle_width(format, &i, list);
			precision = handle_precision(format, &i, list);
			size = handle_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			counter += printed;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(list);
	return (counter);
}
/**
 * print_buffer - Prints the contents of buffer
 * @buffer: Array
 * @buff_index: Index or length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}

