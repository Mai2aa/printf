#include "main.h"
/**
 * @sp_index - the index of special character
 * @ch: char we want its index
 * @m: array of struct
 * Return: index
 */
int sp_index(char ch, struct sp_char *m)
{
	int i;
	for (i = 0; (m + i )->ch != '\0'; i++)
	{
		if (ch == (m + i)->ch)
			return (i);
	}
	return (-1);
}
/**
 * signIndex - the index of flag
 * @ch: char we want its index
 * @m: array of struct
 * Return: index
 */
int signIndex(char ch, struct signs *m)
{
	int i;
	for (i = 0; (m + i)->ch != '\0'; i++)
	{
		if (ch == (m + i)->ch)
			return (i);
	}
	return (-1);
}
