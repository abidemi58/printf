#ifndef our_printf
#define our_printf
#include <stdio.h>
#include <stdarg.h>
/**
 * struct specifier - struct specifier
 * @valid: the valid character.
 * @f: the functions associated.
 *
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hexa_lower(va_list args);
int print_hexa_upper(va_list args);
int print_unsigned(va_list args);
int print_str_unprintable(va_list args);
int print_str_reverse(va_list args);
int print_ptr(va_list args);
int print_rot13(va_list args);
int print_percent(va_list args __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _puts(char *str, int ascii);
int _nbr_len(int prmNumber);
int _strlen_recursion(char *s);
int convert_alpha_numeric(int nb, int upper);
char *convert_rot13(char *str);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
char *convert_base_pointer(unsigned long p);
int _putchar(char c);
int print_percent(va_list args);
int (*get_func(char x))(va_list args);
#endif
