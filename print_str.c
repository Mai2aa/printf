#include "main.h"
/**
 * print_str - prints a string
 * @str: string to be printed
 * @len: length of string
 * Return: -1 if theres an Error
 */
int print_str(char *str, int len)
{
	return (write(1, str, len));
}
