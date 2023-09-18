#include "main.h"
/**
 * call_print - function that get the function and call it back
 * @i: index
 * @format: string
 * @m: struct
 * @pcounter: counter
 * @list: arguments
 */
void call_print(const char *format, int *i, struct sp_char *m,
int *pcounter, va_list list1)
{
	int j, k = 0;
	va_list list;
	int index = *i;
	int flags = 0;
	sign flag[] = {
		{'+', postive_sign}, {' ', space_sign}, {'#', hash_sign}, {'\0', NULL}
			};
	va_copy(list, list1);
	while (signIndex(format[index], flag) != -1)
	{
		for (k = 0; flag[k].ch != '\0'; k++)
		{
			if (format[index] == flag[k].ch)
			{
				if (format[index] == '+' && flags < 2)
					flags = 1;
				else if (format[index] == '#')
					flags = 2;
				index++;
				break;
			}
		}
	}
	j = sp_index(format[index], m);
	if (j != -1)
	{
		if (flag[k].ch != '\0')
			flag[k].fun(flags, flag[k].ch, j, list, pcounter);
		m[j].fun(list1, pcounter);
		*i = index;
	}
	else
	{
		_putchar('%');
		(*i)--;
		*pcounter++;
		return;
	}
}
/**
 * _printf - an alternative function for standard printf
 * @format: character to be printed
 * @...: variadic argument
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, counter = 0;
	va_list list1;
	int *pcounter = &counter;

	spChar type[] = {
		{'s', printstr}, {'c', print_ch}, {'d', printint},
		{'i', printint}};
	if (format == NULL || (format[0] =='%' && format[1] == '\0'))
		return (-1);

	va_start(list1, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		 	*pcounter++;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			call_print(format, &i, type, pcounter, list1);
		}
		 else if (format[i] == '%' && format[i + 1] == '%')
                {
                        i++;
                        _putchar(format[i]);
			*pcounter++;
                }
		
	}
	return (counter);
	va_end(list1);
}
