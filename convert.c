#include "main.h"
/**
 * convert_size_number - mesures number and fit it with size
 * @num: Number to measure
 * @size: Number
 * Return: measured size
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * is_digit - checks if the char is a digit
 * @c: Char
 * Return: 1 if c is a digit and 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
