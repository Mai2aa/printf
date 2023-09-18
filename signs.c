#include "main.h"
/**
 * postive_sign - fun print the + flag
 * @flag: flag
 * @ch: the + char
 * @list: the argument list
 * @pcounter: counter
 */
void postive_sign(int flag, char ch, int j, va_list list, int *pcounter)
{
	if (flag < 2 || (j == 2 || j == 3 || j == 12))
	{
		if (ch == '+' && (j == 2 || j == 3 || j == 12))
		{
			if (va_arg(list, int) >= 0 || j == 12)
			{
				_putchar('+');
				*pcounter++;
			}
		}
	}
	else
	{
		hash_sign(flag, '#', j, list, pcounter);
	}
}
/**
 * space_sign - fun print the space 
 * @flag: flag
 * @ch: the space
 * @list: list of arguments
 * @pcounter: counter
 */
void space_sign(int flag, char ch, int j, va_list list, int *pcounter)
{
	if ((ch == ' ' && (j == 2 || j == 3 || j == 12)) && flag == 0)
	{
		if (va_arg(list, int) >= 0 || j == 12)
		{
			_putchar(' ');
			*pcounter++;
		}
	}
	else if (flag <= 2 && (j == 2 || j == 3 || j == 12))
	{
		_putchar('+');
		*pcounter++;
	}
	else if (flag <= 2 && !(j == 2 || j == 3 || j == 12))
	{
		hash_sign(flag, '#', j, list, pcounter);
	}
}
/**
 * hash_sign - fun print hash
 * @flag: flag
 * @ch: the hash
 * @list: list of arguments
 * @pcounter: counter
 */
void hash_sign(int flag, char ch, int j, va_list list, int *pcounter)
{
	if (va_arg(list, int) != 0)
	{
		if (flag > 1 && !(j == 2 || j == 3 || j == 12))
		{
			if (ch == '#' && j == 7)
			{
				_putchar('0');
				*pcounter++;
			}
			else if (ch == '#' && j == 9)
			{
				_putchar('0');
				_putchar('x');
				*pcounter += 2;
			}
			else if (ch == '#' && j == 10)
			{
				_putchar('0');
				_putchar('X');
				*pcounter += 2;
			}
		}
		else if (flag < 2 && (j == 2 || j == 3 || j == 12))
		{
			_putchar('+');
			*pcounter++;
		}
	}
}
