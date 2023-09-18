#include "main.h"
/**
 * string_len - get the length of the string
 * @s: the string
 * @length: the counter
 * Return: number of characters in a string
 */
int string_len(char *s)
{
	int length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

