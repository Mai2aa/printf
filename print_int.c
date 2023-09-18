#include "main.h"
/**
 * print_int - a finction that prints an integer
 * @number: the number to be printed
 * @pcounter: number of integers printed
 */
void print_int(unsigned int number, int *pcounter)
{
	if ((int)number < 0)
	{
		_putchar('-');
		*pcounter++;
		number *= -1;
	}
	if (number / 10)
		print_int(number / 10, pcounter);
	_putchar(number % 10 + '0');
	*pcounter++;
}
