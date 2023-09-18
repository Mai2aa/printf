#include "main.h"
/**
 * print_ch - prints characater
 * @list: list of arguments
 * @pcounter: counter
 * Return: 1 if success -1 if error
 */
int print_ch(va_list list1, int *pcounter)
{
        if (_putchar((unsigned char)va_arg(list1, int)) != -1)
                *pcounter++;
        else
                return (-1);
        return (1);
}

