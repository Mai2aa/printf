#include "main.h"
/**
 * print_pointer - Print a pointer variable
 * @list1: List a of arguments
 * @buffer: array
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars
 */
int print_pointer(va_list list1, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int index = BUFF_SIZE - 2, longi = 2, start = 1;
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(list1, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[index--] = map_to[num_addrs % 15];
num_addrs /= 16;
longi++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', longi++;
else if (flags & F_SPACE)
extra_c = ' ', longi++;
index++;

return (write_pointer(buffer, index, longi,
width, flags, padd, extra_c, start));
}
