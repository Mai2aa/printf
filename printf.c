#include "main.h"
/**
 * _printf - an alternative function for standard printf
 * @format: character to be printed
 * @...: variadic argument
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
		 write(1, format, 1);
		 counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
	                 write(1, format, 1);
			 counter++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list, int);
				write(1, &num, 1);
				counter++;
			}
			  else if (*format == 'c')
                        {
                                char c = va_arg(list, int);
                        write(1, &c, 1);
			counter++;
                        }
			    else if (*format == 's')
                        {
                                char *str = va_arg(list, char*);
				int str_len = 0;
				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				counter += str_len;
                        }
		}
	

			format++;
	}
	return (counter);
va_end(list);
}
