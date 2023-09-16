#include <unistd.h>
/**
 * _putchar - function that prints char
 * @c: character to be printed
 * Return: 1 and -1 if an error happened
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
