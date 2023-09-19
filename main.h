#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
/* define macros */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1

/**
 * fmt struct - struct 
 * @ch: character
 * @fn: pointer to fun
 */
struct fmt
{
	char form;
	int (*fn)(va_list, char[], int, int, int, int);
};
typedef struct fmt fmt_t;



/* task 0 */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);
int print_ch(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_per(va_list types, char buffer[], int flags, int width, int precision, int size);
int handle_ch(char c, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
long int convert_size_number(long int num, int size);
int is_digit(char);
/* task 7, 11, 12 */
int handle_flags(const char *format, int *i);
/* task 9 */
int handle_width(const char *format, int *i, va_list list);
/* task 10 */
int handle_precision(const char *format, int *i, va_list list);
int handle_size(const char *format, int *i);

#endif
