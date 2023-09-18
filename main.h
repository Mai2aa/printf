#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
/**
 * sp_char struct - struct of special character
 * @ch: symbol of character
 * @fun: pointer to fun
 */
typedef struct sp_char
{
	char ch;
	int (*fun)(va_list, int *);
} spChar;

/**
 * struct signs - struct for signs
 * @ch: symbol of sign
 * @fun: pointer to fun
 */
typedef struct signs
{
	char ch;
	void (*fun)(int, char, int, va_list, int *);
} sign;


/* task 0 */
int _putchar(char c);
int _printf(const char *format, ...);
int print_str(char *str, int len);
void print_int(unsigned int number, int *pcounter);
int string_len(char *s);
int sp_index(char ch, struct sp_char *m);
int signIndex(char ch, struct signs *m);
int printint(va_list list, int *pcounter);
int printstr(va_list list, int *pcounter);
int print_ch(va_list list, int *pcounter);
void postive_sign(int flag, char ch, int j, va_list list, int *pcounter);
void space_sign(int flag, char ch, int j, va_list list, int *pcounter);
void hash_sign(int flag, char ch, int j, va_list list, int *pcounter);
#endif
