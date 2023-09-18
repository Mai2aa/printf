#include "main.h"
/**
 * printint - prints integer
 * @list: list of arguments
 * @pcounter: counter
 * Return: 0
 */
int printint(va_list list1, int *pcounter)
{
        unsigned int number = va_arg(list1, int);

        print_int(number, pcounter);

        return (0);
}
